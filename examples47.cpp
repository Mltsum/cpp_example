#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
 *  类中的函数形参，如果是const类型，是否必须传入const类型？ 答案是不需要。
 * const形参是表征此函数不会改变形参的值。
 * 如需要: 不传入会怎样？ 不传入没关系。
 * 如不需要: const的作用是什么？ 作用是表征该函数不会改变此形参的值。
 *
 *
 * int cube(int i);
 * 实参可以为int类型， 也可以为const int类型。
 * 在函数体中可以修改i的值，函数不会修改实参的值。
 *
 * int cube(const int i);
 * 实参可以为int类型， 也可以为const int类型。
 * 在函数体中不可以修改i的值， 函数不会修改实参的值。
 *
 * void print(const int &r)；
 * 实参可以为int类型， 也可以为const int类型，不可以修改r的值。
 */

using namespace std;

class ClassA {
public:
  void func1(int a) { cout << __FUNCTION__ << " " << a << endl; }
  void func2(const int a) { cout << __FUNCTION__ << " " << a << endl; }
};

int main() {
  ClassA a;
  int var1 = 1;
  a.func1(var1);
  a.func2(var1);
  return 0;
}