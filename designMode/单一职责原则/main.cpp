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
 * 设计模式之单一职责原则(Single Responsibility Principle)
 * 定义 : 应该有且仅有一个原因引起类的变更。简单点说，一个类，最好只负责一件事，只有一个引起它变化的原因。
 *
 * 因此在框架设计前一定要画好UML类图，按照设计原则拆分类，这样设计起来是最优效率的
 */


#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 拆分类A
 */
class A {
public:
    std::string aName;
};

/**
 * 拆分类B
 */
class B {
public:
    std::string bName;
};

/**
 * C继承了A和B, 可以完成属性的合并
 *   拆分的核心是:只有一个引起它变化的原因。
 */
class C : public A, public B {
public:
    std::string cName;
};

/**
 * 组合的形式优于继承
 */
class D{
public:
    A *a;
    B *b;
    std::string dName;
};

int main(int argc, const char* argv[]) {

    C *c = new C();
    c->aName = "a";
    c->bName = "b";
    c->cName = "c";

   return 0;
}