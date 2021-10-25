#include <iostream>
#include <array>
#include <memory>

/*
 *  1. C++构造函数的default和delete
 *
 */

using namespace std;

class CLASS{
public:
    /*
     * 表示删除默认构造函数
     */
//    CLASS() = delete;
    /*
     * 表示默认存在构造函数
     */
    CLASS() = default;
    /*
     * 表示删除默认拷贝构造函数，即不能进行默认拷贝
     */
    CLASS(const CLASS&) = delete;

private:

};

// 程序的主函数
int main( )
{
    CLASS aClass;       // 'CLASS' has been explicitly marked deleted here


    return 0;
}