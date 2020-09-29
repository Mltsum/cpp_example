#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
 *  字符串，任意长度的空格字符分隔计算
 */

using namespace std;
void split(const string &s, vector<string> &sv) {
  string v;
  char emp = ' ';
  int idx = 0;
  for (auto c : s) {
    cout << c << endl;
    idx++;
    if (c != emp) {
      v.push_back(c);
    }
    if ((c == emp || idx == s.size()) && !v.empty()) {
      sv.push_back(v);
      v.clear();
    }
  }
}

int main() {
  string s("  123 456       79 99    w9 9w9w  ");
  vector<string> sv;
  split(s, sv);
  for (const auto &s : sv) {
    cout << s << endl;
  }
  return 0;
}