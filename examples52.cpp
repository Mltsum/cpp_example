#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/*
 *  cpp 能否用默认形参？？？ 当然可以
 */

using namespace std;

void func1(int v1, int v2 = 1, int v3 = 2) {
  cout << v1 << endl;
  cout << v2 << endl;
  cout << v3 << endl;
}

int main() {
  func1(0); // 默认参数可以不传入，采用默认值
  cout << "======" << endl;
  func1(0, 1, 2); // 默认参数可以传入
  cout << "======" << endl;
  func1(0, 1, 3); // 默认参数不传入时为默认值，传入时为传入值

  return 0;
}