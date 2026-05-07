//
// Created by Administrator on 2026/5/7.
//
#include <iostream>
#include <windows.h>
using namespace std;

// 函数声明
int max(int , int num2=20 );


int max(int num1)
{


    return num1;
}


// ============================================
// 1. 传值调用 (Pass by Value)
// 修改形参不会影响实参
// ============================================
void passByValue(int x) {
    std::cout << "[传值] 函数内初始值: x = " << x << std::endl;
    x = 100;  // 修改形参
    std::cout << "[传值] 函数内修改后: x = " << x << std::endl;
}

// ============================================
// 2. 指针调用 (Pass by Pointer)
// 通过指针间接修改实参
// ============================================
void passByPointer(int* ptr) {
    std::cout << "[指针] 函数内初始值: *ptr = " << *ptr << std::endl;
    *ptr = 200;  // 通过指针修改实参
    std::cout << "[指针] 函数内修改后: *ptr = " << *ptr << std::endl;
}

// ============================================
// 3. 引用调用 (Pass by Reference)
// 直接操作实参的别名
// ============================================
void passByReference(int& ref) {
    std::cout << "[引用] 函数内初始值: ref = " << ref << std::endl;
    ref = 300;  // 直接修改实参
    std::cout << "[引用] 函数内修改后: ref = " << ref << std::endl;
}

// ============================================
// 辅助函数：打印分隔线
// ============================================
void printSeparator(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main ()
{
    SetConsoleOutputCP(CP_UTF8);

    // 局部变量声明
    int a = 100;
    int b = 200;
    int ret;

    // 调用函数来获取最大值
    ret = max(a,b);

    cout << "Max value is : " << ret << endl;





    // ---------- 测试传值调用 ----------
    printSeparator("1. 传值调用 (Pass by Value)");
    int value = 10;
    std::cout << "调用前: value = " << value << std::endl;
    passByValue(value);
    std::cout << "调用后: value = " << value << " (未改变)" << std::endl;

    // ---------- 测试指针调用 ----------
    printSeparator("2. 指针调用 (Pass by Pointer)");
    int pointerValue = 20;
    std::cout << "调用前: pointerValue = " << pointerValue << std::endl;
    passByPointer(&pointerValue);  // 传入地址
    std::cout << "调用后: pointerValue = " << pointerValue << " (已改变)" << std::endl;

    // ---------- 测试引用调用 ----------
    printSeparator("3. 引用调用 (Pass by Reference)");
    int refValue = 30;
    std::cout << "调用前: refValue = " << refValue << std::endl;
    passByReference(refValue);  // 直接传入变量
    std::cout << "调用后: refValue = " << refValue << " (已改变)" << std::endl;

    // ---------- 对比总结 ----------
    printSeparator("总结对比");
    std::cout << "原始值经过三次调用后的结果:" << std::endl;
    std::cout << "  value (传值):     " << value << " (未改变)" << std::endl;
    std::cout << "  pointerValue (指针): " << pointerValue << " (已改变)" << std::endl;
    std::cout << "  refValue (引用):  " << refValue << " (已改变)" << std::endl;

    std::cout << "\n关键区别:" << std::endl;
    std::cout << "  - 传值:   创建副本，不影响原值" << std::endl;
    std::cout << "  - 指针:   传入地址，可以修改原值，语法较复杂 (*, &)" << std::endl;
    std::cout << "  - 引用:   传入别名，可以修改原值，语法简洁" << std::endl;



    /*
    总结
    你的理解完全正确：
    ✅ 理念层面：
    C++ 最佳实践 = Java 默认行为
    都是"小值传值，大对象传引用"
    都基于相同的性能考量
    ✅ 实现层面：
    C++：程序员手动选择（灵活但复杂）
    Java：语言自动选择（简单但受限）
    🎯 一句话总结：
    Java 把 C++ 的最佳实践变成了语言的默认行为。
    这就是为什么有经验的 C++ 程序员学 Java 会觉得"传参很自然"，而有经验的 Java 程序员学 C++ 时会问"为什么 int 不用引用？"——因为两者的核心理念是一致的，只是控制权不同。
    */

    return 0;
}

// 函数返回两个数中较大的那个数
int max(int num1, int num2)
{
    // 局部变量声明
    int result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}
