#include <math.h>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include "merge.h"

using namespace std;

/**********************************************
1. c++ 默认参数

**********************************************/

/**
 * 有函数声明(原型)时,默认参数可以放在函数声明或者定义中，但只能放在二者之一
 * 没有函数(原型)时,默认参数在函数定义时指定.
 * 在具有多个参数的函数中指定默认值时,默认参数都必须出现在不默认参数的右边,一旦某个参数开始指定默认值,它右边的所有参数都必须指定默认值.
 * 在调用具有默认参数的函数时, 若某个实参默认,其右边的所有实参都应该默认。
 * @param a
 * @param b
 */
void func1(int a = 1, int b = 2) {
    cout << __FUNCTION__ << endl;
    cout << a << endl;
    cout << b << endl;
}

/**
 * 检查sort 的比较函数，如果返回空
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
    func1(2, 4);

    int a;
    int b;

    // 调用是不能像python一样直接赋值。赋值相当于在输入时对本地变量赋值
    func1(a = 2, b = 4);
    std::cout << "end" << std::endl;
    return 0;
}