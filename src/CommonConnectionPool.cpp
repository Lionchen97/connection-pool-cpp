#include "pch.h"
#include "CommonConnectionPool.h"
#include "public.h"

using namespace std;
// 线程安全的懒汉单例函数接口
ConnectionPool *ConnectionPool::getConnectionPool()
{
    /*
    单例#3  定义一个唯一的类的实例对象
    编译器层面的线程安全，函数静态局部变量的初始化，在汇编指令上已经自动添加线程互斥指令了
    */
    static ConnectionPool pool;
    return &pool;
}
// 从mysql配置文件中加载配置项
bool ConnectionPool::loadConfigFile()
{

    using FFP = FILE *(*)(const char *, const char *);
    FFP Fp = fopen;
#ifdef _WIN32
    // FILE *fp = fopen('./mysql.cnf',"r")
    FILE *fp = Fp("./mysql.ini", "r");
    if (fp == nullptr)
    {

        LOG("mysql.ini file is not exist !");
        return false;
    }
#endif
#ifdef __linux__
    FILE *fp = Fp("./mysql.cnf", "r");
    if (fp == nullptr)
    {

        LOG("mysql.ini file is not exist !");
        return false;
    }
#endif
    while (!feof(fp))
    {
        // 逐行读取数据
        char line[1024] = {0};
        fgets(line, 1024, fp);
        string str = line;
        if (str[0] == '#')
        {
            // LOG(str.substr(1, str.length() - 2));
        }
        else
        {
            int idx = str.find('=', 0);

            // username = lion\n
            int endidx = str.find('\n', 0);

            // 拼接字符串username
            string key = str.substr(0, idx); // 参数1:开始下标 参数2：字符个数
            // 拼接字符串lion
            string value = str.substr(idx + 1, endidx - idx - 1);
            if (key == "ip")
            {
                _ip = value;
            }
            else if (key == "port")
            {
                _port = atoi(value.c_str()); // C标准库中的一个函数，用于将字符串转换为整数
            }
            else if (key == "username")
            {
                _username = value;
            }
            else if (key == "password")
            {
                _password = value;
            }
            else if (key == "dbname")
            {
                _dbname = value;
            }
            else if (key == "initSize")
            {
                _initSize = atoi(value.c_str());
            }
            else if (key == "maxSize")
            {
                _maxSize = atoi(value.c_str());
            }
            else if (key == "maxIdleTime")
            {
                _maxIdleTime = atoi(value.c_str());
            }
            else
            {
                _connectionTimeout = atoi(value.c_str());
            }
        }
    }
    return true;
}
// 连接池的构造
ConnectionPool::ConnectionPool()
{
    // 加载配置项
    if (!loadConfigFile())
    {
        return;
    }

    // 创建初始数量的连接
    for (int i = 0; i < _initSize; ++i)
    {
        Connection *p = new Connection();
        p->connect(_ip, _port, _username, _password, _dbname);
        p->refrshAliveTime(); // 刷新开始空闲的时间
        _connectionQue.push(p);
        _connectionCnt++; // 创建的连接数量+1
    }
    // 启动生产者线程与空闲扫描线程

    // 启动一个新线程，作为生产者线程。线程函数调用普通成员方法调用时依赖对象。
    thread produce(std::bind(&ConnectionPool::produceConnectionTask, this));
    // 分离守护线程，当主线程结束，子线程自动结束。
    produce.detach();
    // 启动一个新的定时线程，扫描超过maxIdleTime时间的空闲连接，进行空闲的connection回收
    thread scanner(std::bind(&ConnectionPool::produceConnectionTask, this));
    // 分离守护线程，当主线程结束，子线程自动结束。
    scanner.detach();
}
// 生产连接的线程函数，由于是成员方法，可以轻松使用成员变量
void ConnectionPool::produceConnectionTask()
{
    for (;;)
    {
        unique_lock<mutex> lock(_queueMutex); //  源码explicit unique_lock(mutex_type& __m)
        while (!_connectionQue.empty())
        {
            // 队列不空，生产者线程进入等待状态。
            cv.wait(lock);
        }
        // 连接数量没有达到上线，继续创建新的连接
        if (_connectionCnt < _maxSize)
        {
            Connection *p = new Connection();
            p->connect(_ip, _port, _username, _password, _dbname);
              p->refrshAliveTime(); // 刷新开始空闲的时间
            _connectionQue.push(p);
            _connectionCnt++; // 创建的连接数量+1
        }
        // 通知消费者线程，可以消费连接
        cv.notify_all();
    }
}

//
void ConnectionPool::scannerConnectionTask()
{
    for(;;)
    {
        // 通过sleep模拟定时效果
        this_thread::sleep_for(chrono::seconds(_maxIdleTime));
        // 扫描整个队列，释放多余的connection
        unique_lock<mutex> lock(_queueMutex);
        // 当总connection数大于初始connection数，才需要释放connection
        while(_connectionCnt>_initSize) 
        {
            Connection *conn = _connectionQue.front();
            if(conn->getAliveTime()>=(_maxIdleTime*1000)){
                _connectionQue.pop();
                _connectionCnt--;
                delete conn; // 释放连接，调用connection的析构
            }
            else{
                break; // 队头的connection没有超过_maxIdelTime,其他connection也不会超过。
            }
        }
    }

}
// 消费者线程
shared_ptr<Connection> ConnectionPool::getConnection()
{
    unique_lock<mutex> lock(_queueMutex);
    while (_connectionQue.empty())
    {
        // 最多等待_connectionTimeout毫秒的时间，直到生产者线程的唤醒。 源码  enum class cv_status { no_timeout, timeout };
        // 判断是否真的为超时。由于线程竞争，其他的线程可能先被唤醒取走了connection导致连接队列为空，当前线程并不是真的超时，所以再给它一次机会让它在while中生存一下。
        if (cv_status::timeout==cv.wait_for(lock, chrono::milliseconds(_connectionTimeout)))
        {
            // 如果消费者线程唤醒之后连接队列依旧为空
            if (_connectionQue.empty())
            {
                LOG("获取空闲连接超时了...获取连接失败");
                return nullptr;
            }
        }
    }
    // 取出连接队列的首元素连接，并自定义删除器实现连接的归还
    shared_ptr<Connection> conn(_connectionQue.front(),
                                [&](Connection *pconn)
                                {
                                    // 服务器应用线程中调用的，所以一定要考虑队列的线程安全
                                    unique_lock<mutex> lock(_queueMutex);
                                      pconn->refrshAliveTime(); // 刷新开始空闲的时间
                                    _connectionQue.push(pconn);
                                });
    _connectionQue.pop();
    // 谁消费了队列中的最后一个connection，谁负责通知生产者线程可以生产连接
    if (_connectionQue.empty())
    {
        cv.notify_all();
    }

    return conn;
}