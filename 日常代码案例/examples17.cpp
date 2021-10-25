// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>

/*
 *  map的插入和find
 *      注意： map的find返回的是一个pair
 */

using namespace  std;
int main () {
    /*
     * int to string
     */


    map<string, vector<int>> mapV;
    string str1 = "1";
    string str2 = "2";
    string str3 = "3";
    vector<int> v1 = {1};
    vector<int> v2 = {1,2};
    vector<int> v3 = {1,2,3};

    /*
     * c++中容器的insert其实都是插入某个位置的
     */
    mapV.insert(mapV.end(),pair<string, vector<int>>(str1, v1));
    mapV.insert(mapV.end(),pair<string, vector<int>>(str2, v2));
    mapV.insert(mapV.end(),pair<string, vector<int>>(str3, v3));

    /*
     * map 中的find其实返回的是一个pair
     */
    auto cur = mapV.find(str3);

    vector<int> vx = cur->second;


  return 0;
}