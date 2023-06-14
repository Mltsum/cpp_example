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
 * 设计模式之单例模式
 *
 * 单例模式允许调用者返回一个全局的唯一对象，这种设计模式常用于一些全局对象和全局函数的封装，从而代替传统的全局变量定义。
 *
 * 单例模式实现主要有四种方式：懒汉式，饿汉式，线程安全饿汉式，局部静态变量式。
 *
 * 主要解决：一个全局使用的类频繁地创建与销毁。
 *
 * 何时使用：控制实例数目，节省系统资源的时候。
 *
 * 如何实现:
 *    单例模式的实现三要素：使用一个私有的构造函数 ，一个私有的静态变量以及一个共有的静态函数来实现。
 *    因为私有的构造函数保证了不能通过构造函数来创建对象实例，只能通过共有的静态函数返回唯一的私有静态变量。
 *
 * 特点与选择：
 *    以空间换时间：由于要进行线程同步，所以在访问量比较大，或者可能访问的线程比较多时，采用饿汉实现。
 *    以时间换空间：在访问量较小时，采用懒汉实现。
 */


#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 饿汉模式
 * 优点: 实现简单，逻辑清晰
 * 缺点: 浪费内存
 */
class SingleTonSimple{
public:
    // 要素1: 公有的静态函数: 方便获取私有的静态变量
    static SingleTonSimple* getInstance(){
        return mSingleTonSimple;
    }

    static void destory(){
        CHECK_AND_DELETE(mSingleTonSimple)
        cout << "销毁单例的指针" << endl;
    }

    void printMsg(){
        cout << "我是饿汉模式的单例，因为我必须在main函数之前实例化对象，不然我会饿死哟，因此叫我懒汉模式，就问你们服不服！" << endl;
    }

private:
    // 要素2: 私有的静态变量: 保证只能通过公有的静态函数访问
    static SingleTonSimple *mSingleTonSimple;

    /**
     * 不允许构造和析构
     */
    // 要素3: 私有的构造和析构: 保证外部不能通过构造来实例化对象，而只能通过公有的静态函数来访问唯一的私有的静态变量。
    SingleTonSimple(){}
    ~SingleTonSimple(){}
};
//  表示在main函数之前，就初始化好了。因此也是线程安全的。当多个线程访问时，其实访问的是同一个地址。
//  在main函数之前初始化，导致程序启动会想对慢一点。且初始化了不一定会用，有可能浪费资源。
SingleTonSimple * SingleTonSimple::mSingleTonSimple = new SingleTonSimple();

/**
 * 懒汉模式的单例
 *   优点：节约内存
 *   缺点：线程不安全，需要手动保证线程安全.
 */
class SingleTonStandard{
public:
    static SingleTonStandard* getInstance(){
        // 这里在new时，有可能多个线程执行到这里。导致实例化多次的情况。
        if(mSingleTonStandard == nullptr){
            mSingleTonStandard = new SingleTonStandard();
        }
        return mSingleTonStandard;
    }

    static void destory(){
        CHECK_AND_DELETE(mSingleTonStandard)
        cout << "销毁单例的指针" << endl;
    }

    void printMsg(){
        cout << "我是懒汉模式的单例，因为我懒的实例化对象，只有用到了我再去进行实例化，因此叫我懒汉模式，就问你们服不服！" << endl;
    }
private:
    /**
     * 全局静态的对象
     */
    static SingleTonStandard *mSingleTonStandard;

    /**
     * 不允许析构和构造
     */
    SingleTonStandard(){}
    ~SingleTonStandard(){}
};
// 在main函数之前初始化了nullptr，真正在使用时才进行初始化。因此不会造成资源浪费的可能。
SingleTonStandard*  SingleTonStandard::mSingleTonStandard = nullptr;


/**
 * 线程安全的懒汉模式
 *   优点：节约内存
 *   缺点：线程安全
 */
class SingleTonStandardThreadSafe{
public:
    static SingleTonStandardThreadSafe* getInstance(){
        // 在new对象时，增加线程锁
        std::unique_lock<std::mutex> lock(mMutex);

        if(mSingleTonStandardThreadSafe == nullptr){
            mSingleTonStandardThreadSafe = new SingleTonStandardThreadSafe();
        }
        return mSingleTonStandardThreadSafe;
    }

    static void destory(){
        CHECK_AND_DELETE(mSingleTonStandardThreadSafe)
        cout << "销毁单例的指针" << endl;
    }

    void printMsg(){
        cout << "我是线程安全的懒汉模式的单例，因为我在创建实例时，有可能有多个线程同时创建，破坏单例的目的，因此我加锁了，就问你们服不服！" << endl;
    }
private:
    /**
     * 全局静态的对象
     */
    static SingleTonStandardThreadSafe *mSingleTonStandardThreadSafe;

    /**
     * 增加线程锁
     */
    static std::mutex mMutex;

    /**
     * 不允许析构和构造
     */
    SingleTonStandardThreadSafe(){}
    ~SingleTonStandardThreadSafe(){}
};
SingleTonStandardThreadSafe*  SingleTonStandardThreadSafe::mSingleTonStandardThreadSafe = nullptr;
std::mutex SingleTonStandardThreadSafe::mMutex;

/**
 * 静态局部变量的实现方式
 * 优点: 线程安全，逻辑简单
 * 缺点: 浪费内存
 */
class SingleTonStaticVar{
public:
    // 如果变量在初始化时，并发线程同时进入到static声明语句，并发线程会阻塞等待初始化结束。
    // 这样可以保证在获取静态局部变量的时候一定是初始化过的，所以具有线程安全性，同时也避免了new对象时指令重排序造成对象初始化不完全的现象。
    // 并且相比较与使用智能指针以及mutex来保证线程安全和内存安全来说，这样做能够提升效率。
    static SingleTonStaticVar* getInstance(){
        static SingleTonStaticVar mSingleTonStaticVar;
        return &mSingleTonStaticVar;
    }

    void printMsg(){
        cout << "我是静态局部变量的单例实现方式，就问你们服不服！" << endl;
    }
private:
    SingleTonStaticVar(){}
    ~SingleTonStaticVar(){}
};



int main(int argc, const char* argv[]) {

    /**
     * 懒汉模式
     */
    SingleTonSimple *singleTonSimple = SingleTonSimple::getInstance();
    singleTonSimple->printMsg();
    singleTonSimple->destory();

    /**
     * 饿汉模式
     */
    SingleTonStandard *singleTonStandard = SingleTonStandard::getInstance();
    singleTonStandard->printMsg();
    singleTonStandard->destory();

    /**
     * 集成线程安全的单例模式
     */
    SingleTonStandardThreadSafe *singleTonStandardThreadSafe =  SingleTonStandardThreadSafe::getInstance();
    singleTonStandardThreadSafe->printMsg();
    singleTonStandardThreadSafe->destory();


    SingleTonStaticVar *singleTonStaticVar = SingleTonStaticVar::getInstance();
    singleTonStaticVar->printMsg();

    return 0;
}