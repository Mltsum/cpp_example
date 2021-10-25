#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>
#include <array>
#include <memory>

/*
 *  智能指针申请一段内存
 *
 */

using namespace  std;



int main () {
    std::unique_ptr<string> up1(new string("mingren"));
    std::unique_ptr<int[]> up2(new int[10]);

    cout << *up1 << endl;

    for (int i = 0; i < 10; ++i) {
        up2[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        cout << up2[i] << endl;
    }


    return 0;
}