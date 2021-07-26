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
 * 关于C++的std::unique_ptr
 *    是什么？
 *    std::unique_ptr
 *       1. 等同于原始指针，而且对于⼤多数操作（包括取消引⽤），他们执⾏的指令完全相同。
 *       2. 只支持移动操作，不支持拷贝操作。
 *
 *    特点:
 *       1. 提供删除器释放对象，允许用户自定义删除器
 *       2. 添加了对象数组的偏特化实现，new[]，delete[]
 *       3. 使用C++ 11的右值引用特性，实现所有权转移 std::move()
 *
 *    解决了什么问题？
 *       1. 传统指针，比如 int *a; 声明后，不能说明是对象还是数组
 *       2. 声明后，需要手动销毁
 *       3. 很难确保在代码的所有逻辑路径上都执行了销毁操作
 *       4. 无法证明此指针在delete后的状态是悬空指针还是nullptr
 *
 *    应用场景
 *       1. 继承层次结构中对象的⼯⼚函数返回类型。
 */

/**
 * 基类
 */
class Investment{
public:
    Investment(){
        cout << "执行构造(Investment)!" << endl;

    }
    ~Investment(){
        cout << "执行析构(Investment)!" << endl;
    }
};

/**
 * 派生类
 */
class Sock : public Investment{
public:
    Sock(){
        cout << "执行构造(Sock)!" << endl;

    }
    ~Sock(){
        cout << "执行析构(Sock)!" << endl;

    }
};
class Bond : public Investment{
public:
    Bond(){
        cout << "执行构造(Bond)!" << endl;

    }
    ~Bond(){
        cout << "执行析构(Bond)!" << endl;

    }
};
class RealEstate : public Investment{};

// 自定义析构
auto delInvmt = [](Investment *pInvestment){
    cout << "执行析构(delInvmt)!" << endl;
    delete pInvestment;
};

enum PiplineType{
    SockType,
    BondType,
    RealEstateType,
};

class Factory{
public:
    // 编译器由模板自动生成函数的过程叫模板的实例化。由模板实例化而得到的函数称为模板函数。

    // C++11 新增，变长模版
    // template <typename... Ts>
    // std::unique_ptr<Investment, decltype(delInvmt)> makeInvestment(Ts&&... params){}

    // 基本策略是创建⼀个空的 std::unique_ptr ，然后指向⼀个合适类型的对象，然后返回。
    std::unique_ptr<Investment, decltype(delInvmt)> makeInvestment(PiplineType type){
        // 1. 只能指针可以通过lamda函数自定义传入析构函数
        // 2. 可以用如下方式初始化一个只能指针ch
        std::unique_ptr<Investment,decltype(delInvmt)> pInv(nullptr,delInvmt);

        switch (type) {
            case SockType:
                {
                    // unique_ptr 在声明后，如何实例化：通过reset
                    // 因为不存在从原始指针到智能指针的隐式转换。
                    pInv.reset(new Sock());
                }
                break;
            case BondType:
                {
                    pInv.reset(new Bond());
                }
                break;
            case RealEstateType:
                {
                    pInv.reset(new RealEstate());
                }
                break;
            default:
                break;
        }
        return pInv;
    }
};

/**
 * unique_ptr不能作为形参，因为不可赋值
 * 要么用普通指针作为形参，要么用引用。
 * @param i
 */
void f1(int * i){

}
void f2(std::unique_ptr<int> &p)
{
    *p = 10;
}

/**
 * 智能指针作为参数返回
 * @param i
 * @return
 */
std::unique_ptr<int> f3(int i)
{
    return std::unique_ptr<int>(new int(i));
}

int main(int argc, const char* argv[]) {
    Factory *factory = new Factory();

    /**
     * 类型1
     */
    PiplineType type = SockType;    // 0x7fa1d7c05a50
    auto pInv = factory->makeInvestment(type);

    cout << pInv << endl;
    cout << "=======================" << endl;

    /**
     * 类型2
     */
    PiplineType type1 = BondType;   // 0x7fa1d7c05a60 地址是不同的
    auto pInv1 = factory->makeInvestment(type1);

    cout << pInv1 << endl;

    cout << "=======================" << endl;


    /**
     * 创建一个空的unique_ptr<int>对象，因为没有与之关联的原始指针，所以它是空的。
     *
     * 检查是否关联原始指针
     * unique_ptr对象始终是关联的原始指针的唯一所有者。
     */
    std::unique_ptr<int> ptr;
    if(!ptr){ std::cout<<"ptr1 is empty"<<std::endl; }
    if(ptr == nullptr){std::cout<<"ptr1 is empty"<<std::endl;}

    /**
     * 关联原始指针
     */
//     std::unique_ptr<int> ptr0 = new int();   // 直接赋值是错误的，不支持的。
     std::unique_ptr<int> ptr1(new int());
     std::unique_ptr<int> ptr2; ptr2.reset(new int());

     /**
      * 获取被管理对象的指针
      */
      auto p = ptr1.get();
      cout << "[ptr1] 指针地址为: " << p << endl;

      /**
       * 释放关联的原始对象指针，并置空
       */
       ptr.reset();
       ptr1.release();
       ptr2 = nullptr;

       /**
        * 所有权的转移
        */
        std::unique_ptr<int> ptrOri(new int());
        if(ptrOri == nullptr){cout << "指针地址空" << endl;}else{cout << "指针地址非空" << endl;};
        cout << "[ptrOri] 指针地址为: " << ptrOri << endl;       // 0x7ff622405a90
        std::unique_ptr<int> ptrDst = std::move(ptrOri);
        if(ptrOri == nullptr){cout << "指针地址空" << endl;}else{cout << "指针地址非空" << endl;};
        cout << "[ptrDst] 指针地址为: " << ptrDst << endl;       // 0x7ff622405a90

        /**
         * 声明一个智能指针数组
         */
         std::unique_ptr<int []> ptrs(new int[10]);

         /**
          * 智能作为函数参数
          * 不能用做形参，因为不可赋值。一般用法:形参作为参数传入，实参用.get()来获取原始指针传入  或者传入引用。
          */
          std::unique_ptr<int> ptr5(new int(42));
          f1(ptr5.get());
          f2(ptr5);

          /**
           * 作为返回值
           */
           std::unique_ptr<int> ptrTmp = f3(10);

    return 0;
}