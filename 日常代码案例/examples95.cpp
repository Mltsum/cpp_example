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
 * 两个类中，回调实现的通信
 */

using namespace std;

class B {
public:
    std::function<void(int w, int h)> callback;  // 回调在另外一个类中实现

private:
    int a;
    int b;
};

class A {
public:
    static void init(std::shared_ptr<B>& b) {  // 实现类B的回调
        b->callback = [](int w, int h) {
            cout << "b->callback" << endl;
            cout << w << "-" << h << endl;
        };
    }
    std::shared_ptr<B> b;

    int getW() { return w; }

    int getH() { return h; }

private:
    int w = 10;
    int h = 20;
};

int main() {
    cout << "==>enter..." << endl;
    A a;
    a.b = std::make_shared<B>();

    a.init(a.b);

    if (a.b->callback) {  // 判断回调是否实现
        a.b->callback(a.getW(), a.getH());
    }
    cout << "==>exit..." << endl;
    return 0;
}
