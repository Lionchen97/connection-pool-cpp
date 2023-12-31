#pragma once
#include <string>
#include <mysql/mysql.h>
#include <ctime>
using namespace std;

/*
实现MySQL数据库的操作
*/
class Connection
{
public:
  // 初始化数据库连接
  Connection();
  // 释放数据库连接资源
  ~Connection();
  // 连接数据库
  bool connect(string ip, unsigned short port, string username, string password, string dbname);
  // 更新操作 insert、delete、update
  bool update(string sql);
  // 查询操作 select
  MYSQL_RES *query(string sql);
  // 刷新一下连接的起始的空闲时间点
  void refrshAliveTime();
  // 返回存活时间
  clock_t getAliveTime()const;
private:
 // 表示和MySQL Server的一条connection
  MYSQL *_conn;
  //记录进入空闲状态后的起始存活时间
  clock_t _alivetime;
};
