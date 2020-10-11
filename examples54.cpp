#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/*
 *  判断元素是否在set内部
 */

using namespace std;

int main() {
  set<int> s{1, 2, 3, 4, 5, 6, 7, 8};

  for (auto i : s) {
    cout << i << endl;
  }

  if (s.find(7) == s.end()) {
    cout << "无交集" << endl;
  }

  return 0;
}