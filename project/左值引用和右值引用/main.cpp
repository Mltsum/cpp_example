#include <dirent.h>
#include <math.h>
#include <string.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <tuple>
#include <vector>
#include "float.h"

using namespace std;

/**
 * 左值引用和右值引用
 *    左值可以取地址，右值不可以取地址。
 *
 * 问题：
 *    什么时候会用右值引用？
 *      作为一种追求执行效率的语言，C++在用临时对象或函数返回值给左值对象赋值时的深度拷贝（deepcopy）一直受到诟病。
 *      考虑到临时对象的生命期仅在表达式中持续，如果把临时对象的内容直接移动（move）给被赋值的左值对象，效率改善将是显著的。这就是移动语义的来源。
 *
 *      与传统的拷贝赋值运算符（copy assignment）成员函数、拷贝构造（copy ctor）成员函数对应，移动语义需要有移动赋值（move assignment）成员函数、
 *      移动构造（move ctor）成员函数的实现机制。可以通过函数重载来确定是调用拷贝语义还是移动语义的实现。
 *
 *      右值引用的目的是可以减少程序运行的开销，为了实现移动语义与完美转发所需要而设计出来的新的数据类型。移动语义是为了提高效率，避免临时构造对象。完美转发主要是广泛应用于泛型函数。
 *
 *      返回值优化：返回栈空间的变量引用原本是有问题的。但C++11后就直接将临时变量move出去了。
 *          理论上我们会认为通过复制构造函数复制一个临时对象，然后在赋值给外部变量。实际上编译器做了优化，省去了中间的临时对象环节。和返回值优化相关有两种机制：RVO (Return Value Optimization)、NRVO (Name RVO).
 *
 *      完美转发:
 *          &是一个左值，&&不一定是右值，也可能是一个左值，取决于编译器判断。这个叫做引用折叠。
 *          引用折叠规则:
 *              X& &、X& &&、X&& &都折叠成X&
 *              X&& &&折叠为X&&
 *
 *    std::forward 在什么场景下会用？
 *      赋值给右值
 *
 *    std::forward 和 std::move的区别是什么？
 *      std::move 左值或者右值转右值
 *      std::forward 完美转发，左转发左，右转发右
 *
 */

class Data {
public:
    Data(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int x;
    int y;
};

class CA {
public:
    // 构造函数
    CA() {}

    // 析构函数
    ~CA() {}

    // 拷贝构造函数
    CA(const CA &) {}

    // 拷贝赋值函数
    CA &operator=(const CA &) {}

    // 移动构造函数
    CA(const CA &&) {}

    // 移动赋值函数
    CA &operator=(const CA &&) {}

