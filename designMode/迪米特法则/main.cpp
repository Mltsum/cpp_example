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
 * 设计模式之最少知识原则（Least Knowledge Principle 简写LKP）
 *    迪米特法则（Law of Demeter）又叫作最少知识原则（Least Knowledge Principle 简写LKP），就是说一个对象应当对其他对象有尽可能少的了解,不和陌生人说话。英文简写为: LoD.
 *
 *    其含义是：如果两个软件实体无须直接通信，那么就不应当发生直接的相互调用，可以通过第三方转发该调用。其目的是降低类之间的耦合度，提高模块的相对独立性。
 *
 *    从迪米特法则的定义和特点可知，它强调以下两点：
 *      从依赖者的角度来说，只依赖应该依赖的对象。
 *      从被依赖者的角度说，只暴露应该暴露的方法。
 *
 *      所以，在运用迪米特法则时要注意以下 6 点。
 *          1. 在类的划分上，应该创建弱耦合的类。类与类之间的耦合越弱，就越有利于实现可复用的目标。
 *          2. 在类的结构设计上，尽量降低类成员的访问权限。
 *          3. 在类的设计上，优先考虑将一个类设置成不变类。
 *          4. 在对其他类的引用上，将引用其他对象的次数降到最低。
 *          5. 不暴露类的属性成员，而应该提供相应的访问器（set 和 get 方法）。
 *          6. 谨慎使用序列化（Serializable）功能。
 *
 *    参考:http://m.biancheng.net/view/1331.html
 */


#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 定义明星类，明星只和经纪人有关系。
 */
class Star{
public:
    Star(std::string name){
        this->mName = name;
    }
    ~Star(){}

    std::string getName(){
        return mName;
    }

private:
    std::string mName;
};

/**
 * 粉丝类，粉丝只会和经纪人发生关系
 */
class Fans{
public:
    Fans(std::string name){
        this->mName = name;
    }
    ~Fans(){}

    std::string getName(){
        return mName;
    }

private:
    std::string mName;
};

/**
 * 公司类，公司只会和经纪人发生关系
 */
class Company{
public:
    Company(std::string name){
        this->mName = name;
    }
    ~Company(){}

    std::string getName(){
        return mName;
    }

private:
    std::string mName;
};

/**
 * 经纪人类，经纪人只会和明星发生关系，也会和粉丝或者公司发生关系
 */
class Agent{
public:
    void setStar(Star *star){
        this->mStar = star;
    }

    void setFans(Fans *fans){
        this->mFans = fans;
    }

    void setCompany(Company *company){
        this->mCompany = company;
    }

    void meeting(){
        cout << "明星（" << mStar->getName() << "）和粉丝（" << mFans->getName() << "）见面啦!" << endl;
    }

    void business(){
        cout << "公司（" << mCompany->getName() << "）和明星（" << mStar->getName() << "）商量收购养猪场的事情!" << endl;
    }

private:
    Star *mStar;
    Fans *mFans;
    Company *mCompany;
};


int main(int argc, const char* argv[]) {

    /**
     * 按照迪米特法则来定义对象
     */
    Star *star = new Star("周星驰");
    Fans *fans = new Fans("马帅");
    Company *company = new Company("高德地图");


    Agent *agent = new Agent();
    agent->setStar(star);
    agent->setFans(fans);
    agent->setCompany(company);

    agent->meeting();
    agent->business();

    return 0;
}