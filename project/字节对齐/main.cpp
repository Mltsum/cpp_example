#include <dirent.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <thread>
#include <string>
#include <vector>
#include <functional>
#include <tuple>
#include <string.h>

using namespace std;

/**
 * 字节对齐
 *       #pragma pack(1) 和 #pragma pack() 成对使用
 *       pragma pack(n) 代表N字节对齐
 */

#pragma pack(1)
struct s0 {
    int i;
    char ch;
};
#pragma pack()


struct s1 {
    int i;
    char ch;
};


#pragma pack(1)
struct s2 {
    int i;
    char ch;
};
#pragma pack()

int main(int argc, const char* argv[]) {

    cout << "1:" << sizeof(s0) << endl;
    cout << "2:" << sizeof(s1) << endl;
    cout << "3:" << sizeof(s2) << endl;


    return 0;
}