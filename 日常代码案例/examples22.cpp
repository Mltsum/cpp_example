// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  变长数组
 */
#define LENTH 10

using namespace  std;
int main () {

    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    cout << vec.size() << endl;

    /*
     * 不能用变量
     */
//    const static int siz = vec.size();
//    float matrix[siz][2];

    /*
     * 定长是可以的
     */
//    float matrix[LENTH][2];


    /*
     * 解决方法是用vector
     */
    int m = 5;
    int n = 6;
    /*
     * 用变量声明5行
     */
    vector<vector<float>> matrix(m);
    for (int i = 0; i < matrix.size(); ++i) {
        /*
         * 5行6列
         */
        matrix[i].resize(n);
    }
    cout << matrix.size() << endl;
    cout << matrix[0].size() << endl;
    for (int j = 0; j < matrix.size(); ++j) {
        for (int i = 0; i < matrix[0].size(); ++i) {
            matrix[j][i] = j+i;
        }
    }







    return 0;
}