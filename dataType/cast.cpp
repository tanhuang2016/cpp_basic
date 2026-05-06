//
// Created by Administrator on 2026/5/6.
//

#include <iostream>
#include <windows.h>



int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);

    volatile const int i = 10;
    int& r = const_cast<int&>(i); // 常量转换，将const int转换为int，让变量可变
    r = 20; // ✅ 编译通过！因为 r 不是 const 的
    std::cout << i << std::endl; // 输出可能是 20
    std::cout << "i 的值: " << i << std::endl;   // 很可能还是 10（编译器优化）
    std::cout << "r 的值: " << r << std::endl;   // 肯定是 20（因为它不是 const）
    std::cout << "i 的地址: " << &i << std::endl;
    std::cout << "r 的地址: " << &r << std::endl; // 地址是一样的！


    int j = 10;
    float f = reinterpret_cast<float&>(j);
    std::cout << f;
    return 0;
}
