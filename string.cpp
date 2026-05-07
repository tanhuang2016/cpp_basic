//
// Created by Administrator on 2026/5/7.
//

#include <cstring>
#include <iostream>
#include <windows.h>
using namespace std;
/*
 * c风格
 */
int main2(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    //C 风格字符串
    char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};
    char site2[] = "RUNOOB";
    std::cout << site<< std::endl;
    std::cout << site2<< std::endl;


    char str1[13] = "runoob";
    char str2[13] = "google";
    char str3[13];
    int  len ;

    // 复制 str1 到 str3
    strcpy( str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;

    // 连接 str1 和 str2
    strcat( str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;

    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;



}

/*
 * c++中的string
 */
int main(int argc, char *argv[]) {
    string str1 = "runoob";
    string str2 = "google";
    string str3;
    int  len ;

    // 复制 str1 到 str3
    str3 = str1;
    cout << "str3 : " << str3 << endl;

    // 连接 str1 和 str2
    str3 = str1 + str2;
    cout << "str1 + str2 : " << str3 << endl;

    // 连接后，str3 的总长度
    len = str3.size();
    cout << "str3.size() :  " << len << endl;
}
