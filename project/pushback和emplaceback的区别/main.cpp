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
        persons.emplace_back(std::move(person));  // 构造+移动构造+析构。
    }

    return 0;
}
