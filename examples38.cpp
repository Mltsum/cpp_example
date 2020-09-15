#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>
#include <array>

/*
 *  for 循环，改变值？ 关于for(auto e : v) 是否需要用引用的问题
 *
 */

using namespace  std;

class Base{
public:
    int m_a;
};

int main () {
    std::vector<Base> v;
    Base b1;
    b1.m_a = 1;
    v.push_back(b1);

    Base b2;
    b2.m_a = 1;
    v.push_back(b2);

    Base b3;
    b3.m_a = 1;
    v.push_back(b3);

    // for循环，不用引用，写值
    for(auto e : v){
        e.m_a = 2;
    }

    // for循环，用引用，写值
    for(auto &e : v){
        e.m_a = 3;
    }


    return 0;
}