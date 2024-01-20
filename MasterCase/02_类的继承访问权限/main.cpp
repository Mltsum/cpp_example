#include <dirent.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <thread>
#include <string>
#include <vector>
#include <functional>
#include <tuple>
#include <string.h>

using namespace std;

/**
 * 关于类的继承
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

class Base{
public:
    int PublicBase;
    void PublicPrint() {std::cout << "PublicPrint()" << std::endl;}
protected:
    int ProtectedBase;
    void ProtectedPrint() {std::cout << "ProtectedPrint()" << std::endl;}
private:
    int PrivateBase;
    void PrivatePrint() {std::cout << "PrivatePrint()" << std::endl;}
};

class Derived : public Base{
public:
    void DerivedPrint() {
        std::cout << "DerivedPrint()" << std::endl;
        std::cout << ProtectedBase << std::endl;
        //若要访问protected的数据成员需要通过派生类里的成员函数访问
        PublicPrint();
        ProtectedPrint();
    }
};

class ProtectedBase : protected Base{
public:
    void Print() {
        std::cout << "DerivedPrint()" << std::endl;
        PublicPrint();
        ProtectedPrint();
    }
};

class PrivateBase : private Base{
public:
    void Print() {
        std::cout << "DerivedPrint()" << std::endl;
        std::cout << ProtectedBase << std::endl;
        //若要访问protected的数据成员需要通过派生类里的成员函数访问
        PublicPrint();
        ProtectedPrint();
    }
};

class C1 : PrivateBase{
public:
    void Print() {
        std::cout << "C1()" << std::endl;
        /**
         * 私有继承，会将继承的内容都放置到本派生类的private下
         */
//        std::cout << ProtectedBase << std::endl;      // no work
//        PublicPrint();
//        ProtectedPrint();
    }
};


class A{
public:
    int a = 1;

protected:
    int b = 2;

private:
    int c = 3;
};

class Aa : A {

};

class Ab : public A {

};

int main(int argc, const char* argv[]) {
    /**
     * 公有继承（public）、保护继承（protected）、私有继承（private）。对于基类中的私有成员，三种继承方式都不可见。以下三种继承是针对除私有成员外，对于公有继承，所有成员的特性不变。对于保护继承，所有成员特性变为保护方式。对于私有继承，所有成员特性变为私有方式。
     *
     *    在这里需要注意：使用关键字class时默认的继承方式是private，使用struct时默认的继承方式是public。
     */

    /**
     * 如果是public继承，则在派生类外部只能访问基类的public，在派生类的内部只能访问基类的public和protected.
     */
    Derived der;
    der.DerivedPrint();
    der.PublicBase = 1;
    der.PublicPrint();
    der.DerivedPrint();

    /**
     * 如果是Protected继承,则在派生类外部只能访问自身的public属性和方法，，在派生类的内部派生类会将所有从基类继承的成员(public和protected)全部放到protected下
     */
    ProtectedBase pb;
    pb.Print();

    /**
     * 如果是Private继承,则在派生类外部只能访问自身的public属性和方法，在派生类的内部派生类会将所有从基类继承的成员(public和protected)全部放到private下
     */
    PrivateBase prb;
    prb.Print();


    /**
     * 类的继承默认是private继承。(为什么？ 可能是为了语言的安全性吧，如果默认pub,则会带来被篡改危险，默认prv可以将篡改权给到用户)
     */
    A a;
    Aa aa;
//    std::cout << aa.c << std::endl;     // compile faild
    Ab ab;
    std::cout << ab.a << std::endl;


    /**

private成员变量：
    类内可以访问；
    实例化对象不可以访问，如果想访问，需要在类内定义可以访问的成员函数；
    派生类不可以访问；

protect成员变量：
    类内可以访问；
    实例化对象不可以访问；
    派生类类内可以访问（三种继承方式都可以在类内访问）；

public成员变量
    都可以访问；
     */
    return 0;
}
