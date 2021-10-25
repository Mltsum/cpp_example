#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include "TestSuite.h"
using namespace std;

/**
 * c++ 一种优良的测试模式
 *
 */

#define PL cout << __LINE__ << endl

int main(int argc, char* argv[]) {
    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        printf("增加help信息...");
        return 0;
    }
    // 用户代码

    if (argc > 1) {
        auto name = argv[1];
        TestSuite::run(name);
    } else {
        TestSuite::runAll();
    }
    return 0;
}
