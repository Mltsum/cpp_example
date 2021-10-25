#include <math.h>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

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


**********************************************/

// 单例模式的两种方式。

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    bool isElementInVector(int e, std::vector<int> v) { return true; }
};

class Utils {
public:
    Utils() {}
    // 静态成员函数的意义在于管理静态成员变量，完成对静态成员变量的封装。可以访问静态成员，也可以访问非静态成员。
    static Utils* getIns() {
        if (ins == NULL) {
            ins = new Utils();
        }
        return ins;
    }
    //    bool isElementInVector(int e, std::vector<int> v) { return true; }

    /*
     * 类的方法可以使用模版吗?
     *     可以
     * 类中的方法，声明和实现如何使用模版关联？
     *     正常实现即可。实现其实是用Utils::定义了域
     */
    template <typename T>
    bool isElementInVector(T e, std::vector<T> v);

public:
    static Utils* ins;
    int           var;
};
// 全局的静态变量，必须在类外进行初始化。
Utils* Utils::ins = nullptr;  // 类的静态变量可以通过类对象来访问，也可以通过类名直接访问。
// int    Utils::var = 1;        // 非静态成员不能用类名访问，静态可以访问是为了类外的初始化。

template <typename T>
bool Utils::isElementInVector(T e, std::vector<T> v) {
    //    std::vector<int>::iterator it;
    //    it = find(v.begin(), v.end(), e);
    //    if (it != v.end()) {
    //        return true;
    //    } else {
    //        return false;
    //    }
    for (auto i : v) {
        if (i == e) {
            return true;
        }
    }
    return false;
}

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
    Singleton s = Singleton::getInstance();
    s.isElementInVector(e, v);

    /**
     * 模版调用的流程:
     * 1) 编译器以这个模板为依据，将T都替换为int，生成了一个可以使用的这个真正的函数。
     *      注意:函数模板是不可以直接被调用的，调用的时候都要由编译器生成一个函数。
     * 2）
     */
    auto ins = Utils::getIns();
    auto res = ins->isElementInVector(e, v);
    std::cout << res << std::endl;

    std::string              rectId = "a";
    std::vector<std::string> fatherIds = {"a", "b"};
    auto                     res1 = Utils::getIns()->isElementInVector(rectId, fatherIds);

    std::cout << "end" << std::endl;
    return 0;
}