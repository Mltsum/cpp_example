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
 * 设计模式之开放封闭原则
 *    软件实体（类、模块、函数等）应该可以扩展，但不能修改。
 *    对于扩展是开放的（Open for extension），对于更改是封闭的（Closed for modification）
 *
 * 好处:
 *    1. 可维护、可扩展、可复用、灵活性好。
 *    2. 开发人员应该仅对程序中呈现出频繁变化的哪些部分做出抽象，然而，对于应用程序中每个部分都刻意的进行抽象同样不是一个好主意。拒绝不成熟的抽象和抽象本身一样重要
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 违反[开放-封闭]原则的代码
 *   1. 如果添加一个功能，则需要修改类，违背开闭原则
 *   2. 一个类尽可能实现一种功能
 */
class BankWorker{
public:
    void saveMoney()   {cout<<"存钱"<<endl;}
    void moveMoney()   {cout<<"转账"<<endl;}
    void payMoney()    {cout<<"支付"<<endl;}
};

/**
 * 实现一个基类，将动作抽象出来
 */
class OcBankWorker{
public:
    virtual void action() = 0;
};

class MoveMoneyWorker : public OcBankWorker{
public:
    void action() override {
        cout<<"转账"<<endl;
    }
};

class SaveMoneyWorker : public OcBankWorker{
public:
    void action() override {
        cout<<"存钱"<<endl;
    }
};

class PayMoneyWorker : public OcBankWorker{
public:
    void action() override {
        cout<<"支付"<<endl;
    }
};

class Bank{
public:
    Bank():mWorker(nullptr){}
    ~Bank(){}

    void hireBank(OcBankWorker *worker){
        mWorker = worker;
    }

    OcBankWorker * getWorker(){
        return mWorker;
    }

private:
    OcBankWorker *mWorker;
};



int main(int argc, const char* argv[]) {

    /**
     * 违反[开放-封闭]原则的代码
     */
    BankWorker *bankWorker = new BankWorker();
    bankWorker->saveMoney();
    bankWorker->moveMoney();
    bankWorker->payMoney();

    /*
     * 遵循开放封闭原则
     */
    SaveMoneyWorker *pSaveMoneyWorker = new SaveMoneyWorker();
    MoveMoneyWorker *pMoveMoneyWorker = new MoveMoneyWorker();
    PayMoneyWorker * pPayMoneyWorker = new PayMoneyWorker();

    Bank *bank = new Bank();
    bank->hireBank(pSaveMoneyWorker);
    bank->getWorker()->action();

    bank->hireBank(pMoveMoneyWorker);
    bank->getWorker()->action();

    bank->hireBank(pPayMoneyWorker);
    bank->getWorker()->action();

    CHECK_AND_DELETE(bankWorker)
   return 0;
}