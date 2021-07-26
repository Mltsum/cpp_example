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
#include <string.h>

using namespace std;

/**
 * 关于C++的std::share_ptr
 *    1. 所有指向它的 std::shared_ptr 都能相互合作确保在它不再使⽤的那个点进⾏析构。当最后⼀个std::shared_ptr 到达那个点， std::shared_ptr 会销毁它所指向的对象。
 *    2. std::shared_ptr 通过引⽤计数来确保它是否是最后⼀个指向某种资源的指针，引⽤计数关联资源并跟 踪有多少 std::shared_ptr 指向该资源。
 *       构造函数递增引⽤计数值
 *       析构函数递减值，拷⻉赋值运算符可能递增也可能递减值。
 *
 *    3. 性能：
 *       std::shared_ptr ⼤小是原始指针的两倍，因为它内部包含⼀个指向资源的原始指针，还包含⼀ 个资源的引⽤计数值。
 *       递增递减引⽤计数必须是原⼦性的，因为多个reader、writer可能在不同的线程。
 *
 *    4.  std::shared_ptr 使⽤delete作为资源的默认销毁器，但是 它也⽀持⾃定义的销毁器。这种⽀持有别于 std::unique_ptr 。对于 std::unique_ptr 来说，销毁器类型是智能指针类型的⼀部分。对于 std::shared_ptr则不是：
 *
 */

#define CUTLINE cout << "-------------------------------------------------" << endl;

class Widget{
public:
    Widget(){ cout << "执行 Widget 的构造函数." << endl;};
    ~Widget(){ cout << "执行 Widget 的析构函数." << endl;};
};


int main(int argc, const char* argv[]) {

    /**
     * 自定义析构不是Share_ptr的一部分
     */
     auto LoggingDel = [](Widget *widget){
        if(widget){delete widget;}
    };
     // 自定义析构是unique_ptr类型的一部分
     std::unique_ptr<Widget,decltype(LoggingDel)> upw(new Widget, LoggingDel);
     // 自定义析构不是share_ptr类型的一部分
     std::shared_ptr<Widget> spw(new Widget,LoggingDel);

     auto customDel1 = [](Widget *pw){};
     auto customDel2 = [](Widget *pw){};
     std::shared_ptr<Widget> pw1(new Widget, customDel1);
     std::shared_ptr<Widget> pw2(new Widget, customDel2);
     // 析构函数定义不一样的share_ptr可以放置到一个容器中。但是unique_ptr不行，自定义析构函数属于其智能指针实现的一部分
     std::vector<std::shared_ptr<Widget>> vPw {pw1, pw2};

     /**
      * 智能指针的大小
      * share_ptr 多一个引用计数
      */
     std::unique_ptr<Widget> ptr1(new Widget());
     std::shared_ptr<Widget> ptr2(new Widget());
     cout << "unique_ptr智能指针的大小为:" << sizeof(ptr1) << endl;  // 8
     cout << "share_ptr智能指针的大小为:" << sizeof(ptr2) << endl;   // 16


     /**
      * 避免传给 std::shared_ptr 构造函数原始指针。通常替 代⽅案是使⽤ std::make_shared
      * 如果你必须传给 std::shared_ptr 构造函数原始指针，直接传new出来的结果，不要传指针变量。
      */
      // 模板函数 make_shared 创建对象, make_shared 需指定类型('<>'中)及参数('()'内), 传递的参数必须与指定的类型的构造函数匹配
      std::shared_ptr<int> sp1 = std::make_shared<int>(10);

      CUTLINE

      /**
       * share_ptr 智能指针的引用计数
       */
       int count = 0;
       std::shared_ptr<int> sp2 = std::make_shared<int>(20);
       count = sp2.use_count();
       std::shared_ptr<int> sp3 = std::make_shared<int>(30);
       count = sp3.use_count();
       sp2.reset(new int());    // sp2引用计数减1到0，因此sp2调用析构。然后将sp2的地址重新分配了一个对象。

       std::shared_ptr<int> sp4 = sp3;  // 两个指针同时指向了同一个对象，引用计数加1(两个对象的引用计数都相同哦) (0x00007fed59f041b8 / 0x00007fed59f041b8 地址相同)
       std::shared_ptr<int> sp5 = sp3;
       count = sp3.use_count();
       count = sp4.use_count();         // strong=3 weak=1  直接赋值时，强引用加1
       sp3.reset();                 // 其中一个智能指针释放，引用计数减1。
       count = sp4.use_count();

       /**
        * 强引用和弱引用的区别
        * 智能指针一个很重要的概念是“所有权”，所有权意味着当这个智能指针被销毁的时候，它指向的内存（或其它资源）也要一并销毁。这技术可以利用智能指针的生命周期，来自动地处理程序员自己分配的内存，避免显示地调用delete，是自动资源管理的一种重要实现方式。
        * 为什么要引入“弱引用”指针呢？弱引用指针就是没有“所有权”的指针。有时候我只是想找个指向这块内存的指针，但我不想把这块内存的生命周期与这个指针关联。这种情况下，弱引用指针就代表“我指向这东西，但这东西什么时候释放不关我事儿……”
        */



        cout << "end test" << endl;
    return 0;
}