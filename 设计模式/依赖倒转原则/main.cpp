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
 * 设计模式之依赖倒转原则
 *    依赖倒置原则定义：依赖于抽象(接口)，不要依赖具体的实现(类)，也就是针对接口编程。
 * C++中的一个重要特性：高内聚，低耦合。高内聚，低耦合。高内聚，低耦合。
 *
 * 依赖倒转原则（Dependency Inversion Principle，简称DIP）是指将两个模块之间的依赖关系倒置为依赖抽象类或接口。
 *  1) 高层模块不应该依赖于低层模块，二者都应该依赖于抽象；
    2) 抽象不应该依赖于细节，细节应该依赖于抽象。

    所谓依赖是指如果一个模块A使用另一个模块B，我们称模块A依赖模块B。在应用程序中，有一些低层次的类，这些类实现了一些基本的或初级的操作，我们称之为低层模块；另外，有一些高层次的类，这些类封装了某些复杂的逻辑，这些类我们称之为高层模块。高层次模块要完成自己封装的功能，就必须要使用低层模块，于是高层模块就依赖于低层模块。
    高层模块依赖于低层模块的现象，在传统的结构化程序设计中，是非常常见的。因为结构化程序设计就是采用由上到下、逐层分解的策略，把大型和复杂的软件系统分解成若干个人们易于理解和易于分析的子系统。这里的分解是根据软件系统的逻辑特性和系统内部各成分之间的逻辑关系进行的。在分解过程中，被分解的上层就是下层的抽象，下层为上层的具体细节。这样，就造成高层抽象模块依赖低层模块；抽象层依赖具体层。但在实际系统中，抽象层是相对稳定的，而低层模块却是经常变动的。因为高层模块依赖于低层模块，一旦低层模块发生改变，高层模块也会受到影响。为了保持系统的稳定，应该使低层模块依赖于高层模块。

    在面向对象设计中，类和类之间依赖关系可以分为两种类型：
        具体耦合关系：发生在两个具体的（可实例化的）类之间，经由一个类对另一个具体类的直接引用造成。
        抽象耦合关系：发生在一个具体类和一个抽象类（或接口）之间，使两个必须发生关系的类之间存有最大的灵活性。
 */


#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 定义抽象层(中间层)
 */
class HardDisk{
public:
    virtual void work()=0;
};

class Memory{
public:
    virtual void work()=0;
};

class Cpu{
public:
    virtual void work()=0;
};

/**
 * 定义高层功能层
 */
class Computer{
public:
    Computer(Cpu *cpu, Memory *mem, HardDisk *hard){
        mCpu = cpu;
        mMemory = mem;
        mHard = hard;
    }

    //高层业务函数，只关心每个硬件的业务(是否工作等),并不关心硬件是那些个产商生产的
    void work(){
        mCpu->work();
        mMemory->work();
        mHard->work();
    }


private:
    Cpu *     mCpu;
    Memory *  mMemory;
    HardDisk *mHard;
};

/**
 * 底层实现层
 */
class XiJieHardDisk :public HardDisk{
public:
    virtual void work(){
        cout << "XiJie HardDisk working..." << endl;
    }
};

class InterCpu :public Cpu{
public:
    virtual void work()
    {
        cout << "Inter Cpu working..." << endl;
    }
};

class JSDMemory :public Memory{
public:
    virtual void work()
    {
        cout << "JSD Memory working" << endl;
    }
};

int main(int argc, const char* argv[]) {

    XiJieHardDisk *xiJieHardDisk = new XiJieHardDisk();
    InterCpu *interCpu = new InterCpu();
    JSDMemory *jsdMemory = new JSDMemory();

    Computer *computer = new Computer(interCpu,jsdMemory,xiJieHardDisk);
    computer->work();
   return 0;
}