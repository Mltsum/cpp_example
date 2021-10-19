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
 * 设计模式之访问者模式
 *    稳定的数据结构和易变的操作耦合问题。
 *    何时使用：需要对一个对象结构中的对象进行很多不同的并且不相关的操作，而需要避免让这些操作"污染"这些对象的类，使用访问者模式将这些封装到类中。
 *    如何解决：在被访问的类里面加一个对外提供接待访问者的接口。
 *    关键代码：在数据基础类里面有一个方法接受访问者，将自身引用传入访问者。
 *
 *    核心还是要使得代码便于扩展。
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 访问者
 */
class Visitor{
public:
    Visitor(std::string &str){
        this->mName = str;
    }

    std::string getName(){
        return mName;
    }

private:
    std::string mName;
};

/**
 * 接待者类
 */
class Receiver{
public:
    Receiver(){}
    virtual bool Accept(Visitor *) = 0;
    std::string getName(){
        return mName;
    }
protected:
    bool mBFree;
    std::string mName;

};

/**
 * 接待者类 - 男
 */
class ReceiverMan : public Receiver{
public:
    ReceiverMan(std::string &str){
        mBFree = false;
        mName = str;
    }

    bool Accept(Visitor * visitor){
        if(!mBFree){
            cout << "ReceiverMan: visitor name is " << visitor->getName() << endl;
            mBFree = true;
            return true;
        }
        return false;
    }
};

/**
 * 接待者类 - 女
 */
class ReceiverWoMan : public Receiver{
public:
    ReceiverWoMan(std::string &str){
        mBFree = false;
        mName = str;
    }

    bool Accept(Visitor * visitor){
        if(!mBFree){
            cout << "ReceiverWoMan: visitor name is " << visitor->getName() << endl;
            mBFree = true;
            return true;
        }
        return false;
    }
};

class ReceiverManager{
public:
    ReceiverManager(){

    }
    /**
     * 接待访问者
     * @return
     */
    bool accept(Visitor* visitor){
        for(auto &receiver : mReceivers){
            if(receiver->Accept(visitor)){
                return true;
            }
        }
        cout << "No receiver: visit faild!"<< endl;
        return false;
    }

    /**
     * 增加一个接收管理者
     * @param receiver : 接收者
     */
    void add(Receiver* receiver){
        mReceivers.push_back(receiver);
    }

    /**
     * 清除全部的接收管理者
     */
    void clear(){
        mReceivers.clear();
    }

private:
    std::vector<Receiver*> mReceivers;
};


int main(int argc, const char* argv[]) {
    std::string mStr = "maShuai";
    std::string sStr = "sheChangMei";
    std::string bStr = "baiHuiHui";

    Visitor *maShuai = new Visitor(mStr);
    Visitor *sheChangMei = new Visitor(sStr);
    Visitor *baiHuiHui = new Visitor(bStr);

    std::string hrStr = "阿里HR-女";
    std::string govStr = "阿里行政-男";
    ReceiverMan *receiverMan = new ReceiverMan(hrStr);
    ReceiverWoMan *receiverWoMan = new ReceiverWoMan(govStr);

    ReceiverManager receiverManager;

    receiverManager.add(receiverMan);
    receiverManager.add(receiverWoMan);

    receiverManager.accept(maShuai);
    receiverManager.accept(sheChangMei);
    receiverManager.accept(baiHuiHui);
    return 0;
}
