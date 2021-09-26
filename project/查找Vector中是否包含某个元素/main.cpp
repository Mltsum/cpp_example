#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 *  在vector中查找某个元素是否存在
 */

#define PL cout << __LINE__ << endl

int main(int argc, const char *argv[]) {
    vector<int> v {4, 7, 9, 1, 2, 5, 2, 2};
    int         key = 2;
    auto        x = std::count(v.begin(), v.end(), key);
    if (std::count(v.begin(), v.end(), key)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element NOT found" << endl;
    }

    return 0;
}
