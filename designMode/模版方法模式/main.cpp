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
 * 设计模式之模版方法模式
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 图像分割类
 *    定义一个操作的算法框架，而将一些步骤延迟到子类中。使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。
 *
 *    应对场景是原子操作不同，流程[稳定]相同的思想。
 *
 *    利用了晚绑定的思想
 *       早绑定: 应用程序调用库程序(库一般都会先应用程序开发出来，应用程序会后开发出来，后开发的函数调用先开发的函数就叫做早绑定)
 *       晚绑定: 库程序调用应用程序(库一般都会先应用程序开发出来，应用程序会后开发出来，先开发的库调用后开发的应用程序就叫做晚绑定)
 *
 *       例如模版方法模式。库中的流程已经实现，运行时，是库中的函数调用应用层实现的原子操作，来实现整个功能，就是晚绑定的一个具体例子
 *          代码中稳定的部分要设计成非虚函数，变化的部分设计成虚函数
 *
 *    非常常用的一个设计模式。
 *
 */

class Segment{
protected:  // 一般都会设计为protected, 因为这些原子方法单独开放出来是没有意义的。只有放在流程里边才有用。
    // 将算法的每个步骤抽析出来，交给派生类实现。同时定义好算法流程的Flow...
    // 代码结构中变化的部分设计成虚函数
    virtual void Threshold() = 0;       // 原子操作, 交给子类实现
    virtual void RegionGrow() = 0;      // 原子操作, 交给子类实现
    virtual void FindCoutours() = 0;    // 原子操作, 交给子类实现

public:
    Segment(){}
    virtual ~Segment(){}                // 任何一个基类的虚函数都应该写为虚析构函数

    /**
     * 定义算法的流程
     */
    void SegmentFlow(){                 // 代码结构中稳定的部分，设计成非虚函数
        // Step1 : 阈值处理
        Threshold();

        // Step2 : 区域生成
        RegionGrow();

        // Step3 : 边缘检测
        FindCoutours();

        // Step...
    }
};

/**
 * 灰度分割
 */
class GrayImgSegment : public Segment{
public:
    GrayImgSegment():Segment(){
    }
    ~GrayImgSegment(){}

protected:
    void Threshold(){
        cout << "call Threshold with GrayImgSegment way" << endl;
    }

    void RegionGrow(){
        cout << "call RegionGrow with GrayImgSegment way" << endl;
    }

    void FindCoutours(){
        cout << "call FindCoutours with GrayImgSegment way" << endl;
    }
};

class RgbImgSegment : public Segment{
public:
    RgbImgSegment() : Segment(){

    }
    ~RgbImgSegment(){

    }

protected:
    void Threshold(){
        cout << "call Threshold with RgbImgSegment way" << endl;
    }

    void RegionGrow(){
        cout << "call RegionGrow with RgbImgSegment way" << endl;
    }

    void FindCoutours(){
        cout << "call FindCoutours with RgbImgSegment way" << endl;

    }
};

class RoadImgSegment : public Segment{
public:
    RoadImgSegment(){

    }
    ~RoadImgSegment(){

    }

protected:
    void Threshold(){
        cout << "call Threshold with RoadImgSegment way" << endl;
    }

    void RegionGrow(){
        cout << "call RegionGrow with RoadImgSegment way" << endl;

    }

    void FindCoutours(){
        cout << "call FindCoutours with RoadImgSegment way" << endl;

    }
};


enum SegmentMode{
    GraySegmentMode,
    RgbSegmentMode,
    RoadSegmentMode,
};

int main(int argc, const char* argv[]) {

    /**
     * 选择算法测试模式：
     */
    SegmentMode segmentMode = GraySegmentMode;

    switch (segmentMode) {
        case GraySegmentMode:
            {
                std::cout << "switch GraySegment Mode..." << endl;
                GrayImgSegment* grayImgSegment = new GrayImgSegment();
                grayImgSegment->SegmentFlow();
            }
            break;
        case RgbSegmentMode:
            {
                std::cout << "switch RgbSegment Mode..." << endl;
                RgbImgSegment* rgbImgSegment = new RgbImgSegment();
                rgbImgSegment->SegmentFlow();
            }
            break;
        case RoadSegmentMode:
            {
                std::cout << "switch RoadImgSegment Mode..." << endl;
                RoadImgSegment* roadImgSegment = new RoadImgSegment();
                roadImgSegment->SegmentFlow();
            }
            break;
        default:
            break;
    }
    return 0;
}
