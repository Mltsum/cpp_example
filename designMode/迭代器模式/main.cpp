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
 * 设计模式之迭代器模式
 * 提供一个对象来顺序访问聚合对象中的一系列数据，而不暴露聚合对象的内部表示。迭代器模式是一种对象行为型模式，其主要优点如下。
 * 1. 访问一个聚合对象的内容而无须暴露它的内部表示。
 * 2. 遍历任务交由迭代器完成，这简化了聚合类。
 * 3. 它支持以不同方式遍历一个聚合，甚至可以自定义迭代器的子类以支持新的遍历。
 * 4. 增加新的聚合类和迭代器类都很方便，无须修改原有代码。
 * 5. 封装性良好，为遍历不同的聚合结构提供一个统一的接口。
 *
 * 缺点:
 *    增加了类的个数，这在一定程度上增加了系统的复杂性。
 */


#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 迭代器的基类
 */
class Iterator {
public:
    Iterator(){}
    ~Iterator(){}

    virtual std::string first() = 0;
    virtual std::string next() = 0;
    virtual std::string current() = 0;
    virtual bool isEnd() = 0;
};

/**
 * 对象基类
 */
class Object{
public:
    Object(){}
    ~Object(){}

    virtual Iterator* createIterator() = 0;
    virtual int count() = 0;
    virtual void push(std::string) = 0;
    virtual std::string pop(int) = 0;
};

/**
 * 迭代器的派生类
 */
class SubIterator : public Iterator {
public:
    // 如果父类的构造为默认构造，则最好也写上初始化
    SubIterator(Object *object):Iterator(),mObject(object),mCurrent(0){}
    ~SubIterator(){}

    std::string first() override {
        return mObject->pop(0);
    }

    std::string next() override {
        std::string str;
        if(mCurrent < mObject->count() - 1){
            mCurrent = mCurrent + 1;
            str = mObject->pop(mCurrent);
        }
        return str;
    }

    std::string current(){
        return mObject->pop(mCurrent);
    };

    bool isEnd(){
        return (mCurrent == mObject->count()-1);
    }

private:
    Object *mObject;
    int mCurrent;
};

/**
 * 对象的派生类
 */
class Children : public Object{
public:
    Children():Object(),mStrings({}),mIterator(nullptr){
    }
    ~Children(){}

    Iterator* createIterator() override {
        if(mIterator == nullptr){
            mIterator = new SubIterator(this);
            return mIterator;
        }
    }

    int count() override {
        return mStrings.size();
    }

    void push(std::string str) override {
        mStrings.push_back(str);
    }

    std::string pop(int i){
        std::string str;
        if(i >= 0 && i < mStrings.size()){
            return mStrings[i];
        }
        return str;
    }

    std::vector<std::string> mStrings;
    Iterator *mIterator;
};

int main(int argc, const char* argv[]) {

    /**
     * 定义一个包含一系列数据的对象
     */
    Children *children = new Children();
    children->push("maShuai");
    children->push("sheChangMei");
    children->push("baiHuiHui");

    /**
     * 获取该对象定义的迭代器
     */
    Iterator* iter = children->createIterator();

    /**
     * 利用迭代器来索引数据
     */
    std::cout << "First person:" << iter->first() << std::endl;
    while(!iter->isEnd()){
        std::cout << "next person:" << iter->next() << std::endl;
    }
   return 0;
}