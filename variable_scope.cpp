//
// Created by Administrator on 2026/5/7.
//
#include <iostream>
using namespace std;
int g=10;
int gfunc() {
    cout << "g=" << g << endl;
    return g;
}

class MyClass {
public:
    static inline int class_var1=1;
    static const int class_var2=2;
    static int class_var;// 只能声明，不能定义
};
int MyClass::class_var = 3;  // 必须在类外定义
int main(int argc, char *argv[]) {
    cout << "g=" << g << endl;
    int g=20;
    cout << "g=" << g << endl;
    //强制访问全局变量
    cout << "::g=" << ::g << endl;
    cout<<gfunc() << endl;
    int a;
    cout << "a=" << a << endl;

    std::cout << "var: " << MyClass::class_var << std::endl;
    std::cout << "var: " << MyClass::class_var1 << std::endl;
    std::cout << "var: " << MyClass::class_var2 << std::endl;
    return 0;
}


