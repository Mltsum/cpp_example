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
    int n = 3;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cout << i << "-" << j << endl;
        }
    }

    return 0;
};

/*
 * 结果
 * 0-1
 * 0-2
 * 1-2
 */