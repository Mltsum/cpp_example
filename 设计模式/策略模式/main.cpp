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
 * 设计模式之策略模式
 *    封装一系列的算法，使其可以相互替换
 *
 * 思想在于:1）定义策略的接口类，以此衍生出不同的策略执行  2）不同的策略执行可以通过上下文类管理 3）不同策略的执行则执行上下文对象即可
 *
 */

using namespace std;

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 定义一个策略类
 */
class IStrategy{
public:
    virtual void travel() = 0;
    IStrategy(){}
    virtual ~IStrategy(){}      // 任何一个基类应声明为虚函数
};

class Context{
public:
    Context(IStrategy *strategy = nullptr){ mStrategy = strategy;}
    Context(){
        CHECK_AND_DELETE(this->mStrategy)
    }

    void travel(){
        mStrategy->travel();
    };

private:
    // 应该放置指针，指针才具有多态。 不应该声明为对象
    // 指针应该被初始化和显示的delete
    IStrategy *mStrategy;
};

class BikeStrategy : public IStrategy{
public:
    void travel(){
        cout << "travel by bike!" << endl;
    }
};

class CarStrategy : public IStrategy{
public:
    void travel(){
        cout << "travel by car!" << endl;
    }
};

class SubwayStrategy : public IStrategy{
public:
    void travel(){
        cout << "travel by subway!" << endl;
    }
};


enum TravelMode{
    BikeMode,
    CarMode,
    SubwayMode
};

int main(int argc, const char* argv[]) {

    TravelMode curMode = SubwayMode;

    IStrategy *bike = new BikeStrategy();
    IStrategy *car = new CarStrategy();
    IStrategy *subway = new SubwayStrategy();

    switch (curMode) {
        case BikeMode:
            {
                Context *bikeCtx = new Context(bike);
                bikeCtx->travel();
            }
            break;
        case CarMode:
            {
                Context *carCtx = new Context(car);
                carCtx->travel();
            }
            break;
        case SubwayMode:
            {
                Context *subwayCtx = new Context(subway);
                subwayCtx->travel();
            }
        default:
            break;
    }
    CHECK_AND_DELETE(bike)
    CHECK_AND_DELETE(car)
    CHECK_AND_DELETE(subway)
    return 0;
}
