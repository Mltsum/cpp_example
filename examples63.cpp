#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

/**
 * 类内函数调用时，是否用静态函数的问题
 */

using namespace std;

bool split(const std::string &str, const std::string &delim, std::vector<std::string> &res) {
    if ("" == str) {
        return false;
    }
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        string s = p;      //分割得到的字符串转换为string类型
        res.push_back(s);  //存入结果数组
        p = strtok(NULL, d);
    }
    return true;
}

//字符串分割函数
std::vector<std::string> split(std::string str, std::string pattern) {
    std::string::size_type   pos;
    std::vector<std::string> result;
    str += pattern;  //扩展字符串以方便操作
    int size = str.size();
    for (int i = 0; i < size; i++) {
        pos = str.find(pattern, i);
        if (pos < size) {
            std::string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}

/**
 * 检查sort 的比较函数，如果返回空
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    string                   address = "socol-test.t3go.cn:8090--gaode_smartva:Q1G6rNkUzA7iT1IZxE";
    std::vector<std::string> res;
    //    auto                     flag = split(address, "--", res);

    res = split(address, "--");
    if (res.size() > 0) {
        std::cout << res.size() << std::endl;
        std::cout << res[0] << std::endl;
        std::cout << res[1] << std::endl;
        std::cout << res[2] << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}