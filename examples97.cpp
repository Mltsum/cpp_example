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
 *  本文要解答的是:
 *  1. shareptr 如何实现计数？
 *      A: 出现赋值或者拷贝时加1，出现智能指针的释放时减1
 *
 *  2. shareptr 如何实现多个指针共享一个对象(Several shared_ptr objects may own the same object.)？
 *      A: 通过一个对象的赋值，拷贝，实现多个智能指针指向同一个对象
 *
 *  3. shareptr 是可以拷贝和赋值的，依据是？
 *      A: 实现了拷贝构造函数，并在实现时，计数器加1
 *      A: 实现了拷贝赋值函数
 *
 *  4. 最后一个shareptr负责销毁对象，是如何实现的？
 *      A:delete 对象
 *
 *  5. 强引用和弱引用？
 *
 *  6. shared_ptr允许多个指针指向同一个对象，怎么理解？
 *
 *  7. 使用:使用模板函数 make_shared 创建对象, make_shared 需指定类型('<>'中)及参数('()'内),
 * 传递的参数必须与指定的类型的构造函数匹配
 *
 */

// 拷贝构造函数
// template<class _Tp>
// inline
// shared_ptr<_Tp>::shared_ptr(const shared_ptr& __r) _NOEXCEPT
//    : __ptr_(__r.__ptr_),
//      __cntrl_(__r.__cntrl_)
//{
//    if (__cntrl_)
//        __cntrl_->__add_shared();
//}

// 拷贝赋值函数
// template<class _Tp>
// inline
// shared_ptr<_Tp>&
// shared_ptr<_Tp>::operator=(const shared_ptr& __r) _NOEXCEPT
//{
//    shared_ptr(__r).swap(*this);
//    return *this;
//}

// reset
//_LIBCPP_INLINE_VISIBILITY void reset(_Tp* __p = 0) throw()
//{
//    if (__ptr_ != __p)
//        delete __ptr_;
//    __ptr_ = __p;
//}

using namespace std;

#define RED "red"
#define BLACK "black"
#define BLUE "blue"

class Student {
public:
    Student() { cout << "Student borned" << endl; }
    ~Student() { cout << "Student died" << endl; }

    void setColor(string color) { this->color = color; }

    void printColor() { cout << "我的颜色是" << color << endl; }

private:
    string color;
};

int main(int argc, const char* argv[]) {
    // 注意作用域
    //    {
    //        std::shared_ptr<Student> sh1;
    //        std::cout << sh1.use_count() << '\n';
    //    }

    {
        Student* sh0 = new Student();  // shared_ptr允许多个指针指向同一个对象；unique_ptr则独占所指向的对象。
        cout << "sh0 地址为:" << sh0 << endl;
        std::shared_ptr<Student> sh2(sh0);  // sh2 是一个指针，指向了这个sh0对象
        sh2->setColor(RED);
        std::shared_ptr<Student> sh3(sh0);  // sh3 是一个指针，指向了这个sh0对象
        sh3->setColor(BLACK);

        sh2->printColor();
        sh3->printColor();
        cout << "sh2 地址为:" << sh2 << endl;
        cout << "sh3 地址为:" << sh3 << endl;
        sh2.swap(sh3);  // sh2 和 sh3 交换了指向的对象
        sh2->printColor();
        sh3->printColor();
        cout << "变换地址后，sh2 地址为:" << sh2 << endl;  // 两个指针交换对象后，地址发生变化
        cout << "变换地址后，sh3 地址为:" << sh3 << endl;

        if (sh2 == sh3) {
            cout << "shared_ptr 的地址相同！" << endl;
            cout << "sh2 地址为:" << sh2 << endl;
            cout << "sh3 地址为:" << sh3 << endl;
        }
    }

    {
        // 一旦一个shared_ptr的计数器变为0，他就会自动释放自己所管理的对象。
        auto sh4 = std::make_shared<Student>();
        sh4->setColor(BLUE);
        cout << "引用计数为:" << sh4.use_count() << endl;
        cout << "否是独占所有权:" << sh4.unique() << endl;

        // 可以认为每个shared_ptr都有一个关联的计数器，通常称其为引用计数。无论何时我们拷贝一个shared_ptr，计数器都会递增
        auto sh5(sh4);
        sh4.reset();  // 放弃内部对象的所有权或拥有对象的变更, 会引起原有对象的引用计数的减少
        cout << "引用计数为:" << sh4.use_count() << endl;
        sh4->printColor();
    }

    {
        // 初始化
        shared_ptr<Student> p;                     // 空智能指针，指向类型为Student的对象
        cout << "实例化前的地址为:" << p << endl;  // 0x0
        p = std::make_shared<Student>();           // 智能指针实例化
        cout << "实例化后的地址为:" << p << endl;  // 0x7fcb19c059f8

        shared_ptr<Student> q(new Student());      // 空智能指针，指向类型为Student的对象
        cout << "实例化后的地址为:" << q << endl;  // 0x7fcb19c059f8
    }
    return 0;
}
