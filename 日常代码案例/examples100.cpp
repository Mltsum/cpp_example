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
 * 关于基类和派生类的函数参数传递
 *     基类 =》 派生类
 *          其实是基类的指针强转成派生类的指针，此时如果函数中派生类用了基类没有的属性或者方法，则会出现问题。
 *          此时可以进行指针的转换。static_cast(没有运行时类型检查来保证转换的安全性) 和 dynamic_cast(行时类型检查来保证转换的安全性)
 *
 *     派生类 =》 基类
 *          其实是派生类的指针强转成基类的指针，此时如果函数中只会用基类的函数和属性，基类的函数和属性在派生类中都有，因此不会出现问题。
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

class A{
public:
    A(){
        cout << "AAA" << endl;
    }
};

class Aa : public A{
public:
    Aa(){
        cout << "Aa" << endl;
    }
};

class C{
public:
    C(A* a){
        cout << "CCC" << endl;
    }
};


class D{
public:
    D(Aa* aa){
        cout << "DDD" << endl;
    }
};

int main(int argc, const char* argv[]) {

    A *a = new A();
    Aa *aa = new Aa() ;

    /**
     * 派生类 =》 基类是可以的
     */
    C *c = new C(aa);

    /**
     * 基类 =》 派生类 不行, 如需转，则需要显式的转换
     */
//    D *d = new D(a);    // no work

    return 0;
}
