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
 */
class Segment{
public:
    // 将算法的每个步骤抽析出来，交给派生类实现。同时定义好算法流程的Flow...
    virtual void Threshold()=0;
    virtual void RegionGrow() = 0;
    virtual void FindCoutours() = 0;

public:
    Segment(){}
    ~Segment(){}

    /**
     * 定义算法的流程
     */
    void SegmentFlow(){
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
