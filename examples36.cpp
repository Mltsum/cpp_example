#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>
#include <array>

/*
 *  二维数组的初始化
 */

template <typename T> int valueToIdx(std::vector<T> v, T c) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == c) {
            return i;
        }
    }
    return -1;
}

using namespace  std;
int main () {
//    std::array<std::array<float, 2>, 2> arr = {{1,1}, {2,2}}; //震惊！方括号居然不行。
    std::array<std::array<float, 2>, 2> arr2 = {(1,1),(2,2)};
    std::array<int, 2> arr1 {1,2};



    return 0;
}