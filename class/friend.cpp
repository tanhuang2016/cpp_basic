//
// Created by Administrator on 2026/5/8.
//
#include <iostream>
#include <ostream>

using namespace std;

class Box
{


    double width;
public:
    friend void printWidth( Box box );
    // 授权：允许这个全局函数访问我的私有变量
    friend ostream& operator<<(ostream& os, const Box& box);
    // 声明 + 运算符重载友元函数
    Box operator+(const Box& b1);
    void setWidth( double wid );

    Box() = default;


    explicit Box(int i);

};


// 成员函数定义
void Box::setWidth( double wid )
{
    width = wid;
}

Box::Box(int i) {
    setWidth(i);
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth( Box box )
{
    /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width <<endl;
}

// 第一个参数是左边的 cout (ostream&)
// 第二个参数是右边的 myBox (const Box&)
ostream& operator<<(ostream& os, const Box& box) {
    os << "Width: " << box.width; // ⚠️ 注意：width 是私有的！
    return os;
}

// 重载 + 运算符：将两个 Box 的宽度相加
Box Box:: operator+(const Box& other)
{
    Box result;
    result.width = this->width + other.width;
    return result;
}
void doSomething(Box b) {
    // 处理盒子
}
// 程序的主函数
int main( )
{
    Box box;
    // 使用成员函数设置宽度
    box.setWidth(10.0);

    // 使用友元函数输出宽度
    printWidth( box );
    std::cout << box;

    Box a(1), b(2);
    Box c = a + b;
    cout << c;
    // doSomething(10); 如果不加explicit，可以隐式转换
    return 0;
}