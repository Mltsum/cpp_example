// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  遍历map
 */

using namespace  std;
int main () {
    /*
     * 注意 : str->size() str->size() 指的是第一个字符串的长度。注意呀
     * 注意字符串数组的使用
     */
    string str[]  = {"ab", "b", "c", "d", "e"};
    map<int, string> mapV;
    cout <<  str->length() << endl;

    for (int i = 0; i < 5; ++i) {
        mapV.insert(mapV.end(), pair<int,string>(i, str[i]));
    }

    /*
     * map的遍历
     */
    for(auto it = mapV.begin(); it != mapV.end(); it++){
        cout << it->first << endl;
        cout << it->second << endl;
    }

    return 0;
}