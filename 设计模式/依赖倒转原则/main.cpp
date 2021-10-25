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