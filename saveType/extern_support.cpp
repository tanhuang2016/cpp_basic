//
// Created by Administrator on 2026/5/7.
//
#include <iostream>

extern int count;

void write_extern(void)
{
    std::cout << "Count is " << count << std::endl;
}