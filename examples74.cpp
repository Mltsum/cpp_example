#include <dirent.h>
#include <stdio.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <map>
#include <unsupported/Eigen/CXX11/Tensor>
#include "math.h"

using namespace std;
using namespace Eigen;

int main(int argc, char **argv) {
    /**
     * c++ 中的and ?
     * c++ 中的可替代关键词
     * https://blog.csdn.net/nicai_xiaoqinxi/article/details/102692740
     */

    if (true and false) {
        cout << "code here..." << endl;
    }

    if (true or false) {
        cout << "code here1..." << endl;
    }

    if (not false) {
        cout << "code here2..." << endl;
    }

    if (not true) {
        cout << "code here3..." << endl;
    }

    return 0;
};