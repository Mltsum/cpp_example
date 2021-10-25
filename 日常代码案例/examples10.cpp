#include <iostream>
#include <array>
#include <memory>

/*
 *  1. std::pair 是类模板，提供在一个单元存储两个相异类型对象的途径。
 *      使用 :
 *          1) pair是将2个数据组合成一个数据，当需要这样的需求时就可以使用pair，如stl中的map就是将key和value放在一起来保存。
 *          2) 当一个函数需要返回2个数据的时候，可以选择pair。
 *
 */

using namespace std;


// 程序的主函数
int main( )
{
    /*
     * pair的使用
     */
    std::pair<int, float> p1(2, 2.1);
    cout << "p1.first : " << p1.first << " p1.second : " << p1.second << endl;
    std::make_pair(3, 3.1);

    return 0;
}