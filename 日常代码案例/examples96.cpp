#include <dirent.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <thread>

using namespace std;
using namespace Eigen;

/*
 *  本文要解答的是:
 *  1. 为什么声明为private或者protected的构造函数, 不能在std::make_shared<Foo>(i)中实现呢
 *      因为std::make_shared<Foo>(i)
 * 其实构造函数不是在本类中实现，而是在make_shared中实现。因此如果声明为private或者protected时会导致编译错误。
 */

using namespace std;

#include <iostream>
#include <memory>
#include <vector>

class Foo;
Foo* getInstancdFoo();
class Foo {
public:
    static std::shared_ptr<Foo> getFoo(int i) {
        shared_ptr<Foo> foo;
        Foo*            foo1 = getInstancdFoo();
        //        foo = std::make_shared<Foo>(i);       // 这样不行，非本类中构造
        //        foo = std::shared_ptr<Foo>(new Foo(i));  // 这样是可以的，在本类中构造
        return foo;
    }

public:
    Foo(int i) {
        std::cout << "foo:" << i << std::endl;
        cout << __FUNCTION__ << endl;
    }
};

Foo* getInstancdFoo() {
    return new Foo(1);
}

int main(int argc, const char* argv[]) {
    auto foo = Foo::getFoo(10);

    //    auto foo1 = Foo1::getFoo(11);
}
