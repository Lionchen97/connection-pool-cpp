#pragma once
#include <string>
#include "Connection.h"
#include <queue>
#include <mutex>
#include <atomic>
#include<memory>
#include<functional>
#include<thread>
#include<condition_variable>
#include <iostream>
using namespace std;
/*
实现连接池功能模块
*/
// 线程安全的懒汉式单例模式
class ConnectionPool
{

private:
    // 单例#1 构造函数私有化
    ConnectionPool();
    // 从mysql配置文件中加载配置项
    bool loadConfigFile();
    //  运行在独立的线程中，专门负责生产新connection
    void produceConnectionTask();
    //  扫描超过maxIdleTime时间的空闲连接，进行空闲的connection回收
    void scannerConnectionTask();
    ConnectionPool(const ConnectionPool &cp) = delete;
    ConnectionPool &operator=(const ConnectionPool &cp) = delete;
    string _ip;         // MySQL Server的ip地址
    unsigned int _port; // MySQL的端口号
    string _username;
    string _password;
    string _dbname;
    int _initSize;                      // 连接池的初始连接量
    int _maxSize;                       // 连接池的最大连接量
    int _maxIdleTime;                   // 连接池的最大空闲时间。
    int _connectionTimeout;             // 连接池获取连接的超时时间
    atomic_int _connectionCnt;          // 线程安全的记录所创建的connection总数量
    queue<Connection *> _connectionQue; // 存储可用connection的连接队列
    mutex _queueMutex;                  // 维护连接队列的线程安全互斥锁
    condition_variable cv;              // 设置条件变量，用于连接生产者线程和连接消费者线程的线程间通信
public:
    // 单例#2 获取连接池对象实例
    static ConnectionPool *getConnectionPool();
    /* 给外部提供接口，从连接池中获取一个可用的空闲连接，避免用户的手动归还。
       用智能指针管理，只要重写删除器就能实现用完连接归还到可以连接，而不是用默认的析构去释放连接。
       由于智能指针析构时，会把connection资源delete掉，相当于调用connection的析构函数，connection就被close了。
    */
    shared_ptr<Connection> getConnection(); 
};