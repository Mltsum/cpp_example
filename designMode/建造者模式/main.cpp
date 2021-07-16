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
 * 设计模式之建造者模式
 *    把复杂的各种零配件按照约定的规则组装成产品的过程，由于产品的基础元件不会有太大改动，但是基础元件的组合类型时长变化，这种情况下比较适合采用建造者模式来组织软件的框架.
 *
 *    主要解决：主要解决在软件系统中，有时候面临着"一个复杂对象"的创建工作，其通常由各个部分的子对象用一定的算法构成；由于需求的变化，这个复杂对象的各个部分经常面临着剧烈的变化，但是将它们组合在一起的算法却相对稳定。
 *
 *    何时使用：一些基本部件不会变，而其组合经常变化的时候。
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * [产线类] : 描述各部分会经常变化，但整体组合相对稳定的类
 */
class Machine {
public:
    Machine(){}
    ~Machine(){}

    // 经常变化的属性: 对外开放经常变化属性设置的方法
    void setLightName(std::string &name){
        this->mLightName = name;
    }

    // 经常变化的属性：对外开放经常变化属性设置的方法
    void setCameraName(std::string &name){
        this->mCameraName = name;
    }
    // 经常变化的属性：对外开放经常变化属性设置的方法
    void setMotionName(std::string &name){
        this->mMotionName = name;
    }

    // 显示当前对象，经常变化的属性
    void showMachineInfo(){
        std::string context;
        context.append("LightName:").append(mLightName).append("; ");
        context.append("CameraName:").append(mCameraName).append("; ");
        context.append("mMotionName:").append(mMotionName).append("; ");
        cout << context << endl;
    }

private:
    std::string mLightName;
    std::string mCameraName;
    std::string mMotionName;
};

/**
 * [建造者类] : 将上述部分经常变化，但总体元素相对稳定的类，封装成不同的建造者类
 *    建造者类内部继承了对[产线类]的设置和继承
 */
class Assemble {
public:
    Assemble(){
    }
    ~Assemble(){}

    virtual void setParamName(std::string lightName, std::string cameraName, std::string motionName) = 0;
    virtual Machine* getMachine() = 0;
};

/**
 * Apple 组装类
 */
class AssembleApple : public Assemble{
public:
    AssembleApple(){
        mMachine = new Machine();
    }
    ~AssembleApple(){
        CHECK_AND_DELETE(mMachine)
    }

    void setParamName(std::string lightName, std::string cameraName, std::string motionName){
        mMachine->setCameraName(cameraName);
        mMachine->setLightName(lightName);
        mMachine->setMotionName(motionName);
    }

    Machine* getMachine(){
        return mMachine;
    }

private:
    Machine *mMachine;
};

/**
 * huawei组装类
 */
class AssembleHuawei : public Assemble{
public:
    AssembleHuawei(){
        mMachine = new Machine();
    }
    ~AssembleHuawei(){
        CHECK_AND_DELETE(mMachine)
    }

    void setParamName(std::string lightName, std::string cameraName, std::string motionName){
        mMachine->setCameraName(cameraName);
        mMachine->setLightName(lightName);
        mMachine->setLightName(motionName);
    }

    Machine* getMachine(){
        return mMachine;
    }

private:
    Machine *mMachine;
};

class AssembleXiaomi : public Assemble{
public:
    AssembleXiaomi(){
        mMachine = new Machine();
    }
    ~AssembleXiaomi(){
        CHECK_AND_DELETE(mMachine)
    }

    void setParamName(std::string lightName, std::string cameraName, std::string motionName){
        mMachine->setCameraName(cameraName);
        mMachine->setLightName(lightName);
        mMachine->setLightName(motionName);
    }

    Machine* getMachine(){
        return mMachine;
    }

private:
    Machine *mMachine;
};

/**
 * 工厂
 */
class mobileFactory{
public:
    mobileFactory(){

    }
    ~mobileFactory(){

    }

    /**
     * 设置组装产线
     * @param pAss
     */
    void setAssemble(Assemble *pAss){
        mAssemble = pAss;
    }

    /**
     * 获取零部件集合
     * @return
     */
    Machine* getMachine(){
        return mAssemble->getMachine();
    }
private:
    Assemble *mAssemble;
};

int main(int argc, const char* argv[]) {

    mobileFactory factory;

    /**
     * 生产苹果手机
     */
    AssembleApple *aApple = new AssembleApple();
    aApple->setParamName("appleLite","appleCamera","appleMotion");
    factory.setAssemble(aApple);
    factory.getMachine()->showMachineInfo();

    /**
     * 生产华为手机
     */
//    AssembleHuawei *aHuawei = new AssembleHuawei();
//    aHuawei->setParamName("huaweiLite","huaweiCamera","huaweiMotion");
//    factory.setAssemble(aHuawei);
//    factory.getMachine()->showMachineInfo();

    /**
     * 生产小米手机
     */
//    AssembleXiaomi *aXiaomi = new AssembleXiaomi();
//    aXiaomi->setParamName("xiaomiLite","xiaomiCamera","xiaomiMotion");
//    factory.setAssemble(aXiaomi);
//    factory.getMachine()->showMachineInfo();



    return 0;
}
