#include <iostream>

using namespace std;

/*
 * 1. free()时:segmentation fault when free() is used
 */

int main() {

  char *p;
  char a[50] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  p = (char *)malloc(50 * sizeof(char));

  if (!p) {
    cout << "Allocation Failure";
    cout << "\n";
  } else {
    cout << "Allocation Success";
    cout << "\n";
    p = a; // 1.此时p的地址其实是a的地址，free会失败。
           // 2.会造成p的内存malloc内存泄漏。
           // 3.应该用memory copy
    cout << p;
    cout << "\n";
    free(p);
  }

  return 0;
}