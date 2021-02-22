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
 * python 默认为深拷贝，c++ 默认浅拷贝
 *
 */

int main(int argc, char **argv) {
    int a = 1;
    int b = a;
    cout << &a << &b << endl;
    return 0;
}

/*
'''
python 默认深拷贝？
140606776793736
140606776793736
'''

a = [1,2,3,4,5]
print(id(a))
b = a;
print(id(b))

print('end...')

*/
