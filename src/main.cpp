#include <iostream>
#include "Connection.h"
#include "CommonConnectionPool.h"
using namespace std;

int main()
{
    // Connection conn;
    // char sql[1024] = {0};
    // sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
    // conn.connect("localhost", 3306, "lion", "Csj19971012!", "lion_db");
    // conn.update(sql);
    // return 0;
    clock_t begin = clock();
    ConnectionPool *pool = ConnectionPool::getConnectionPool();
    for (int i = 0; i < 1000; ++i)
    {
#if 0
        // 不使用连接池
        Connection conn;
        char sql[1024] = {0};
        sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
        conn.connect("localhost", 3306, "lion", "Csj19971012!", "lion_db");
        conn.update(sql);
#endif
#if 1
        // 使用连接池
        shared_ptr<Connection> sp = pool->getConnection();
        char sql[1024] = {0};
        sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
        sp->update(sql);
#endif
        
    }
    clock_t end = clock();
    cout << (end - begin) << "ms" << endl;
}