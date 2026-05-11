//
// Created by Administrator on 2026/5/9.
//
#include <iostream>
#include <sqlite3.h> // 引入头文件

// 回调函数：每查询到一行数据，这个函数就会被调用一次
static int callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\t";
    }
    std::cout << std::endl;
    return 0;
}

int main() {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    // 1. 打开数据库（如果 test.db 不存在，会自动创建）
    rc = sqlite3_open("test.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Opened database successfully" << std::endl;
    }

    // 2. 创建表
    const char* sql_create = "CREATE TABLE IF NOT EXISTS USERS ("
                             "ID INT PRIMARY KEY     NOT NULL,"
                             "NAME           TEXT    NOT NULL,"
                             "AGE            INT     NOT NULL);";

    rc = sqlite3_exec(db, sql_create, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    // 3. 插入数据
    const char* sql_insert = "INSERT INTO USERS (ID, NAME, AGE) VALUES (1, 'Alice', 25);";
    sqlite3_exec(db, sql_insert, 0, 0, &zErrMsg);

    // 4. 查询数据
    const char* sql_select = "SELECT * FROM USERS;";
    std::cout << "--- Query Results ---" << std::endl;
    rc = sqlite3_exec(db, sql_select, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    // 5. 关闭数据库
    sqlite3_close(db);
    return 0;
}
