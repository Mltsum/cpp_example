#include <dirent.h>
#include <math.h>
#include <string.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <tuple>
#include <vector>
#include "float.h"

using namespace std;

/**
 * 关于C++的push_back 和 emplace_back的区别
 *
 *
 */

class Person {
public:
    Person(int age) : _age(age) { cout << "Construct a person." << _age << endl; }

    Person(const Person &p) : _age(p._age) { cout << "Copy-Construct" << _age << endl; }

    // noexcept是C++11引入的,表明函数是否会抛出异常
    Person(const Person &&p) noexcept : _age(p._age) { cout << "Move-Construct" << _age << endl; }

private:
    int _age;
};

int main(int argc, const char *argv[]) {
    //    Construct a person.0
    //    Copy-Construct0
    std::vector<Person> persons;
    for (int i = 0; i < 1; ++i) {
        Person person(i);
        // __push_back_slow_path(__x);
        // __alloc_traits::construct(__a, _VSTD::__to_address(__v.__end_), _VSTD::forward<_Up>(__x));
        persons.push_back(person);
    }

    cout << "-------------" << endl;
    //    Construct a person.1
    persons.clear();
    for (int i = 0; i < 1; ++i) {
        // __emplace_back_slow_path(_VSTD::forward<_Args>(__args)...);
        // __alloc_traits::construct(__a, _VSTD::__to_address(__v.__end_), _VSTD::forward<_Args>(__args)...);
        persons.emplace_back(1);  // 节省了拷贝构造的过程
    }

    cout << "-------------" << endl;
    //    Construct a person.0
    //    Copy-Construct0
    persons.clear();
    for (int i = 0; i < 1; ++i) {
        Person person(i);
        persons.emplace_back(person);  // 构造+拷贝构造。 和push_back相同
    }

    cout << "-------------" << endl;
    //    Construct a person.0
    //    Move-Construct0
    persons.clear();
    for (int i = 0; i < 1; ++i) {
        Person person(i);
        // std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝。
        // 通过std::move，可以避免不必要的拷贝操作。
        // std::move是为性能而生。
        // std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝。
        // 右值引用（及其支持的Move语意和完美转发）是C++0x加入的最重大语言特性之一。从实践角度讲，它能够完美解决C++中长久以来为人所诟病的临时对象效率问题。
        persons.emplace_back(std::move(person));  // 构造+移动构造+析构。
    }

    /**
     * 左值和右值的概念
        左值是可以放在赋值号左边可以被赋值的值；左值必须要在内存中有实体；
        右值当在赋值号右边取出值赋给其他变量的值；右值可以在内存也可以在CPU寄存器。
        一个对象被用作右值时，使用的是它的内容(值)，被当作左值时，使用的是它的地址。
        左值：指表达式结束后依然存在的持久对象，可以取地址，具名变量或对象 。
        右值：表达式结束后就不再存在的临时对象，不可以取地址，没有名字。

        右值引用（及其支持的Move语意和完美转发）是C++0x加入的最重大语言特性之一。从实践角度讲，它能够完美解决C++中长久以来为人所诟病的临时对象效率问题。从语言本身讲，它健全了C++中的引用类型在左值右值方面的缺陷。从库设计者的角度讲，它给库设计者又带来了一把利器。从库使用者的角度讲，不动一兵一卒便可以获得“免费的”效率提升。
     */
    return 0;
}
