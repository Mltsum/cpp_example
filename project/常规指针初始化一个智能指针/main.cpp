#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 *  用常规指针去初始化一个智能指针，当智能指针释放时，常规指针的状态是？
 *  结论: 常规指针会释放掉！
 */

#define PL cout << __LINE__ << endl

class Xiaoming {
public:
    Xiaoming() { cout << "老子构造啦" << endl; };
    ~Xiaoming() { cout << "老子析构啦" << endl; };
    Xiaoming(const Xiaoming &) { cout << "老子拷贝构造啦" << endl; }
    Xiaoming &operator=(const Xiaoming &a) { cout << "老子赋值构造啦" << endl; };
};

int main(int argc, const char *argv[]) {
    Xiaoming *xiaoming = new Xiaoming();

    {
        PL;
        // 这行代码在堆里创建了两块内存：1.存储T。2.用于引用计数的内存，管理附加此内存的shared_ptr对象的计数，最初计数将为1.
        // 新的shared_ptr对象的最佳方法是使用std::make_shared类模板。因为 1）它一次性为T对象和用于引用计数的数据都分配了内存，而new操作符只是为T分配了内存(没理解，求高人解答)。2）它可以避免一些由堆指针或者new分配指针导致的错误。
        std::shared_ptr<Xiaoming> xiaoming1(new Xiaoming);
        PL;
    }
    {
        PL;
        std::shared_ptr<Xiaoming> xiaoming2(xiaoming);
        PL;
    }

    if (xiaoming) {
        PL;
    }

    return 0;
}
