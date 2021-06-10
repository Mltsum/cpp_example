#include <dirent.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <thread>
#include <string>
#include <vector>
#include <functional>
#include <tuple>

using namespace std;
using namespace Eigen;

/*
 *  c++ function
 */

using namespace std;


int main(int argc, const char* argv[]) {

    char a[1520640] = "11111";
    char b[1769472] = "ccccccccc";

//    memcpy(b,a,100);  // ok
//    memcpy(b,a,200);  // ok
    memcpy(b,a,1769472);  // 不行，越界


//    memcpy(b,a,21);

    return 0;
}
