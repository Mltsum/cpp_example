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
 *      智能指针shared_ptr的初始化和地址获取
 */

using namespace std;

class A {
public:
    A() { cout << "Student structure" << endl; }
    ~A() { cout << "Student deStructure" << endl; }

    class Aa {
    public:
        Aa() { cout << "Aa structure" << endl; }
        ~Aa() { cout << "Aa deStructure" << endl; }
    };

private:
    string x;
};

int main(int argc, const char* argv[]) {
    // 智能指针shared_ptr的初始化和地址获取
    std::shared_ptr<A::Aa> ca;
    // reset : Replaces the managed object with an object pointed to by ptr
    ca.reset(new A::Aa());

    // get : returns a pointer to the managed object
    cout << "address is :" << ca.get() << endl;
    return 0;
}
