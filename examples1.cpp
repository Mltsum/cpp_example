#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include <list>
#include <array>

/*
 * 互斥量需要引入该头文件
 */
#include <mutex>

/*
 * 功能：
 *  线程池 : 将多个线程放入一起，统一管理, 统一调度;
 *  实现方式: 在程序启动时，一次性创建好一定数量的线程(避免临时创建销毁线程，引起的资源消耗(保存上下文，恢复上下文，线程切换会带来很大的消耗)等，使得程序更加稳定)。
 *
 *  线程创建的数量极限问题:
 *      1)创建线程需要消耗系统资源等。
 *      2)根据经验，2000个线程是极限。
 *
 *  建议 : 1) 创建的线程的数量=CPU数量.  或者创建的线程的数量=CPU数量*2.
 *        2) 创建的线程数和业务强相关。
 *
 */

using namespace std;


int main() {
    std::cout << "main thread start..." << std::endl;

    int array[] { 1,4,3 };
    cout << "1[a] is " << 0[array] << endl;
    cout << "a[0] is " << array[0] << endl;

    // array?
    std::array<int, 3> array1 {1,2,3};
//    cout << "0[array] is " << 0[array1] << endl;    // error
    cout << "0[array] is " << array1[0] << endl;

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
//    cout << "0[vec] is " << 0[vec] << endl; //error
    cout << "vec[0] is " << vec[0] << endl;


    std::cout << "main thread end..." << std::endl;
    return 0;
}
