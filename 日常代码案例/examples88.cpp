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

/*
 *  判断map中是否含有key最有效率的方式
 */
int main(int argc, char **argv) {
    map<string, int> m;
    m.insert(make_pair("one", 1));
    m.insert(make_pair("two", 2));
    m.insert(make_pair("three", 3));
    m.insert(make_pair("four", 4));
    m.insert(make_pair("five", 5));

    /**
     * count 比轮训有效率
     */
    if (m.count("one")) {
        cout << "has the key - one" << endl;
    }

    if (m.count("six")) {
        cout << "has the key - six" << endl;
    }

    return 0;
}
