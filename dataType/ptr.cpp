#include <iostream>
#include <windows.h>
#include <memory>

using namespace std;
//
// Created by Administrator on 2026/5/6.
class Base {
public:
    virtual ~Base()  {
        std::cout << "Base 析构函数被调用" << endl;
    };
};

class Driver : public Base {
public:
    ~Driver() override {
        std::cout << "Driver 析构函数被调用" << endl;
    };
    void show() {
        cout << "Driver::show()" << endl;
    }
};

int main(int argc, char *argv[]) {
    cout << "112" << endl;
    SetConsoleOutputCP(CP_UTF8);

    // 指针方式
    Base* ptr_base = new Driver; // 基类指针指向派生类对象

    // 将基类指针转换为派生类指针
    Driver* ptr_derived = dynamic_cast<Driver*>(ptr_base);

    if (ptr_derived) {
        ptr_derived->show(); // 成功转换，调用派生类方法
    } else {
        std::cout << "Dynamic cast failed!" << std::endl;
    }
    delete ptr_base;

    // 栈对象方式
    Driver d;
    d.show();       // 用 .
    // 自动删除，无需管理











    Driver derived_obj;
    Base& ref_base = derived_obj; // 基类引用绑定到派生类对象

    try {
        // 将基类引用转换为派生类引用
        Driver& ref_derived = dynamic_cast<Driver&>(ref_base);
        ref_derived.show(); // 成功转换，调用派生类方法
    } catch (const std::bad_cast& e) {
        std::cout << "Dynamic cast failed: " << e.what() << std::endl;
    }


    std::unique_ptr<Driver> up = std::make_unique<Driver>();
    up->show();  // 像普通指针一样用，但不用手动 delete

    std::shared_ptr<Driver> sp = std::make_shared<Driver>();
    sp->show();  // 多个指针可以共享同一个对象
    return 0;
}
