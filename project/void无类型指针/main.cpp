#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 *  void * 为"无类型指针"
 *      1. void 指针可以指向任意类型的数据，就是说可以用任意类型的指针对 void 指针对 void 指针赋值。
 *      2. 内存分配函数 malloc 函数返回的指针就是 void * 型，用户在使用这个指针的时候，要进行强制类型转换，也就是显式说明该指针指向的内存中是存放的什么类型的数据 (int *)malloc(1024) 表示强制规定 malloc 返回的 void* 指针指向的内存中存放的是一个个的 int 型数据。
 *
 */

int main(int argc, const char *argv[]) {
    const void *bytes;
    float *     ptr = new float[10];
    ptr[0] = 100;

    bytes = (const void *)ptr;

    //    float value = ((float *)bytes)[0];

    return 0;
}
