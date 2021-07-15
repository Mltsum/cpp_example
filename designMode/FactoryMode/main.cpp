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
 * 设计模式之工厂模式
 * 简单工厂模式
 *    对不同类对象的创建进行了封装。该模式通过向工厂传入类来指定要创建的对象
 * 工厂方法模式
 *    将创建对象的能力交给子工厂，方便扩展。
 */

using namespace std;

/**
 * 简单工厂模式
 * 定义一个基类 => 由基类创造出不同的产品 => 定义一个工厂类 => 由工厂根据不同的类创建出不同的对象
 *
 */
class Product{
public:
    virtual void show() = 0;
};

class ProductA : public Product{
public:
    void show(){
        cout << "this is ProductA" << endl;
    }
};

class ProductB : public Product{
public:
    void show(){
        cout << "this is ProductB" << endl;
    }
};

/**
 * 简单工厂模式的工厂
 */
class Factory{
public:
    Product* Create(int i){
        switch(i){
            case 1:
                return new ProductA;
            case 2:
                return new ProductB;    // 缺点，当需要新增产品时，就需要修改工厂的类
            default:
                break;
        }
    }
};

/**
 * 工厂方法模式的工厂
 */
 class FactoryWithMethod{
 public:
     /**
      * 定义一个接口，让子类决定实例化哪个类
      */
     virtual Product* create() = 0;
 };

 class FactoryWithMethodA : public FactoryWithMethod{
 public:
     Product* create(){
         return new ProductA;
     }
 };

class FactoryWithMethodB : public FactoryWithMethod{
public:
    Product* create(){
        return new ProductB;
    }
};

/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char* argv[]) {

    /**
     * 简单工厂模式
     */
    Factory *factory = new Factory();
    factory->Create(1)->show();
    factory->Create(2)->show();

    /**
     * 工厂方法模式
     */
    FactoryWithMethodA *factoryWithMethodA = new FactoryWithMethodA();
    FactoryWithMethodB *factoryWithMethodB = new FactoryWithMethodB();

    factoryWithMethodA->create()->show();
    factoryWithMethodB->create()->show();

    return 0;
}
