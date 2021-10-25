#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/*
 * malloc 后 free 和 delete的区别
 * 从编程纪律、规则上说，是不可以。
因为new和delete 操作时, 是把对象当成一个复杂类，bai而执行对应的构造/析构函数。
 而 malloc 和 free 则不执行它们。 题目中所说的两种错配情况，
会导致不可预测的错误发生。而这种错误，在项目很大时是比较难发现的。相当于项目中埋藏的炸弹。

但是当对象是简单类型时，确实是不会出错。
 */

int main(int argc, char *argv[]) {
  cout << "start" << endl;
  char *c = (char *)malloc(10);

  c[0] = '1';
  c[1] = '2';
  c[2] = '3';

  if (c) {
    //    free(c);      // delete 和 free效果一样
    delete c;
    //    c = nullptr; // 空间释放掉，但数据和地址还在，需要指向nullptr
  }
  //  delete c;

  cout << c[0] << endl;
  cout << c[1] << endl;
  cout << c[2] << endl;
  cout << "end" << endl;
  return 0;
}