//
// Created by mingren.ms on 2020/8/4.
//
#include <future>
#include <iostream>
#include <list>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;
class B; // 前置声明
class A {
public:
  B *b;
};

class B {};
int main() { return 0; }
