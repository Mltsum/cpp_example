//
// Created by mingren.ms on 2020/8/4.
//
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
/*
 * 判断文件是否存在
 */
using namespace std;
int main() {
  string path = "D:\\Working_repo\\09.cpp_learning\\demo1\\r.txt";

  ifstream f(path.c_str());
  if (f.good()) {
    f.close(); // 打开后，关闭才能正常删除
    cout << "yes, delete it" << endl;
    if (remove(path.c_str()) == 0) {
      cout << "file has been deleted" << endl;
    }
  } else {
    cout << "no" << endl;
  }
  return 0;
}
