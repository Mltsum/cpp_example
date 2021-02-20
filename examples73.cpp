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
    MatrixXd x(2, 2);

    // 这样赋值必须进行初始化矩阵大小, 且元素必须全部赋值
    x << 1, 2, 3, 4;

    cout << x << endl;

    /**
     * 必须在声明时指定大小, 下述应用时错误的
     */
    //    MatrixXd y;
    //    y(2, 2);
    //    y << 1, 2, 3, 4;
    //    cout << y << endl;

    MatrixXd points3d;

    points3d = x;
    cout << "------" << endl;
    cout << points3d << endl;

    return 0;
};