    // 左值引用
    CA(Data &data) { cout << "CA-左值引用构造" << endl; }
    // const左值引用
    CA(const Data &data) { cout << "CA-const左值引用构造" << endl; }
    // 右值引用
    CA(Data &&data) { cout << "CA-右值引用构造" << endl; }
};

// 函数1
int &function1() {
    int res = 1;
    return res;
}

class T {
public:
    T() { cout << "create T" << endl; }
    ~T() { cout << "delete T" << endl; }
    T &operator=(const T &t) {
        cout << "create T by operator=" << endl;
        return *this;
    }
    T(const T &t) { cout << "create T by copy constructor" << endl; }
};

T f1() {  // RVO
    return T();
}

T f2() {  // NRVO
    T t;
    return t;
}

// 函数2
int plus1(int a, int b) {
    return a + b;
}

int main(int argc, const char *argv[]) {
    // leftValue是左值(左值可以取地址)  1是右值(右值不可以取地址)
    int leftValue = 1;

    // 左值引用
    int &leftRef = leftValue;

    // 左值引用 (左值引用只能指向左值，不能指向右值)
    //    int &lestRef1 = 1;    // nowork

    // 右值引用只能指向右值，不能指向左值 (引用只是一个别名，但右值也是有右值引用的)
    int &&rightRef = 1;
    //    int &&rightRef1 = leftValue;  // no work

    // std::move() 可以将值赋值给右值
    int &&rightRef2 = std::move(leftValue);

    // std::forward() 可以将右值赋值给左值
    // forward
    // 用于完美转发的，它会将输入的参数原封不动地传递到下一个函数中，这个“原封不动”指的是，如果输入的参数是左值，那么传递给下一个函数的参数的也是左值；如果输入的参数是右值，那么传递给下一个函数的参数的也是右值。
    int   value2 = std::forward<int>(1);              // 常量转发
    int &&rightRef4 = std::forward<int &&>(1);        // 右值转发
    int & leftRef3 = std::forward<int &>(leftValue);  // 左值转发

    // 因为返回一个类型的引用，因此是一个左值
    function1();

    // 下列函数为右值
    // 1. 不可以取地址 2. 不可修改
    int c = plus1(1, 2);  // plus1(1, 2) 无名字， 不可修改(plus1(1, 2) = 10)

    /**
     * 探讨右值引用的应用场景
     */
    Data       data(1, 2);   // 左值引用
    const Data data1(2, 3);  // const 左值引用

    /**
     * std::forward的引用原理
     * 当输入为左值, 输出为左值
     * forward(typename remove_reference<_Tp>::type& __t)
     * return static_cast<_Tp&&>(__t);
     *
     * 当输入为右值，输出为右值
     * forward(typename remove_reference<_Tp>::type&& __t)
     * return static_cast<_Tp&&>(__t);
     */
    Data &&data2 = std::forward<Data &&>(Data(1, 3));  // 右值引用 &&不一定就确定是右值，也可能是左值，取决于编译器判断。

    CA ca(data);
    CA ca1(data1);
    CA ca2(data2);            // 为什么不是调用右值构造？？？ 其实是引用折叠
    CA ca5(std::move(data));  // 为什么不是调用右值构造？？？ 其实是引用折叠

    /**
     * std::move的引用原理
     * typename remove_reference<_Tp>::type&&  move(_Tp&& __t) move函数的参数T&&是一个指向模板类型参数的右值引用;
     * 通过引用折叠，此参数可以和任何类型的实参匹配，因此move既可以传递一个左值，也可以传递一个右值；
     * 如果传入 && ==》move(_Tp&& __t) ==》&& && 引用折叠成 &&, 传入右值
     * 如果传入 &  ==> move(_Tp&& __t) ==》& && 引用折叠成 &, 传入左值
     * return static_cast<_Up&&>(__t); // 返回一个右值
     */
    CA ca3(std::move(data));  // move 强制将左值转换为右值，传递给方法后就可以直接当作右值引用

    std::vector<Data> vec;

    /**
     * vector<_Tp, _Allocator>::push_back(const_reference __x)
     * vector<_Tp, _Allocator>::__push_back_slow_path(_Up&& __x)
     * __alloc_traits::construct(__a, _VSTD::__to_address(__v.__end_), _VSTD::forward<_Up>(__x));
     */
    vec.push_back(data);

    /**
     * vector<_Tp, _Allocator>::emplace_back(_Args&&... __args)
     * __emplace_back_slow_path(_VSTD::forward<_Args>(__args)...);
     * __alloc_traits::construct(__a, _VSTD::__to_address(__v.__end_), _VSTD::forward<_Args>(__args)...);
     * 关于_VSTD::forward<_Args>(__args)...
     * 输入参数的类型是Args&&...
     * 1. 需要保留输入参数的右值属性，因此Args后面需要跟上&&
     * 2. std::forward的模板参数必须是<Args>，而不能是<Args...>，这是由于我们不能对Args进行解包之后传递给std::forward，而解包的过程必须在调用std::forward之后
     */
    vec.emplace_back(data);

    /**
     * 返回值优化
     * 结论 : 不论返回左值或者右值，都没有进行拷贝赋值的操作，因此确定是做了返回值优化的。
     * 有一种可能是优化了函数的表现形式，将返回型的函数变成void型的函数，通过引用来修改。
     */
    T t1 = f1();
    T t2 = f2();

    return 0;
}
