#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  class的赋值以及vector的赋值容易踩的坑
 */

using namespace  std;
class A{
public:
    int m_a;
    float m_b;
};


int main () {

    std::map<int, std::vector<A>>  m1;
    std::map<int, std::vector<A>>  m2;

    A a1;
    a1.m_a = 1;
    a1.m_b = 1.1;
    std::vector<A> v1;
    v1.push_back(a1);
    m1[1] = v1;

    A a2;
    a2 = a1;
    v1.push_back(a2);
    m1[2] = v1;

    for (int i = 1; i < 3; ++i) {
        for (int j = 0; j < v1.size(); ++j) {
            A tmp = m1[i][j];
            m2[i].push_back(tmp);   // 注意两个vector的赋值，容易踩的坑
        }
    }

    cout << a2.m_a << a2.m_b << endl;


    return 0;
}