#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include <list>
#include <array>

/*
 * 功能：
 *  1) 当父类中有纯虚函数时，子类必须实现此纯虚函数，才能进行类的实例化；
 *  2) 当父类中有虚函数时，子类可以覆盖此虚函数(声明前记得加virtual, 实现前可不加)；
 *  3) 类可以多重继承，继承后依然可以用父类的函数；
 *  4) 如果想直接用父类的函数时，直接用就行了，不需要在子类中定义；
 */
using namespace std;

class A{
public:
    virtual void run(){
        cout << "A::run()" << endl;
    }
    virtual void running() = 0;
};

class B: public A{
public:
    virtual void run(){
        cout << "B::run()" << endl;
    }
    virtual void running(){
        cout << "B::running()" << endl;
    }
};

class C: public B{
public:
    virtual void run(){
        cout << "B::run()" << endl;
    }
    virtual void running(){
        cout << "C::running()" << endl;
    }
};

using namespace std;


int main() {
    /*
     * 抽象类不能实例化
     */
    B *b = new B();
    b->running();

    C *c = new C();
    c->running();

    return 0;
}
