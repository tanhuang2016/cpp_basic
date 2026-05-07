//
// Created by Administrator on 2026/5/7.
//
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int main( )
{
    SetConsoleOutputCP(CP_UTF8);
    // 基于当前系统的当前日期/时间
    time_t now = time(0);

    cout << "1970 到目前经过秒数:" << now << endl;

    tm *ltm = localtime(&now);

    // 输出 tm 结构的各个组成部分
    cout << "年: "<< 1900 + ltm->tm_year << endl;
    cout << "月: "<< 1 + ltm->tm_mon<< endl;
    cout << "日: "<<  ltm->tm_mday << endl;
    cout << "时间: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;


    // 格式化输出：yyyy-mm-dd HH:mm:ss
    char time_buffer[80];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", ltm);
    cout << "\n格式化时间: " << time_buffer << endl;
}