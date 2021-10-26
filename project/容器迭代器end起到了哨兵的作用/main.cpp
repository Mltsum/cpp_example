#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

/**
 * 容器的end()方法，返回一个迭代器，需要注意：这个迭代器不指向实际的元素，而是表示末端元素的下一个元素，这个迭代器起一个哨兵的作用，表示已经处理完所有的元素。
 * 因此，在查找的时候，返回的迭代器，不等于end()，说明找到了目标。等于end()，说明检查了所有元素，没有找到目标。
 */

#define PL cout << __LINE__ << endl

class X {
public:
    int ele;
};

int main(int argc, char* argv[]) {
    X x1;
    x1.ele = 1;

    X x2;
    x2.ele = 2;

    X x3;
    x3.ele = 3;

    std::vector<X> a {x1, x2, x3};

    auto x = a.end()->ele;
    auto s = a.begin()->ele;
    auto e1 = (a.end() - 1)->ele;

    // 容器的迭代器使用
    std::vector<X>::const_iterator iterator;
    for (iterator = a.begin(); iterator != a.end(); iterator++) {
        std::cout << iterator->ele << std::endl;
    }
    return 0;
}
