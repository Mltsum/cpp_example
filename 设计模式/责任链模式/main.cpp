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
 * 设计模式之责任链模式
 *    1、责任链中对象只和自己的后继是耦合关系，和其他对象毫无关联
 *    2、在处理中分配职责时，责任链给程序更多的灵活性（将责任大的对象放在责任链的前面）
 *    3、应用程序可以动态增加或者删除处理者；也可以动态的改变处理者之间的先后顺序
 *    4、使用责任链的用户不必知道处理者的信息。
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 消息处理基类
 */
class Handler {
public:
    /**
     * 本消息处理类
     * @param str
     */
    virtual void showMsg(std::string) = 0;
    /**
     * 设置下一个消息处理类
     */
    virtual void setNextHandler(Handler *) = 0;
};

/**
 * 个数处理类
 */
class NumberHandler : public Handler{
public:
    NumberHandler(){
        strs.push_back("001");
        strs.push_back("002");
        strs.push_back("003");
        strs.push_back("004");
    }

    /**
     * 责任链中，显示本节点的消息
     * @param code
     */
    void showMsg(std::string code) override {
        const auto &iter = std::find(strs.begin(),strs.end(),code);
        if(iter != strs.end()){
            cout << "Message code in NumHandler:" << code << endl;
        } else {
          mHandler->showMsg(code);
        }
    }

    /**
     * 责任链中，后继者的指定
     * @param handler
     */
    void setNextHandler(Handler* handler) override {
        this->mHandler = handler;
    }

private:
    std::vector<std::string> strs;
    Handler *mHandler;
};

/**
 * 数字处理类
 */
class DigitalHandler : public Handler{
public:
    DigitalHandler(){
        this->strs.push_back("101");
        strs.push_back("102");
        strs.push_back("103");
        strs.push_back("104");
    }

    /**
     * 责任链中，显示本节点的消息
     * @param code
     */
    void showMsg(std::string code) override {
        const auto &iter = std::find(strs.begin(),strs.end(),code);
        if(iter != strs.end()){
            cout << "Message code in DigitalHandler:" << code << endl;
        } else {
            mHandler->showMsg(code);
        }
    }

    /**
     * 责任链中，后继者的指定
     * @param handler
     */
    void setNextHandler(Handler* handler) override {
        this->mHandler = handler;
    }

private:
    std::vector<std::string> strs;
    Handler *mHandler;
};

/**
 * 字符处理类
 */
class TextHandler : public Handler{
public:
    TextHandler(){
        this->strs.push_back("111");
        strs.push_back("112");
        strs.push_back("113");
        strs.push_back("114");
    }

    /**
     * 责任链中，显示本节点的消息
     * @param code
     */
    void showMsg(std::string code) override {
        const auto &iter = std::find(strs.begin(),strs.end(),code);
        if(iter != strs.end()){
            cout << "Message code in TextHandler:" << code << endl;
        } else {
            mHandler->showMsg(code);
        }
    }

    /**
     * 责任链中，后继者的指定
     * @param handler
     */
    void setNextHandler(Handler* handler) override {
        this->mHandler = handler;
    }

private:
    std::vector<std::string> strs;
    Handler *mHandler;
};


int main(int argc, const char* argv[]) {

    /**
     * 设置责任链的节点
     */
    NumberHandler *numberHandler = new NumberHandler();
    DigitalHandler *digitalHandler = new DigitalHandler();
    TextHandler *textHandler = new TextHandler();

    /**
     * 设置责任链的链接模式
     */
    numberHandler->setNextHandler(digitalHandler);
    digitalHandler->setNextHandler(textHandler);

    /**
     * 责任链的使用
     */
    numberHandler->showMsg("111");

    CHECK_AND_DELETE(numberHandler)
    CHECK_AND_DELETE(digitalHandler)
    CHECK_AND_DELETE(textHandler)
   return 0;
}