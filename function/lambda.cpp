//
// Created by Administrator on 2026/5/7.
//
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <windows.h>

// ============================================
// Lambda 表达式的三种传参方式演示
// ============================================

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "=== Lambda 表达式传参方式演示 ===" << std::endl;

    // ---------- 1. Lambda 传值捕获 ----------
    std::cout << "\n--- 1. 传值捕获 (Capture by Value) ---" << std::endl;

    int value = 10;
    std::string text = "Hello";

    // [value, text] 表示按值捕获（创建副本）
    auto lambdaByValue = [value, text]() {
        std::cout << "[Lambda内] value = " << value << ", text = " << text << std::endl;
        // value = 100;  // ❌ 编译错误：按值捕获的变量默认是 const
        std::cout << "[Lambda内] 无法修改按值捕获的变量" << std::endl;
    };

    std::cout << "调用前: value = " << value << ", text = " << text << std::endl;
    lambdaByValue();
    std::cout << "调用后: value = " << value << ", text = " << text << " (未改变)" << std::endl;

    // ---------- 2. Lambda 引用捕获 ----------
    std::cout << "\n--- 2. 引用捕获 (Capture by Reference) ---" << std::endl;

    int refValue = 20;
    std::string refText = "World";

    // [&refValue, &refText] 表示按引用捕获（直接操作原变量）
    auto lambdaByRef = [&refValue, &refText]() {
        std::cout << "[Lambda内初始] refValue = " << refValue << ", refText = " << refText << std::endl;
        refValue = 200;      // ✅ 可以修改
        refText = "Modified"; // ✅ 可以修改
        std::cout << "[Lambda内修改后] refValue = " << refValue << ", refText = " << refText << std::endl;
    };

    std::cout << "调用前: refValue = " << refValue << ", refText = " << refText << std::endl;
    lambdaByRef();
    std::cout << "调用后: refValue = " << refValue << ", refText = " << refText << " (已改变)" << std::endl;

    // ---------- 3. Lambda 混合捕获 ----------
    std::cout << "\n--- 3. 混合捕获 (Mixed Capture) ---" << std::endl;

    int a = 30;
    int b = 40;
    std::string str = "Test";

    // [a, &b] 表示 a 按值捕获，b 按引用捕获
    auto lambdaMixed = [a, &b, &str]() {
        std::cout << "[Lambda内] a = " << a << " (只读)" << std::endl;
        std::cout << "[Lambda内] b = " << b << " (可修改)" << std::endl;
        std::cout << "[Lambda内] str = " << str << " (可修改)" << std::endl;

        // a = 300;  // ❌ 编译错误：a 是按值捕获的
        b = 400;     // ✅ b 是按引用捕获的
        str += "_Modified";  // ✅ str 是按引用捕获的

        std::cout << "[Lambda内修改后] b = " << b << ", str = " << str << std::endl;
    };

    std::cout << "调用前: a = " << a << ", b = " << b << ", str = " << str << std::endl;
    lambdaMixed();
    std::cout << "调用后: a = " << a << " (未变), b = " << b << " (已变), str = " << str << " (已变)" << std::endl;

    // ---------- 4. Lambda 作为函数参数（传值）----------
    std::cout << "\n--- 4. Lambda 作为函数参数（传值）---" << std::endl;

    auto addLambda = [](int x, int y) -> int {
        return x + y;
    };

    // 定义一个接受 Lambda 的函数
    auto executeLambda = [](std::function<int(int, int)> func, int a, int b) {
        std::cout << "[函数内] 执行 Lambda: " << a << " + " << b << " = " << func(a, b) << std::endl;
        return func(a, b);
    };

    int result = executeLambda(addLambda, 5, 3);
    std::cout << "结果: " << result << std::endl;

    // ---------- 5. Lambda 捕获大对象（性能对比）----------
    std::cout << "\n--- 5. Lambda 捕获大对象（性能对比）---" << std::endl;

    std::vector<int> bigData(1000000, 42);  // 100万元素

    // ❌ 按值捕获大对象（会拷贝，慢）
    auto lambdaCopyBig = [bigData]() {
        std::cout << "[按值捕获] 数据大小: " << bigData.size() << " (已拷贝)" << std::endl;
    };

    // ✅ 按引用捕获大对象（不拷贝，快）
    auto lambdaRefBig = [&bigData]() {
        std::cout << "[按引用捕获] 数据大小: " << bigData.size() << " (无拷贝)" << std::endl;
    };

    std::cout << "原始数据大小: " << bigData.size() << std::endl;
    lambdaCopyBig();  // 会拷贝整个 vector
    lambdaRefBig();   // 不会拷贝

    // ---------- 6. mutable Lambda（允许修改按值捕获的变量）----------
    std::cout << "\n--- 6. Mutable Lambda（修改按值捕获的变量）---" << std::endl;

    int mutableValue = 50;

    // 使用 mutable 关键字，允许修改按值捕获的变量（但只影响副本）
    auto lambdaMutable = [mutableValue]() mutable {
        std::cout << "[Mutable Lambda内初始] mutableValue = " << mutableValue << std::endl;
        mutableValue = 500;  // ✅ 可以修改副本
        std::cout << "[Mutable Lambda内修改后] mutableValue = " << mutableValue << std::endl;
    };

    std::cout << "调用前: mutableValue = " << mutableValue << std::endl;
    lambdaMutable();
    std::cout << "调用后: mutableValue = " << mutableValue << " (未改变，因为修改的是副本)" << std::endl;

    // ---------- 总结 ----------
    std::cout << "\n========================================" << std::endl;
    std::cout << "总结：" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "[capture]       - 按值捕获（创建副本，不可修改）" << std::endl;
    std::cout << "[&capture]      - 按引用捕获（操作原变量，可修改）" << std::endl;
    std::cout << "[=]             - 按值捕获所有外部变量" << std::endl;
    std::cout << "[&]             - 按引用捕获所有外部变量" << std::endl;
    std::cout << "[a, &b]         - 混合捕获（a按值，b按引用）" << std::endl;
    std::cout << "[x]() mutable   - 允许修改按值捕获的副本" << std::endl;

    return 0;
}