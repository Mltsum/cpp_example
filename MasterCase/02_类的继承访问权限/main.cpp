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


int main(int argc, const char* argv[]) {
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

    return 0;
}
