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
不要将执行的代码放在头文件中
静态变量的初始化不能放置到头文件中


**********************************************/

Utils* Utils::uts = nullptr;
/**
 * 检查sort 的比较函数，如果返回空
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
    int         e = 1;
    vector<int> v = {1, 2, 3, 4, 5};

    auto res = Utils::getIns()->isElementInVector(1, {1, 2});
    std::cout << res << std::endl;

    std::cout << "end" << std::endl;
    return 0;
}