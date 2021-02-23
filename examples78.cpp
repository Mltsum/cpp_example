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
 *  拷贝构造函数能实现默认深拷贝？
 */

class CA {
public:
    CA() : a(10) {}
    /**
     * 通过使用另一个同类型的对象来初始化新创建的对象。
     * 复制对象把它作为参数传递给函数。
     * 复制对象，并从函数返回这个对象。
     *
     * 注意: 默认的拷贝构造函数是不对指针进行赋值的，因此如果类中有指针要在拷贝构造函数中额外处理
     * @param b
     */
    CA(const CA &c) {
        // 拷贝地址，地址相同，深拷贝可能会导致crash
        //        this->ptr = c.ptr;
        // 拷贝地址，地址相同，浅拷贝
        this->ptr = new int();
        *this->ptr = *c.ptr;
    }
    void setb(int b) { this->b = b; }
    void setPtr(int *p) { this->ptr = p; }

private:
    int  a;
    int  b;
    int *ptr;
};

int main(int argc, char **argv) {
    CA   ca1;
    int  a = 1;
    int *p = &a;
    ca1.setb(11);
    ca1.setPtr(p);
    cout << "ca1 address : " << &ca1 << endl;

    CA ca2 = ca1;
    cout << "ca2 address : " << &ca2 << endl;

    return 0;
}
