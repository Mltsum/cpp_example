#include <iostream>
#include <array>
#include <memory>

/*
 * 强制转换运算符
 *  const_cast<type>(exp) : 用来更改const和volatile属性的
 *  static_cast<type>(exp) : 静态转换，非运行时的强制转换，没有运行时类检查来保护转换的安全性
 *
 */

#include <io.h>
#include <string>

using namespace std;

int main(){
    float f = 0.12345;
    cout << static_cast<int>(f) << endl;

//    cout << dynamic_cast<int>(f) << endl;
}