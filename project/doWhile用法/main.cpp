#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 *  do while
 *
 */

int main(int argc, const char *argv[]) {
    std::vector<int> v {0, 1, 2, 3};

    do {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << endl;
        }
    } while (false);  // 不满足就跳出

    return 0;
}
