#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include "unistd.h"
using namespace std;

/**
 *  利用绑定函数来定义回掉
 *      1. 定义一个回调类型，方便在函数定义时使用
 *      2. 定义一个待绑定函数
 *      3. 绑定函数和回掉函数，std::bind(delay, std::placeholders::_1)
 *      4. 执行回调用
 */

// 定义一个回调类型，方便在函数定义时使用
typedef std::function<void(int)> Delay_callback;

// 定义一个待绑定函数
void delay(int sec) {
    std::cout << "sec:" << sec << std::endl;
    sleep(sec);
}

class Example {
public:
    void function(Delay_callback callback) {
        std::cout << "call function:" << std::endl;
        // 执行回调
        callback(1);
    }

public:
    int ele;
};

int main(int argc, char *argv[]) {
    Example ex;
    // 利用std::bind绑定现有的函数，将现有函数绑定到回掉函数中
    ex.function(std::bind(delay, std::placeholders::_1));
    return 0;
}
