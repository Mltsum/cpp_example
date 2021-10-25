#include <dirent.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <thread>

using namespace std;
using namespace Eigen;

/*
 * sprintf 会覆盖
 */

/*
 * 带有类模版的类，在实例化时，必须指定类型
 *
 */

int main() {
    char sql[512] = {0};
    sprintf(sql, "aaa");
    sprintf(sql, "bbb");
    printf("%s", sql);
    return 0;
}
