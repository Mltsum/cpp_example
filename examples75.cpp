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
 * map 不存在的key, 会返回什么值？？
 *  返回默认值0
 * 能否设置返回默认值？
 *  并不能, 这点和python的字典不同
 *
 */

int main(int argc, char **argv) {
    map<string, int> m;
    m.insert(make_pair("one", 1));
    m.insert(make_pair("two", 2));
    m.insert(make_pair("three", 3));
    m.insert(make_pair("four", 4));

    auto i = m["five"];
    cout << i << endl;

    auto j = m.at("five");
    cout << i << endl;

    return 0;
}

/*
    dict = {'Alice': '2341', 'Beth': '9102', 'Cecil': '3258'}
    print(dict.get('Alice'))
    print(dict.get('mas','default'))
    '''
    2341
    default
    '''

*/
