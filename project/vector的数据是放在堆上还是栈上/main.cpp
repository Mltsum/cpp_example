#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 *  vector的内存申请是在堆还是栈？ 是否是取决于大小而动态配置？
 *      vector, map的数据是放在堆上。
 *
 */

#define RANGE (20)

int main(int argc, const char *argv[]) {
    /**
     * vector类放置于栈上，至于data是放置到哪里，待定
     * insert前后都是24个字节
     */
    std::vector<int> v;

    int x = sizeof(v);

    for (int i = 0; i < RANGE; ++i) {
        v.emplace_back(std::move(i));
        // 2倍增长
        // 内存申请依赖vector中的allocator_type& __a = this->__alloc();

        // 内存分配: typedef typename __alloc_traits::pointer         pointer;  // __alloc_traits类提供了一个顶层内存分配器的萃取器，可以使用_Alloc的allocate, dellocate, construct, destory等函数来完成内存分配、释放，对象构造、析构等任务。
        //        pointer                                         __begin_;
        //        pointer                                         __end_;
        //        std::cout << "v.capacity()" << v.capacity() << std::endl;
        std::cout << i << ":" << &v[i] << std::endl;
    }
    int y = sizeof(v);

    std::cout << "--------------------" << std::endl;

    /**
     * vector类放置于堆上，至于data是放置到哪里，待定
     */
    std::vector<int> *p = new vector<int>;
    for (int i = 0; i < RANGE; ++i) {
        p->emplace_back(std::move(i));
        std::cout << i << ":" << &v[i] << std::endl;

        //        std::cout << "p.capacity()" << p->capacity() << std::endl;
    }

    /**
     * 试验map的数据是放在堆上还是放在栈上
     * insert前后都是24个字节，因此是放在堆上
     */
    std::map<int, int> m;

    int x1 = sizeof(m);
    m.insert(std::make_pair(1, 1));
    m.insert(std::make_pair(2, 2));
    m.insert(std::make_pair(3, 3));
    m.insert(std::make_pair(4, 4));
    m.insert(std::make_pair(5, 5));
    int x2 = sizeof(m);

    return 0;
}
