#include <algorithm> // std::sort
#include <fstream>
#include <iostream> // std::cout
#include <list>
#include <map>
#include <string>
#include <vector> // std::vector

/*
 *  类中数据成员的声明与初始化总结
 *     1.非静态的常量数据成员不能在类内初始化，也不能在构造函数中初始化，而只能且必须在构造函数的初始化列表中初始化；
 */
using namespace std;
class Base {
public:
  Base(int c) : c(c) { cout << "const c:" << c << endl; };
  void func() { cout << "hello class" << endl; }

  // 记住: 涉及到static的，在类外初始化。 其他的尽量优先在初始化列表中初始化。

private:
  // 静态常量数据成员可以在类内初始化(即类内声明的同时初始化)，也可以在类外，即类的实现文件中初始化，不能在构造函数中初始化，也不能在构造函数的初始化列表中初始化；
  static const int a = 10;

  // 静态非常量数据成员只能在类外，即类的实现文件中初始化，也不能在构造函数中初始化，不能在构造函数的初始化列表中初始化；
  static int b;

  // 非静态的常量数据成员不能在类内初始化，也不能在构造函数中初始化，而只能且必须在构造函数的初始化列表中初始化；
  // 原因是const 的数据不能显式的修改，只能通过初始化列表进行初始化
  const int c;

  // 引用 也只能在构造函数中初始化列表中初始化。
  int &e;

  // 非静态的非常量数据成员不能在类内初始化，可以在构造函数中初始化，也可以在构造函数的初始化列表中初始化；
  int d;
};

using namespace std;
int main() {

  Base *base = new Base(5);
  base->func();

  return 0;
}