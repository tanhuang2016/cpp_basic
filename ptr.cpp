//
// Created by Administrator on 2026/5/7.
//
#include <iostream>
#include <windows.h>

using namespace std;

int main2 ()
{
    int  var = 20;   // 实际变量的声明
    int  *ip= &var;        // 指针变量的声明

    // ip = &var;       // 在指针变量中存储 var 的地址
    *ip=30;
    cout << "Value of var variable: ";
    cout << var << endl;

    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;

    return 0;
}


int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    int  var;
    int  *ptr;
    int  **pptr;
    int  ***pptr2;

    var = 3000;

    // 获取 var 的地址
    ptr = &var;

    // 使用运算符 & 获取 ptr 的地址
    pptr = &ptr;
    pptr2= &pptr;

    // 使用 pptr 获取值
    cout << "var 值为 :" << var << endl;
    cout << "*ptr 值为:" << *ptr << endl;
    cout << "**pptr 值为:" << **pptr << endl;
    cout << "**pptr2 值为:" << ***pptr2 << endl;
}
