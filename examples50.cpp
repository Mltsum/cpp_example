#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
 *  public 类外也可以访问
 */

using namespace std;

namespace MNN {
class MNN_ {
public:
  void func1() { cout << "hello" << endl; };
};
} // namespace MNN

// 类名和命名空间名 不能并行起相同的名字，否则会被认为重定义。
// class MNN {
// public:
//  void func1() { cout << "hello" << endl; };
//};

int main() {
  MNN::MNN_ *mnn = new MNN::MNN_();
  mnn->func1();

  return 0;
}