#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/*
 *  用基类的指针实例化继承类的对象时，只能调用基类定义的函数。
 */

using namespace std;

class base {
public:
  void func1(){};
};

class base1 : public base {
public:
  void func4(){};
};

int main() {
  base *bs = new base1();
  bs->func1();
  base1 *bs1 = new base1();
  bs1->func1();
  bs1->func4();
  return 0;
}