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
 * 函数传入*a  和 传入*&a的相同点和不同点
 * 相同点:
 *   传入只能是指针，*a可以传入指针和取址。*&a只能传入指针(why??)
 *
 * 不同点:
 *   *a 和传入的地址不绑定，当地址a值改变时，传入的值不变
 *   *&a 和传递的地址绑定，当地址a值改变时，传入的值也发生变化
 *
 *
 */

void func1(int *&a) {
    cout << "func1" << endl;
}

void func2(int *a) {
    cout << "func1" << endl;
}

int main(int argc, char **argv) {
    //    int  a = 10;
    //    int *p = &a;
    //    *p = 11;  // 地址指向的数改变
    //    cout << a << endl;
    //    int c = 12;
    //    p = &c;  // 地址改动了，但和a无关，不绑定
    //    cout << a << endl;

    //    int   a = 10;
    //    int * b = &a;
    //    int *&p = b;  // *& 的赋值或者函数参数的传入对象只能是指针
    //    *p = 11;      // 地址指向的数改变
    //    cout << *b << endl;
    //    int c = 12;
    //    p = &c;  // 地址改动了，和b绑定，*b的值也会发生变化
    //    cout << *b << endl;

    /*
     * *&a 传入指针？ 只能传入指针, 不能传入取址
     */
    int  x = 1;
    int *px = &x;
    cout << &x << endl;  // 两者是等价的
    cout << px << endl;

    //    func1((&x));  // 引用必须用一个变量别名才可以，因此传入&x地址，指针是可以的，但指针引用是不行的
    func1(px);
    func2(&x);

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
