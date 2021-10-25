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
    vector<double> c_list {4.8665442543380477, 5.3343303469145882};

    // 0.0 则按照整型来累加
    double center = accumulate(c_list.begin(), c_list.end(), 0) / double(c_list.size());

    // 0.0 则按照浮点来累加
    double center1 = accumulate(c_list.begin(), c_list.end(), 0.0) / double(c_list.size());

    /**
     * 源码如下: 累加的类型由 __init 决定
     * 源码由__开头的变量，挺好看的
     *
     */

    //    template <class _InputIterator, class _Tp>
    //    inline _LIBCPP_INLINE_VISIBILITY
    //    _Tp
    //    accumulate(_InputIterator __first, _InputIterator __last, _Tp __init)
    //    {
    //        for (; __first != __last; ++__first)
    //            __init = __init + *__first;
    //        return __init;
    //    }

    return 0;
};
