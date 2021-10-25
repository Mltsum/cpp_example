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
 * C++ const 和 constexpr 的区别
 *   const并未区分出编译期常量和运行期常量
 *   constexpr限定在了编译期常量。简单的来说，如果其传入的参数可以在编译时期计算出来，那么这个函数就会产生编译时期的值。但是，传入的参数如果不能在编译时期计算出来，那么constexpr修饰的函数就和普通函数一样了。
 *   目的 : 一方面是为了引入更多的编译时计算能力，另一方面也是解决 C++98 的 const 的双重语义问题。
 */

constexpr int foo(int i) {
    return i + 5;
}

int main() {
    int i = 10;

    std::array<int, foo(5)> arr;  // OK

    foo(i);  // Call is Ok

    // But...
    // std::array需要编译期常值才能编译通过的小技巧。这样的话，即可检测你所写的函数是否真的产生编译期常值了。
    //    std::array<int, foo(i)> arr1;  // Error
}
