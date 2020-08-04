// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  清除char型数组？
 *
 */
#define LENTH 10

using namespace  std;
int main () {

    char abspath[256];
    sprintf(abspath, "this is test");

    cout << abspath << endl;

    memset(abspath, 0, sizeof(abspath));

    cout << abspath << endl;


    return 0;
}