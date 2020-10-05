#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
 *  有元函数和有元类
 *      1. 有元函数和有元类其实是告诉函数或者告诉有元类中的函数，
 * 可以访问我的私有成员
 *      2. friend是不受类中的权限控制的，一般写到哪个位置都可以。
 */

using namespace std;

class ClassB;
class ClassA;
class Gbvar {
public:
  Gbvar(int a, int b) : gba(a), gbb(b) {}

  // 表示着友元函数和友元类中的函数可以随时访问本类中的所有数据成员。
  friend class ClassB;
  friend class ClassA;

private:
  int gba;
  int gbb;
};

class ClassB;
class ClassA {
public:
  friend class ClassB;
  void func1(int a) { cout << __FUNCTION__ << " " << a << endl; }
  void func2(const int a) { cout << __FUNCTION__ << " " << a << endl; }

  void setc(int z) { this->z = z; }

  void printgb(Gbvar &gb_var) {
    cout << gb_var.gba << " " << gb_var.gbb << endl;
  }

private:
  int x;
  int y;
  int z; //  公共
};

class ClassB {
public:
  //  friend class ClassA;
  void getz(ClassA &ca) { cout << ca.z << endl; }

  void printgb(Gbvar &gb_var) {
    cout << gb_var.gba << " " << gb_var.gbb << endl;
  }

private:
  int a;
  int b;
  int c;
};

int main() {

  Gbvar gb_var(111, 222);

  ClassA ca;
  ca.printgb(gb_var);
  ClassB cb;
  cb.printgb(gb_var);

  return 0;
}