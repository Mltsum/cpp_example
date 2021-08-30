#include <iostream>
using namespace std;

/**
 *  StackOverflowError
 *      1. 内存申请过大
 *      2. 调用层级太深
 *
 */

#define RANGE (1024 * 1024 * 2)

int main(int argc, const char *argv[]) {
    /**
     * 尝试栈上申请大于1M的内存，会出现什么情况?
     * 结论: 会导致结果
     */
    int a[RANGE];  // 在栈上申请过大的内存本身就会越界，导致Segmentation fault  // (1024 * 1024 * 2)
                   //    a[1024 * 1024 - 1] = 1000;
    a[RANGE - 1] = 1000;
    std::cout << a[RANGE - 1] << std::endl;

    return 0;
}
