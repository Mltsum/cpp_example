#include <iostream>
#include <array>
#include <vector>
#include <memory>
#include <map>
#include <utility>

/*
 *  1. Map的使用
 *      1) map如何插入元素？
 *
 */


// 程序的主函数
int main( )
{
    std::map<int, float> mapTemp;
    /*
     * insert的方式插入pair
     */
    mapTemp.insert(std::pair<int, float>(000,0.1));
    /*
     * insert的方式插入value_type数据
     */
    mapTemp.insert(std::map<int,float>::value_type(001,0.2));


    return 0;
}