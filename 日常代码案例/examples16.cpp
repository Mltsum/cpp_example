// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>

/*
 * min() max() 输入输出必须一致
 *
 * round() 四舍五入
 */

using namespace  std;
int main () {

    float a = 2.3;
    float b = 1.4;
    cout << round(a) << endl;

    /*
     * min, max中，输入比较的两个数值的类型必须相同。
     */
    cout << max(round(a),(float)0) << endl;
//    cout << max(round(a),0) << endl;          // 输入类型不同，不行



  return 0;
}