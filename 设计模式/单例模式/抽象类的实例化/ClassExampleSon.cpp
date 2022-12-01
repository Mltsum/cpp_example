//
// Created by mingren on 2022/12/1.
//

#include "ClassExampleSon.h"

IMPL_INSTANCE(ClassExample, ClassExampleSon)

ClassExampleSon::ClassExampleSon(){
    std::cout << "ClassExampleSon 构造拉" << std::endl;
}
ClassExampleSon::~ClassExampleSon(){
    std::cout << "ClassExampleSon 析构拉" << std::endl;
}

void ClassExampleSon::running(){
    std::cout << "ClassExampleSon running拉" << std::endl;
}