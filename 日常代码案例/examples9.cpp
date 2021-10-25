#include <iostream>
#include <array>
#include <memory>

/*
 *  1. c++ 中成员函数后加const：
 *  成员函数中，常常有一些成员函数不改变类的数据成员，也就是说，这些成员方法对成员属性“只读不写”，而有一些方法要修改类数据成员的值，即“即读又写”。
 *  如果把不改变数据成员的函数都加上const关键字进行标识，显然，可提高程序的可读性。
 *  其次，它还能提高程序的可靠性，已定义成const的成员函数，一旦企图修改数据成员的值，则编译器按错误处理。
 *
 */

using namespace std;

class CLASS{
public:
    void setDataValue(int data){
        m_data = data;
    }

    /*
     * const的成员方法，修改对类属性的修改是只读不写的，如果写，会产生error
     */
//    void setDataValue1(int data) const{
//        m_data = data;
//    }

public:
    int m_data;
};




// 程序的主函数
int main( )
{
    CLASS aClass;
    aClass.setDataValue(5);
    cout << aClass.m_data << endl;

    return 0;
}