#include <array>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/*
 *  memccpy时，需要*dst必须记得申请内存
 *  memcpy和memccpy的区别
 */

using namespace std;

int main() {
  char *a1 = "12345";
  char *b = (char *)malloc(5 * sizeof(char));
  char *c = (char *)malloc(5 * sizeof(char));

  /*
 函数说明：memccpy() 用来拷贝src
 所指的内存内容前n个字节到dest所指的地址上。与memcpy()
 不同的是，memccpy()会在复制时检查参数c 是否出现，若是则返回dest 中值为c
 的下一个字节地址。
 返回值：返回指向dest中值为c 的下一个字节指针。返回值为0
 表示在src 所指内存前n 个字节中没有值为c的字节 memccpy(b, a1, 1, 5);
 */
  memccpy(b, a1, 1, 5);

  /*
   * memcpy() 会复制 src 所指的内存内容的前 num 个字节到 dest 所指的内存地址上。
   * memcpy()并不关心被复制的数据类型，只是逐字节地进行复制，这给函数的使用带来了很大的灵活性，可以面向任何数据类型进行复制。
   */
  memcpy(c, a1, 5);
  return 0;
}