//
// Created by Administrator on 2026/5/6.
//
#include <iostream>
/*
 * 条件注释
 */
int main() {
    int num = 0;
#if num == 0
    std::cout << "0";
#else
    std::cout << "1";
#endif
}
