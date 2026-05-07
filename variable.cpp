//
// Created by Administrator on 2026/5/6.
//

#include <iostream>
#include <windows.h>
using namespace std;

extern int a, b;
extern int c;
extern float f;
//声明函数，告诉编译器有这个函数，可以调用
 int func();

int main(int argc, char *argv[]) {
    extern int d2, f2;
    int d1 = 3, f1 = 5; // 定义并初始化 d 和 f
    char x = 'x'; // 变量 x 的值为 'x'
    std::cout << x;


    // 变量定义
    int a, b;
    int c;
    float f;
    // 实际初始化
    a = 10;
    b = 20;
    c = a + b;

    std::cout << c << std::endl;

    f = 70.0 / 3.0;
    cout << f << endl;
    //函数调用，只要声明了就能调用，但是具体能不能调用需要看函数定义
    int i = func();
    cout << i << endl;
    return 0;
}
/*
 * 函數在调用点的后面，需要先声明再定义
 */
int func() {
    return 0;
}
