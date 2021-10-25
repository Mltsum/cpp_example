#include <math.h>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "Utils.h"

using namespace std;

/**********************************************
单例模式可以用指针和实例两种方式实现。
    在应用这个模式时，单例对象的类必须保证只有一个实例存在。许多时候整个系统只需要拥有一个全局对象，这样有利于我们协调系统整体的行为。

静态变量和静态函数特点:
1）静态成员变量是该类的所有对象所共有的。对于普通成员变量，每个类对象都有自己的一份拷贝。而静态成员变量一共就一份，无论这个类的对象被定义了多少个，静
态成员变量只分配一次内存，由该类的所有对象共享访问。所以，静态数据成员的值对每个对象都是一样的，它的值可以更新；
2）因为静态数据成员在全局数据区分配内存，由本类的所有对象共享，所以，它不属于特定的类对象，不占用对象的内存，而是在所有对象之外开辟内存，在没有产生类
对象时其作用域就可见。因此，在没有类的实例存在时，静态成员变量就已经存在，我们就可以操作它；
3）静态成员变量存储在全局数据区。static成员变量的内存空间既不是在声明类时分配，也不是在创建对象时分配，而是在初始化时分配。静态成员变量必须初始化，
而且只能在类体外进行。否则，编译能通过，链接不能通过。
4)static成员变量和普通static变量一样，编译时在静态数据区分配内存，到程序结束时才释放。这就意味着，static成员变量不随对象的创建而分配内存，也不随对象的销毁而释放内存。而
普通成员变量在对象创建时分配内存，在对象销毁时释放内存。
5) 类的静态变量可以通过类对象来访问，也可以通过类名直接访问。

6) 要十分注意的是: 在实现模版时，定义和实现不要分开，否则会出现链接问题


**********************************************/

// 单例模式的两种方式。

// class Singleton {
// public:
//    static Singleton& getInstance() {
//        static Singleton instance;
//        return instance;
//    }
//    bool isElementInVector(int e, std::vector<int> v) { return true; }
//};

Utils* Utils::uts = nullptr;

/**
 * 检查sort 的比较函数，如果返回空
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
    int         e = 1;
    vector<int> v = {1, 2, 3, 4, 5};

    //
    //    Singleton s = Singleton::getInstance();
    //    s.isElementInVector(e, v);

    /**
     * 模版调用的流程:
     * 1) 编译器在链接时，以这个模板为依据，将T都替换为int，生成了一个可以使用的这个真正的函数。此时找到了util.h中
     *      Utils.h 再 去找实现是找不到的，因为此时已经定了形参的格式
     * 2）
     */
    auto res = Utils::getIns()->isElementInVector(1, {1, 2});
    std::cout << res << std::endl;

    std::cout << "end" << std::endl;
    return 0;
}