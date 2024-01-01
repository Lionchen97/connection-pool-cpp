#include <iostream>
#include "Connection.h"
#include "CommonConnectionPool.h"
#include "public.h"
#define USE_CONNECTIONPOOL false // 启用多线程
#define ENABLE_MULTITHREADING false // 启用多线程
using namespace std;

int main()
{
    clock_t begin = clock();

#if USE_CONNECTIONPOOL
    ConnectionPool *pool = ConnectionPool::getConnectionPool();
    if (pool != nullptr)
    {
        LOG("启用连接池");
    }
    else
    {
        LOG("启用连接池失败");
        return 0;
    }

#if ENABLE_MULTITHREADING
    LOG("开启多线程")
    // 使用连接池（多线程）
    thread t1([&]()
        {
            for(int i=0;i<250;i++)
            {
                shared_ptr<Connection> sp = pool->getConnection();
                char sql[1024] = {0};
                sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
                sp->update(sql);
            } 
        });
    thread t2([&]()
        {
            for(int i=0;i<250;i++)
            {
                shared_ptr<Connection> sp = pool->getConnection();
                char sql[1024] = {0};
                sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
                sp->update(sql);
            } 
        });
    thread t3([&]()
        {
            for(int i=0;i<250;i++)
            {
                shared_ptr<Connection> sp = pool->getConnection();
                char sql[1024] = {0};
                sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
                sp->update(sql);
            } 
        });
    thread t4([&]()
        {
            for(int i=0;i<250;i++)
            {
                shared_ptr<Connection> sp = pool->getConnection();
                char sql[1024] = {0};
                sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
                sp->update(sql);
            } 
        });
    t1.join();
    t2.join();
    t3.join();
    t4.join();
#else
    LOG("未启用多线程");
    for (int i = 0; i < 1000; ++i)
    {

        // 使用连接池（单线程）

        char sql[1024] = {0};
        sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
        sp->update(sql);
    }
#endif

#else
    LOG("未启用连接池");
#if ENABLE_MULTITHREADING
    LOG("开启多线程");
    // 不使用连接池（多线程）
    thread t1([&]()
        {
            for(int i=0;i<250;i++)
            {
                Connection conn;
                char sql[1024] = {0};
                sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
                conn.connect("localhost", 3306, "lion", "Csj19971012!", "lion_db");
                conn.update(sql);
            } 
        });
    thread t2([&]()
        {
            for(int i=0;i<250;i++)
            {
                Connection conn;
                char sql[1024] = {0};
                sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
                conn.connect("localhost", 3306, "lion", "Csj19971012!", "lion_db");
                conn.update(sql);
            } 
        });
    thread t3([&]()
        {
            for(int i=0;i<250;i++)
            {
                Connection conn;
                char sql[1024] = {0};
                sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
                conn.connect("localhost", 3306, "lion", "Csj19971012!", "lion_db");
                conn.update(sql);
            } 
        });
    thread t4([&]()
        {
            for(int i=0;i<250;i++)
            {
                Connection conn;
                char sql[1024] = {0};
                sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
                conn.connect("localhost", 3306, "lion", "Csj19971012!", "lion_db");
                conn.update(sql);
            } 
        });
    t1.join();
    t2.join();
    t3.join();
    t4.join();
#else
    LOG("未启用多线程");
    for (int i = 0; i < 1000; ++i)
    {
        // 不使用连接池（单线程）
        Connection conn;
        char sql[1024] = {0};
        sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
        conn.connect("localhost", 3306, "lion", "Csj19971012!", "lion_db");
        conn.update(sql);
    }
#endif
#endif
    clock_t end = clock();
    LOG("耗时:" + to_string(end - begin) + "ms");
}