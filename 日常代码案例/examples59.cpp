#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/*
 *  保留小数固定位数
 */

int main(int argc, char *argv[]) {
  // 保留小数固定位数

  float f = 0.1233232323232323;

  cout << setprecision(3) << f << endl;

  float f1 = ((int)(f * 100000.0)) / 100000.0;

  cout << f1 << endl;

  return 0;
}