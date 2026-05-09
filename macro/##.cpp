//
// Created by Administrator on 2026/5/9.
//
#include <iostream>
using namespace std;

#define MKSTR1( x ) #x
#define concat(a, b) a ## b

int main ()
{
    cout << MKSTR1(HELLO C++) << endl;
    int xy = 100;

    cout << concat(x, y);


    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    cout << "Compiler: " << __cplusplus << endl;
    return 0;
}