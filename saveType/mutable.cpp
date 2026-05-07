//
// Created by Administrator on 2026/5/7.
//
#include <iostream>

class Example {
public:
    Example() : value(0), cachedValue(0) {}

    // 常量成员函数
    int getValue() const {
        cachedValue = 1 * 2;
        return value; // 读取常量成员
    }

    // 修改 mutable 成员
    void increment() {
        ++value;
        cachedValue = value * 2; // 修改 mutable 成员
    }

    int getCachedValue() const {
        return cachedValue; // 读取 mutable 成员
    }

private:
    int value;                 // 常规成员，不能在 const 函数中修改
    mutable int cachedValue;   // 可修改成员，可以在 const 函数中修改
};

int main() {
    const Example ex;
    // ex.increment(); // 错误：无法在 const 对象上调用非 const 函数
    // ex.value = 10;  // 错误：无法修改 const 对象的成员

    std::cout << "Value: " << ex.getValue() << std::endl;
    std::cout << "Cached Value: " << ex.getCachedValue() << std::endl; // 输出为 0

    return 0;
}