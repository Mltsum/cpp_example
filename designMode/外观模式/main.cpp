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
