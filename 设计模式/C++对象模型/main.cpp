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
 * 设计模式之C++对象模型
 *
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

class A{
public:
    // ...
};

// 对象模型1
class B:A{
public:
    // ...
};

// 对象模型2
class C{    // 用组合代替继承
public:
    A a;         // A和C紧耦合
};

// 对象模型3
class D{
public:
    A *a;         // 组合的方式，组合指针的灵活性是最大的，指针可以实现多态。 (尽量用指针，指针表示着隔离)
};


int main(int argc, const char* argv[]) {

    std::cout << "设计模式之C++对象模型" << std::endl;
    std::cout << "继承和组合优先使用组合，组合中优先组合指针来实现隔离" << std::endl;

    return 0;
}
