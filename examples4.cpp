#include <iostream>
#include <array>
#include <memory>

/*
 *  1. 智能指针share_ptr的使用
 *      std::shared_ptr 是通过指针保持对象共享所有权的智能指针。多个 shared_ptr 对象可占有同一对象
 */

using namespace std;


// 程序的主函数
int main( )
{
    /*
     * unique_ptr的数组智能指针，没有*和->操作，但支持下标操作[]
     */
    unique_ptr<int[]> up(new int[2]);

    for (int i = 0; i < 2; i++) {
        up[i] = i;
    }
    cout << up[1] << endl;

    /*
     * shared_ptr的数组智能指针，有*和->操作，但不支持下标操作[]，只能通过get()去访问数组的元素。
     * shared_ptr的数组智能指针，必须要自定义deleter
     */
    shared_ptr<int> sp(new int[2], [](int* p){delete [] p;});
    cout << "address is" << sp.get() << endl;

    return 0;
}