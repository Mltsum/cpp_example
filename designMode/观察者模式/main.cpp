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
using namespace Eigen;

/**
 * 设计模式之观察者模式
 */

using namespace std;

/**
 * 观察者:
 * @param argc
 * @param argv
 * @return
 */
 class Observer{
 public:
     Observer(){}
     virtual ~Observer(){}      // 基类的析构函数都要设计成虚函数

     /**
      * 观察者只需状态更新即可
      */
     virtual void update(int) = 0;      // 变化的部分
 };

/**
 * 发布者 : 发布者内部存有一定量的观察者，当发布者的信息更新时，会将更新消息发送给这些观察者，同时支持增删这些观察者。
 *           目标 ==》 观察者
 * @param argc
 * @param argv
 * @return
 */
 class Subject{
 public:
     Subject(){}
     virtual ~Subject(){}       // 基类的析构函数都要设计成虚函数

     /**
      * 增加观察者
      */
     virtual void attach(Observer*) = 0;        // 变化的部分

     /**
      * 删除观察者
      */
     virtual void detach(Observer*) = 0;        // 变化的部分

      /**
       * 通知观察者
       */
     virtual void notify() = 0;                 // 变化的部分
 };

 /**
  * 具体的观察者1
  */
 class ConcreteObserver : public Observer{
 public:
     /**
      * 构造函数(构造目标信息)
      * @param pSubject
      */
     ConcreteObserver(Subject *pSubject):mSubject(pSubject){

     }

     void update(int value){
         cout << "ConcreteObserver get the update. New State:" << value << endl;
     }

 private:
     Subject *mSubject;
 };

 /**
  * 观察者2
  */
class ConcreteObserver2 : public Observer{
public:
    /**
     * 构造函数(构造目标信息)
     * @param pSubject
     */
    ConcreteObserver2(Subject *pSubject):mSubject(pSubject){

    }

    void update(int value){
        cout << "ConcreteObserver2 get the update. New State:" << value << endl;
    }

private:
    Subject *mSubject;
};

/**
 * 发布者实例
 */

class ConcreteSubject : public Subject{
public:
    /**
     * 绑定观察者
     */
    void attach(Observer *pObserver){
        mObserverList.push_back(pObserver);
    }


    /**
     * 删除观察者
     */
    void detach(Observer* pObserver){
        mObserverList.remove(pObserver);
    }

    /**
     * 通知观察者
     */
    void notify(){
        for(auto &obs : mObserverList){
            obs->update(mState);
        }
    }

    /**
     * 设置当前状态
     */
     void setState(int value){
         mState = value;
     }

private:
    std::list<Observer*> mObserverList;
    int mState;
};


int main(int argc, const char* argv[]) {

    // 创建发布者
    ConcreteSubject *pSubject = new ConcreteSubject();

    // 创建观察者
    ConcreteObserver *Observer = new ConcreteObserver(pSubject);

    ConcreteObserver2 *Observer2 = new ConcreteObserver2(pSubject);

    // 当目标状态发生变化时，观察者应该接收到
    pSubject->setState(2);

    // 目标绑定观察者
    pSubject->attach(Observer);
    pSubject->attach(Observer2);

    // 目标通知观察者
    pSubject->notify();

    // 释放一个观察者
    pSubject->detach(Observer);

    pSubject->setState(3);
    pSubject->notify();

    if(pSubject){
        delete pSubject;
        pSubject = nullptr;
    }
    if(Observer){
        delete Observer;
        Observer = nullptr;
    }
    if(Observer2){
        delete Observer2;
        Observer2 = nullptr;
    }

    return 0;
}
