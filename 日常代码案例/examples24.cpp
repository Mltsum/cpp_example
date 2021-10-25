// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  c++中可以用变量来定义数组吗? 不能
 *
 */
#define LENTH 10

using namespace  std;
int main () {
    /*
     * 非常量参数或对非常量符号的引用导致了故障
     */
    int a = 5;
    int arr[a];


    return 0;
}