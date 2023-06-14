//
// Created by mingren on 2022/11/30.
//

#ifndef TEST_CLASSEXAMPLE_H
#define TEST_CLASSEXAMPLE_H

#include "ClassMacro.h"

/**
 * 单例模式
 */
class ClassExample{
public:
    // 单例的要素1: 共有的静态函数，方便获取私有的静态变量
    DEF_INSTANCE(ClassExample);         // 单例的要素2: 私有的静态变量或者编译阶段的宏， 防止直接访问

    virtual void running() = 0;

public:
    ClassExample();
    ~ClassExample();
};

#endif //TEST_CLASSEXAMPLE_H
