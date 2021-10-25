#include <iostream>
#include <array>
#include <vector>
#include <memory>

/*
 *  1. i++和++i
 */

using namespace std;


// 程序的主函数
int main( )
{
    /*
     * 0 1 2 3 4
     */
    for (int i = 0; i < 5; ++i) {
        cout << i << " ";
    }
    cout << " " << endl;

    /*
     * 0 1 2 3 4
     */
    for (int j = 0; j < 5; j++) {
        cout << j << " ";
    }

    return 0;
}