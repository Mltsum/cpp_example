#include <iostream>
#include <vector>

using namespace std;

/*
 * 将一段内存写到文件
 */

class base1 {
public:
  base1() { cout << "base1 cons" << endl; }
  ~base1() { cout << "base1 decons" << endl; }
};

class base {
public:
  base() { cout << "base cons" << endl; }
  ~base() { cout << "base decons" << endl; }

private:
  base1 bs1;
};

int main() {
  auto bs = new base();
  // ...

  delete bs;
  return 0;
}