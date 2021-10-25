#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>
#include <array>
#include <memory>

/*
 *  类中的变量是否都需要初始化？(可以不初始化，int 默认为0,  string 为空)
 *
 *  构造函数参数错误（或者类中属性的类构造函数实现有问题），会出现上述问题。call to deleted constructor of std::istream
 *
 */

using namespace  std;

class Base{
    Base(int a, int b){
        m_c = a + b;
    }

private:
    int m_c;
};

class A{
public:
    int m_a;
    string str;
    Base base;
};


int main () {
    A *a = new A();


    return 0;
}