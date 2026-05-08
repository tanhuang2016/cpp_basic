//
// Created by Administrator on 2026/5/8.
//
#include <iostream>

class MyClass {
public:
    int data;

    void display() {
        std::cout << "Data: " << data << std::endl;
    }
};

int main() {
    // 动态分配内存创建类对象
    MyClass *ptr = new MyClass;
    ptr->data = 42;

    // 通过指针调用成员函数
    ptr->display();

    // 释放动态分配的内存
    delete ptr;

    int n;
    std::cin >> n;
    // 编译器在编译时根本不知道 n 是多少，只有在运行时才知道要开多大的数组
    int* arr = new int[n];
    return 0;
}