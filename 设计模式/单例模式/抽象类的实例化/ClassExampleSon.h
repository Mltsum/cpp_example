//
// Created by mingren on 2022/12/1.
//

#ifndef TEST_CLASSEXAMPLESON_H
#define TEST_CLASSEXAMPLESON_H

#include "ClassExample.h"

class ClassExampleSon : public ClassExample{
public:

//    static ClassExample * getInstance();      // 继承

    // 在函数调用的时候，如果该函数在基类中被定义为虚函数，那么在调用的时候看该指针（包括基类指针和派生类指针）所指向的对象，
    // 如果是派生类的对象就调用派生类中重写的函数，如果是基类的对象就调用基类中的函数。
    // 如果该函数为非虚函数，那么看该指针的类型，如果是基类的指针就调用基类中的函数，如果是派生类的指针就调用派生类中的函数。
    // 这种情况是非多态的情况，函数没有实现重写，而只是进行了覆盖。
    void running() override;

    ClassExampleSon();
    ~ClassExampleSon();

public:
    int element = 10;
};

#endif //TEST_CLASSEXAMPLESON_H
