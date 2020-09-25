#include "main.h"
#include <algorithm> // std::sort
#include <fstream>
#include <iostream> // std::cout
#include <list>
#include <map>
#include <string>
#include <vector> // std::vector

/*
 *  如果include重复包含的情况，会出现包含有问题。
 *      比如a.h 包含了b.h,  b.h 也包含了a.h。
 * 就会出现在a.h中引用b.h有问题的情况。 注意要避免这种情况
 *
 */
using namespace std;
class Base {
public:
  Base() {
    //  a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << "构造";
  }

private:
  int a[3][4]; // 初始化{{}, {}}没问题，但是声明和赋值分开就不太好了
};

namespace MNN_USER {
class Base1 {
public:
  Base1(int a) { cout << a << endl; }
};
} // namespace MNN_USER

using namespace std;
int main() {
  std::vector<Base> v;
  std::vector<MNN_USER::Base1> v1; // 即便构造需要传入参数也可以这样声明
  return 0;
}