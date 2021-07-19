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
 * 设计模式之状态模式
 *    允许一个对象在其内部状态改变时改变它的行为。对象看起来似乎修改了它的类。
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 状态基类
 */
class Status{
public:
    Status(){}
    virtual void showStepTip() = 0;
};

/**
 * 汽车驶入状态
 */
class CarInStatus : public Status{
public:
    CarInStatus(){}
    
    void showStepTip(){
        std::cout << "Step1: 请驶入指定位置" << std::endl;
    }
};

/**
 * 驻车状态
 */
class CarStopStatus :public Status {
public:
	CarStopStatus() {}
        
	void showStepTip() override
	{
		std::cout << "Step2: 熄火，挂P档，拉手刹" << std::endl;
	}
};

/**
 * 加油状态
 */
class AddOilStatus :public Status
{
public:
	AddOilStatus() {}

	void showStepTip() override
	{
		std::cout << "Step3: 拾起油枪加注汽油" << std::endl;
	}
};

/**
 * 完成加油状态
 */
class FinishAddStatus :public Status
{
public:
    FinishAddStatus() {}

    void showStepTip() override
    {
        std::cout << "Step4: 放好油枪" << std::endl;
    }
};

/**
 * 汽车驶出状态
 */
class CarOutStatus :public Status
{
public:
    CarOutStatus() {}

    void showStepTip() override
    {
        std::cout << "Step5: 请驶离换电站" << std::endl;
    }
};

/**
 * 状态管理类
 */
class StatusManager{
public:
    // 初始化当前状态
    StatusManager(){}
    // 设置当前状态
    void setStatus(Status* status){
        this->mStatus = status;
    }

    void showCurTip(){
        mStatus->showStepTip();
    }

private:
    Status *mStatus;
};

int main(int argc, const char* argv[]) {
    CarInStatus *initStatus = new CarInStatus();

    // 初始化管理类
    StatusManager *statusManager = new StatusManager();
    statusManager->setStatus(initStatus);
    statusManager->showCurTip();

    CarStopStatus *stopStatus = new CarStopStatus();
    statusManager->setStatus(stopStatus);
    statusManager->showCurTip();

    AddOilStatus *addOilStatus = new AddOilStatus();
    statusManager->setStatus(addOilStatus);
    statusManager->showCurTip();

    FinishAddStatus *finishStatus = new FinishAddStatus();
    statusManager->setStatus(finishStatus);
    statusManager->showCurTip();

    CarOutStatus *carOutStatus = new CarOutStatus();
    statusManager->setStatus(carOutStatus);
    statusManager->showCurTip();

   return 0;
}