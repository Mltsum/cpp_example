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
 * 设计模式之外观模式
 *    将功能封装起来，主要的代码逻辑里形成统一的接口，其核心思想就是把功能模块化处理.
 *
 *    避免将高层实现直接调用底层模块。而是通过中间封装，将高层实现和底层模块隔离开。
 *
 *    更注重从架构的层次去看整个系统。而不是单个类的层次。外观模式更多的是一种架构模式。
 *
 *    核心是做代码模块层之间的解耦
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 配置文件设置类
 */
class ConfigSetting{
public:
    ConfigSetting(){

    }
    ~ConfigSetting(){

    }

    void initSetting(){
        cout << "start read config file!" << endl;
    }
};

/**
 * 日志管理类
 */
class LogMgr{
public:
    LogMgr(){

    }
    ~LogMgr(){

    }
    void startLogOutput(){
        std::cout << "Start log output!" << std::endl;
    }
};

/**
 * 线程管理类
 */
class ThreadMgr {
public:
    ThreadMgr() {}
    ~ThreadMgr(){}

    void startThreadMgr()
    {
        std::cout << "Start thread management!" << std::endl;
    }
};

/**
 * UI界面类
 */
class LogicUI
{
public:
    LogicUI() {}
    ~LogicUI(){}

    void startLogic()
    {
        std::cout << "Start logic ui model!" << std::endl;
    }
};

/**
 * 主UI
 * 外观类
 */
class MainUI
{
public:
    MainUI() {}
    ~MainUI(){}

    void Init()
    {
        mSetting.initSetting();
        mLogicUI.startLogic();
    }

    void Start()
    {
        mLogMgr.startLogOutput();
        mThreadMgr.startThreadMgr();
    }

private:
    /**
     * 子功能管理
     */
    ConfigSetting         mSetting;
    LogMgr		  mLogMgr;
    ThreadMgr	          mThreadMgr;
    LogicUI		  mLogicUI;
};

int main(int argc, const char* argv[]) {

    /**
     * 在主功能中，调用起各个子功能
     */
    MainUI *mainUi = new MainUI();
    mainUi->Init();
    mainUi->Start();
    return 0;
}
