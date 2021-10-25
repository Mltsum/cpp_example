#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  文件按行读出
 */

using namespace  std;

//bool elementInVector(std::vector<int> &fv, float fc) {
//    bool  res = false;
//    for (auto f : fv) {
//        cout << f << endl;
//        if (f == fc){
//            res = true;
//            break;
//        }
//    }
//    return res;
//}
class A{
public:
    void loadNum(){
        int a = 1, b = 2, c = 3;
        m_a = a;
        m_b = b;
        m_c = c;

    }

public:         // 注意：private的参数对外是不可见的，除非写函数get;
    int m_a;
    int m_b;
    int m_c;
};

void func(A &ca){
    ca.loadNum();
    cout << "func" << ca.m_a << endl;

}

int main () {
//    float a = 1;
//    vector<int> v = {2, 3, 4};
//    cout << elementInVector(v,a) << endl;

    A ta;
    ta.loadNum();
    cout << "main" << ta.m_a << endl;

    func(ta);

    return 0;
}