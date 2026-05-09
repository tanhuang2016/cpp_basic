//
// Created by Administrator on 2026/5/9.
//
//参数宏
#include <iostream>
#include <windows.h>
using namespace std;

#define MIN(a,b) (a<b ? a : b)

int main ()
{
    SetConsoleOutputCP(CP_UTF8);
    int i, j;
    i = 100;
    j = 30;
    cout <<"较小的值为：" << MIN(i, j) << endl;

    return 0;
}