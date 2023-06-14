//
// Created by mingren on 2022/11/30.
//

#include "ClassMacro.h"
#include "ClassExample.h"

//IMPL_INSTANCE(ClassExample, ClassExample)       // 如果有虚函数(抽象类或者接口类)，则不实例化

ClassExample::ClassExample(){
    std::cout << "ClassExample 构造拉" << std::endl;
}
ClassExample::~ClassExample(){
    std::cout << "ClassExample 析构拉" << std::endl;
}
