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
 *  std::call_once的作用是很简单的，　就是保证函数或者一些代码段在并发或者多线程的情况下，始终只会被执行一次。比如一些init函数，多次调用可能导致各种奇怪问题。
 */

std::once_flag flag1;

void simple_do_once() {
    std::call_once(flag1, []() { std::cout << "Simple example: called once\n"; });
}

int main() {
    std::thread st1(simple_do_once);
    std::thread st2(simple_do_once);
    std::thread st3(simple_do_once);
    std::thread st4(simple_do_once);
    st1.join();
    st2.join();
    st3.join();
    st4.join();
}