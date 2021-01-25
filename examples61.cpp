#include <math.h>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

/**
 * 函数模版
 * 1）函数模版允许使用多个类型参数，但在template定义部分的每个形参前必须有关键字typename或class.
 *      template<class 数据类型参数标识符1，…，class 数据类型参数标识符n>
 * 2) 在template语句与函数模板定义语句<返回类型>之间不允许有别的语句。

 */

using namespace std;

template <typename T, typename S>
bool keyInMap(T key, std::map<T, S>& m) {
    bool res = false;
    for (auto ele : m) {
        if (key == ele.first) {
            res = true;
        }
    }
    return res;
}

/**
 * 检查sort 的比较函数，如果返回空
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
    std::cout << "end" << std::endl;

    double              t1;
    map<double, double> tmp;
    map<double, int>    tmp2;
    auto                s1 = keyInMap(t1, tmp);
    auto                s2 = keyInMap(t1, tmp2);
    return 0;
}