#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/*
 *  当类作为属性时，
 *  如果直接实例出对象，则在base类构造之前会执行构造，则在base类析构之后会执行析构
 *  如果用对象的指针，则需要在构造函数中申请内存，在析构函数中释放内存
 */

using namespace std;

class classA {
public:
  classA() { cout << "this is classA cons" << endl; }
  ~classA() { cout << "this is classA decons" << endl; }
};

class classB {
public:
  classB() { cout << "this is classB cons" << endl; }
  ~classB() { cout << "this is classB decons" << endl; }
};

class base {
public:
  base() {
    cout << "this is base cons" << endl;
    clsb = new classB();
  }
  ~base() {
    cout << "this is base decons" << endl;
    delete clsb;
  }

private:
  classA clsa; // 属性的构造居然是在构造函数之前？？？
  classB *clsb;
};

int main() {
  base *bs = new base();

  delete bs; // base类在析构时会自动将属性的类释放掉
  return 0;
}