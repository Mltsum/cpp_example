#include <algorithm> // std::sort
#include <fstream>
#include <iostream> // std::cout
#include <list>
#include <map>
#include <string>
#include <vector> // std::vector

/*
 *  二维数组初始化不能这样，SAB了
 */
using namespace std;
class Base {
public:
  Base() {
    //  a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << "构造";
  }

private:
  int a[3][4]; // 初始化{{}, {}}没问题，但是声明和赋值分开就不太好了
};

using namespace std;
int main() {

  int c[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  return 0;
}