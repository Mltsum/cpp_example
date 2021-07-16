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
 * 设计模式之装饰器模式
 *    允许向现有的对象添加新的功能，同时不改变其结构。
 *    创建了一个装饰类，用来包装原有的类，并在保持类方法签名完整性的前提下，提供了额外的功能。
 *    主要解决：一般的，我们为了扩展一个类经常使用继承方式实现，由于继承为类引入静态特征，并且随着扩展功能的增多，子类会很膨胀。
 *
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 普通抽象类
 */
class CoffeeBean{
public:
    virtual void showCoffeeName() = 0;
    virtual void showPrice() = 0;

public:
    std::string mCoffeeName;
    int mPrice;
};

/**
 * 咖啡类
 */
class Coffee : public CoffeeBean{
public:
    Coffee(std::string &name, int price){
        mCoffeeName = name;
        mPrice = price;
    }

    void showCoffeeName(){
        std::cout << "CoffeeBean name:" << mCoffeeName << std::endl;
    }

    void showPrice(){
        std::cout << "CoffeeBean price:" << mPrice << std::endl;
    }
};

/**
 * 装饰类
 *  保持基类完整性的前提下，扩展出了
 */
class ExtendCoffee : public CoffeeBean{
public:
    ExtendCoffee(CoffeeBean* pBean){
        mPBean = pBean;
    }
    ~ExtendCoffee(){}

    /**
     * 扩展抽象类时，也必须进行父类抽象接口的实现！！！！
     */
    virtual void showCoffeeName(){};
    virtual void showPrice(){};

    /**
     * 在抽象类的基础上，进行接口的扩展，扩展完成后依然是抽象类！！！
     * */
    virtual void showCoffeeColor() = 0;
    virtual void setCoffeeColor(std::string &color) = 0;

protected:
    CoffeeBean *mPBean;
    std::string mColor;
};

/**
 * 美式
 */
class Americano : public ExtendCoffee{
public:
    Americano(CoffeeBean *pBean):ExtendCoffee(pBean){

    }
    ~Americano(){}

    void ShowCoffeeName()
    {
        std::cout << "I am Americano Coffee,Coffee name:" << mPBean->mCoffeeName + " from American" << std::endl;
    }
    void ShowPrice()
    {
        mPBean->mPrice = 48;
        std::cout << "Americano Coffee price:" << mPBean->mPrice << std::endl;
    }

    void setCoffeeColor(std::string &color){
        mColor = color;
    }

    void showCoffeeColor(){
        std::cout << "Americano Coffee color:" << mColor << std::endl;
    }
};

/**
 * 拿铁
 */
class Latte :public ExtendCoffee
{
public:
    Latte(CoffeeBean* pBean) :ExtendCoffee(pBean) {}
    ~Latte() {}

    void ShowCoffeeName()
    {
        std::cout << "I am Latte Coffee,Coffee name:" << mPBean->mCoffeeName + " from Italy" << std::endl;
    }
    void ShowPrice()
    {
        mPBean->mPrice = 58;
        std::cout << "Latte Coffee price:" << mPBean->mPrice << std::endl;
    }
    void setCoffeeColor(std::string &color){
        mColor = color;
    }

    void showCoffeeColor(){
        std::cout << "Latte Coffee color:" << mColor << std::endl;
    }
};

/**
 * 摩卡
 */
class Mocha :public ExtendCoffee
{
public:
    Mocha(CoffeeBean* pBean) :ExtendCoffee(pBean) {}
    ~Mocha() {}

    void ShowCoffeeName()
    {
        std::cout << "I am Mocha Coffee,Coffee name:" << mPBean->mCoffeeName + " from Franch" << std::endl;
    }
    void ShowPrice()
    {
        mPBean->mPrice = 68;
        std::cout << "Mocha Coffee price:" << mPBean->mPrice << std::endl;
    }
    void setCoffeeColor(std::string &color){
        mColor = color;
    }
    void showCoffeeColor(){
        std::cout << "Mocha Coffee color:" << mColor << std::endl;
    }
};


class A{
public:
    A(){
        cout << "AAA" << endl;
    }
};

class Aa : public A{
public:
    Aa(){
        cout << "Aa" << endl;
    }
};

class C{
public:
    C(A* a){
        cout << "CCC" << endl;
    }
};


class D{
public:
    D(A* a){
        cout << "DDD" << endl;
    }
};


int main(int argc, const char* argv[]) {
    std::string coffeeName = "CoffeeBean";
    Coffee *coffee = new Coffee(coffeeName,200);
    coffee->showCoffeeName();
    coffee->showPrice();

    Americano* amCoffee = new Americano(coffee);
    amCoffee->ShowCoffeeName();
    amCoffee->ShowPrice();

    Latte* ltCoffee = new Latte(coffee);
    ltCoffee->ShowCoffeeName();
    ltCoffee->ShowPrice();

    Mocha* mkCoffee = new Mocha(coffee);
    mkCoffee->ShowCoffeeName();
    mkCoffee->ShowPrice();


    //  关于派生类和基类的构造问题
    A *a = new A();
    Aa *aa = new Aa() ;
    /**
     * private继承不行的原因是派生类无从得知基类的构造函数。因此传递有问题。
     * public继承可以的原因是派生类的构造需要调用基类的构造，因此是可以的。
     */
    C *c = new C(aa);

    return 0;
}
