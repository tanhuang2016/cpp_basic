//
// Created by Administrator on 2026/5/7.
//
#include <iostream>
#include <windows.h>

using namespace std;

int main( )
{
    SetConsoleOutputCP(CP_UTF8);
    char name[50];

    cout << "请输入您的名称： ";
    cin >> name;
    cout << "您的名称是： " << name << endl;

}