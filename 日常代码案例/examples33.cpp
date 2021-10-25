// sort algorithm example
#include <algorithm> // std::sort
#include <fstream>
#include <iostream> // std::cout
#include <list>
#include <map>
#include <string>
#include <vector> // std::vector

/*
 *  char 不能赋值给string ????
 */

using namespace std;
int main() {
  char c1[256] = "12345";
  printf("%s\n", c1);

  string s1 = c1;
  printf("%s\n", s1.c_str());
  return 0;
}