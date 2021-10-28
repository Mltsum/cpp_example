#include "Person.h"
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

/**
 * static 的值必须在类内声明，类外定义，并赋值初始值
 */

int main(int argc, char* argv[]) {
    std::cout << ups::Person::x;
    return 0;
}
