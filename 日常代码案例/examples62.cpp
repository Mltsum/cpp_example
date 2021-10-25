#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

/**
 * 类内函数调用时，是否用静态函数的问题
 */

using namespace std;

class MergeDot {
public:
    MergeDot() { tsrCodes = {1, 2, 3}; }
    static bool compareTsrCodeByScore(int &l, int &r) {
        return l < r;  // 升序
    }

    /*
     *  compareTsrCodeByScore
     * 必须声明为静态。原因是类内非静态函数相互调用时，必须参数可以对应上。而compareTsrCodeByScore(int &l, int &r)
     *  实际上是有三个参数的，因此在compareTsrCodeByScore调用时会提示找不到函数。
     */
    void func1() { std::sort(tsrCodes.begin(), tsrCodes.end(), compareTsrCodeByScore); };

public:
    vector<int> tsrCodes;
};

/**
 * 检查sort 的比较函数，如果返回空
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    std::cout << "end" << std::endl;

    double              t1;
    map<double, double> tmp;
    map<double, int>    tmp2;
    auto                s1 = keyInMap(t1, tmp);
    auto                s2 = keyInMap(t1, tmp2);
    return 0;
}