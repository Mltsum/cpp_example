#ifndef __UTILS_H__
#define __UTILS_H__

#include <iosfwd>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Utils {
public:
    static Utils* getIns() {
        if (uts == NULL) {
            uts = new Utils();
        }
        return uts;
    }
    uint64_t stringtolong(std::string str) {
        uint64_t          result;
        std::stringstream ss;
        ss << str;
        ss >> result;
        return result;
    }

    template <typename T>
    bool isElementInVector(T e, std::vector<T> v) {
        for (auto i : v) {
            if (i == e) {
                return true;
            }
        }
        return false;
    }

    std::vector<std::string> intersection(std::vector<std::string> v1, std::vector<std::string> v2) {
        std::vector<std::string> res_vec;
        for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
            if (find(v2.begin(), v2.end(), *iter) != v2.end()) {
                res_vec.emplace_back(*iter);
            }
        }
        return res_vec;
    }

    template <typename T, typename S>
    bool keyInMap(T key, std::map<T, S>& m) {
        bool res = false;
        for (auto ele : m) {
            if (key == ele.first) {
                res = true;
            }
        }
        return res;
    }

    /*
     * 字符串分割函数
     */
    std::vector<std::string> split(std::string str, std::string pattern);

    template <typename T>
    T abs(T& l, T& r) {
        if (l - r > 0) {
            return l - r;
        } else {
            return r - l;
        }
    }

public:
    static Utils* uts;
};
// Utils* Utils::uts = nullptr;  // 哪里用在哪里初始化
#endif