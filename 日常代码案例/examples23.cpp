// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  vector可以封装pair吗？
 */
#define LENTH 10

using namespace  std;
int main () {

  vector<pair<int, float>> v;

  v.push_back(pair<int, float>(1, 0.1));
  v.push_back(pair<int, float>(2, 0.2));

  cout << "v[0].first" << v[0].first << endl;
  cout << "v[0].second" << v[0].second << endl;

  cout << "v[1].first" << v[1].first << endl;
  cout << "v[1].second" << v[1].second << endl;






    return 0;
}