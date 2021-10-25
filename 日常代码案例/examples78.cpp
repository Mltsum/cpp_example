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
 *  可以通过重载 =  实现类的赋值浅拷贝？
 */
int main(int argc, char **argv) {
    int a = 1;
    int b = 2;
    int c = 1;
    int d = 2;

    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;

    vector<int> v;
    // emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程
    v.emplace_back(a);
    v.emplace_back(b);
    // push_back()
    // 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）
    v.push_back(c);
    v.push_back(d);

    cout << &v[0] << endl;
    cout << &v[1] << endl;
    cout << &v[2] << endl;
    cout << &v[3] << endl;

    return 0;
}
