#include <dirent.h>
#include <stdio.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <unsupported/Eigen/CXX11/Tensor>
#include "math.h"

using namespace std;
using namespace Eigen;

/*
 * lambda语法
 * [capture](parameters)->return-type {body}
 */

/**
说明:
普通函数与lambda函数对比
    匿名函数是许多编程语言都支持的概念，有函数体，没有函数名。
    函数对象能维护状态，但语法开销大，而函数指针语法开销小，却没法保存范围内的状态。

 */

// []叫做捕获说明符，表示一个lambda表达式的开始
// 接下来是参数列表，即这个匿名的lambda函数的参数
// ->return-type表示返回类型

// 静态变量是在main之前构造的
auto func = []() { cout << "hello,world" << endl; };

bool func1() {
    printf("gResistor ====");
    return false;
}
static bool gResistor = func1();

// 静态函数确定的是作用域
static void func2() {
    cout << "hello,world2" << endl;
}

int main() {
    printf("main ====");
    func();

    // lambda函数能够捕获lambda函数外的具有自动存储时期的变量。函数体与这些变量的集合合起来叫闭包。
    //    [] 不截取任何变量
    //    [&} 截取外部作用域中所有变量，并作为引用在函数体中使用
    //    [=] 截取外部作用域中所有变量，并拷贝一份在函数体中使用
    //    [=, &foo] 截取外部作用域中所有变量，并拷贝一份在函数体中使用，但是对foo变量使用引用
    //    [bar] 截取bar变量并且拷贝一份在函数体重使用，同时不截取其他变量
    //    [x, &y] x按值传递，y按引用传递
    //    [this] 截取当前类中的this指针。如果已经使用了&或者=就默认添加此选项。
    int  a = 1;
    auto g = [&]() { cout << a << endl; };
    g();

    //
    int b = 2;
    //    void g = [&]() { cout << b << endl; }();
}

/*
不属于类成员函数的静态函数是一个普通的全局的静态函数
普通函数的定义和声明默认情况下是extern的，但静态函数只是在声明他的文件当中可见，不能被其他文件所用。因此定义静态函数有以下好处：
    其他文件中可以定义相同名字的函数，不会发生冲突。
    态函数不能被其他文件所用。
static bool gResistor = []() {
    MNNInsertExtraRuntimeCreator(MNN_FORWARD_OPENCL, new CLRuntimeCreator, true);
    return false;
}();

 */