#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>
#include <array>
#include <memory>

/*
 *  初始化
 *
 */

using namespace  std;

class DetectionParams {
public:
    // 可配置
    std::string model_path;
    std::string image_path;
};

class Base{
public:
    Base(){
        cout << "构造" << endl;
        detection_params = new DetectionParams();       // 在new时，需要找到class的实体，用前置声明不行， 必须将类定义到new之前
    }
    ~Base(){
        cout << "析构" << endl;
        delete detection_params;
    }
    void init();

private:
    DetectionParams *detection_params;      // 其实这里只是声明了一个空指针。 需要new来分配地址
    DetectionParams detection_params1;      // 最好不要用指针。这样省去了构造和析构函数的new和malloc
};


void Base::init() {
    detection_params->model_path = "/sdcard/mingren.ms/deliver/detect-quan.mnn";
    cout << detection_params->model_path << endl;
    detection_params->image_path = "/sdcard/mingren.ms/20Q3_tsr_data_yj/1/";
    cout << detection_params->image_path << endl;

    detection_params1.model_path = "/sdcard/mingren.ms/deliver/detect-quan.mnn";
    cout << detection_params->model_path << endl;
    detection_params1.image_path = "/sdcard/mingren.ms/20Q3_tsr_data_yj/1/";
    cout << detection_params->image_path << endl;
}


int main () {
//    Base *a = new Base();     // Base *a 和 Base a; 区别不仅仅是表示: 在使用上同样有区别

    std::unique_ptr<Base> a(new Base);      // 或者用智能指针

    a->init();

//    delete a;

    return 0;
}