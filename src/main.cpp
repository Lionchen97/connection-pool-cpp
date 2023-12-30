#include <iostream>
#include "Connection.h"
using namespace std;

int main()
{
    Connection conn;
    char sql[1024] = {0};
    sprintf(sql, "insert into USER(U_NAME,U_AGE,U_GENDER) values('%s','%d','%s')", "lion", 25, "male");
    conn.connect("localhost", 3306, "lion", "Csj19971012!", "lion_db");
    conn.update(sql);
    return 0;
}