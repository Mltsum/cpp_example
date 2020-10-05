#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
 *  public 类外也可以访问
 */

using namespace std;

class Gbvar {
public:
  Gbvar(int a, int b, int c) {
    gba = a;
    gbb = b;
    gbc = c;
  }

public:
  int gbc;

private:
  int gba;
  int gbb;
};

int main() {

  Gbvar gb_var(1, 2, 3);
  cout << gb_var.gbc << endl;
  return 0;
}