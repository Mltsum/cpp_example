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
    vector<int> v {1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (auto item : v) {
        item = 2;
    }

    // 需要更改值的话，记得用引用
    for (auto &item : v) {
        item = 2;
    }
    return 0;
};
