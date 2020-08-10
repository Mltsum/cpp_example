//
// Created by mingren.ms on 2020/8/4.
//
#include <fstream>
#include <iostream>
#include <string>
/*
 * 字符串的compare?
 *    相等则返回0， 不相等则返回-1
 */
using namespace std;
int main() {
  string str1 = "eye";
  string str2 = "jdt";
  string str3 = "red_blue";
  cout << str1.compare(str2) << endl;  // -1
  cout << str1.compare("eye") << endl; // 0

  if (str1.compare(str2)) { // equ?
    cout << "equ" << endl;
  } else {
    cout << "not equ" << endl;
  }
  return 0;
}
