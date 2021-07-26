#include <dirent.h>
#include <string.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <tuple>
#include <vector>

using namespace std;

/**
 * 关于C++的lambda函数
 *   匿名函数
 *   [capture](parameters)->return-type {body}
 *   []叫做捕获说明符；
 *   []是指闭包，闭包是指在Lambda函数之外声明的变量，Lambda函数可以引用这些变量，这些变量的集合叫做闭包。
 *      lambda函数外的具有自动存储时期的变量。函数体与这些变量的集合合起来叫闭包。
 *      [] 不截取任何变量
 *      [&} 截取外部作用域中所有变量，并作为引用在函数体中使用
 *      [=] 截取外部作用域中所有变量，并拷贝一份在函数体中使用
 *      [=, &foo] 截取外部作用域中所有变量，并拷贝一份在函数体中使用，但是对foo变量使用引用
 *      [bar] 截取bar变量并且拷贝一份在函数体重使用，同时不截取其他变量
 *      [x, &y] x按值传递，y按引用传递
 *      [this] 截取当前类中的this指针。如果已经使用了&或者=就默认添加此选项。
 *
 *   ->return-type表示返回类型，如果没有返回类型，则可以省略这部分。
 *
 *   函数类型: std:function(通用多态函数封装器)
 *      function<T> f    // T 表示函数的输入和输出
 *      对应其boost::function函数包装器。在c++0x11中，将boost::function纳入标准库中。
 *
 *   为什么有lambda？
 *      有一些函数只是临时用一下，而且业务逻辑也比较的简单，相当于是临时工，就没必要给它定义成一个正常函数。使用临时的匿名函数，可以减轻函数的数量，让代码变的清晰易读。
 */

int main(int argc, const char *argv[]) {
    /**
     * 排序中的匿名函数
     */
    std::vector<int> v {1, 2, 3, 4};
    std::sort(v.begin(), v.end(), [](int &l, int &r) { return l < r; });          // 隐式的声明返回类型
    std::sort(v.begin(), v.end(), [](int &l, int &r) -> bool { return l < r; });  // 显式的声明返回类型

    /**
     * lambda函数的类型为std:function
     */
    std::function<void(int &)> f;
    f = [](int &i) { cout << "hello std::function and lambda function." << endl; };

    return 0;
}