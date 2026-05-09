//
// Created by Administrator on 2026/5/8.
//
#include <iostream>
#include <stdexcept>
/*@echo off

:: 设置代理
set HTTP_PROXY=http://127.0.0.1:7897
set HTTPS_PROXY=http://127.0.0.1:7897

:: 手动指定编译器路径
set CC=D:\soft\CLion 2026.1.1\bin\mingw\bin\gcc.exe
set CXX=D:\soft\CLion 2026.1.1\bin\mingw\bin\g++.exe

:: 进入 vcpkg 目录
cd /d D:\soft\vcpkg-2026.04.27\vcpkg-2026.04.27

:: 安装 boost
vcpkg.exe install boost-system:x64-mingw-dynamic boost-filesystem:x64-mingw-dynamic boost-stacktrace:x64-mingw-dynamic

pause*/
// #define BOOST_STACKTRACE_USE_NOOP
#include <boost/filesystem.hpp>
#include <boost/stacktrace.hpp>
using namespace std;

double division(int a, int b)
{
    if( b == 0 )
    {
        throw runtime_error("Division by zero condition!");
    }
    return (a/b);
}

int main ()
{
    int x = 50;
    int y = 0;
    double z = 0;
    // 测试 boost::filesystem
    boost::filesystem::path current_path = boost::filesystem::current_path();
    cout << "Current path: " << current_path.string() << endl;
    // try {
    //     z = division(x, y);
    //     cout << z << endl;
    // }catch (const char* msg) {
    //     cerr << msg << endl;
    // }
    // try {
    //     z = division(x, y);
    //     cout << z << endl;
    // }catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << "\nStack:\n"
    //               << boost::stacktrace::stacktrace();
    // }
    int a =1;
    int *b= &a;
    cout <<"b"<< *b << endl;
    cout <<"b1"<< b[0] << endl;
    int *invalue= NULL;
    invalue = new int[2]{2,3};
    cout <<"invalue"<< *invalue << endl;
    cout <<"invalue2"<< invalue[1] << endl;
    char* pvalue  = NULL;
    pvalue  = new char[20];
    try {
        z = division(x, y);
        cout << z << endl;
    } catch (const std::exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
        cerr << "Stack trace:\n" << boost::stacktrace::stacktrace() << endl;
    }

    return 0;
}