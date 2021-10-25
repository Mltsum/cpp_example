#include <iostream>
#include <array>
#include <memory>

/*
 *  1. 尽量以const enum inline 替换#define
 *      原因是#define是预处理器做的事情，而该命名对编译器并不可见。当使用别人的代码出现错误时，并不会出现#define的名称，而是其值，可能会增加解决问题的时间成本
 *
 *
 */

using namespace std;

/*
 * const 代替#define
 *      作为一个语言常量，const肯定会进入记号表。
 *      注意：1）常量通常定义在头文件中，以方便被不同的源码包含，  2)如果此常量要声明在类中，为了确保此常量只有一份实体，需声明为static
 */
#define MICRO_VAR 100
const int microVar = 100;

class Box{
public:
    /*
     * 设定一个常量，不用define并且保证只有一个实体，声明为static
     */
    const static int microVar1 = 101;
};



// 程序的主函数
int main( )
{
    Box *box = new Box();
    cout << box->microVar1 << endl;


    return 0;
}