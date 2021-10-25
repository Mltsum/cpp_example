// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  vector中的合并
 */

using namespace  std;
int main () {
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5,6};
    vector<int> v3;
    /*
     * 合并方式1：insert
     */
    v2.insert(v2.end(), v1.begin(), v1.end());
    for (int i = 0; i < v2.size(); ++i) {
        cout << v2[i] << endl;
    }

    /*
     * 合并方式2：merge
     *  1、vec1,和vec2需要经过排序，merge只能合并排序后的集合，不然会报错。
     *   2、vec3需要指定好大小，不然会报错。
     */
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    v3.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

    for (int i = 0; i < v3.size(); ++i) {
        cout << v3[i] << endl;
    }
    return 0;
}