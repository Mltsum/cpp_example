//
// Created by mingren on 2021/10/25.
//
#include <iostream>
#include "../TestSuite.h"

class TestCase1 : public TestCase {
public:
    virtual bool run() {
        std::cout << "running TestCase1" << std::endl;
        return true;
    }
};

TestSuiteRegister(TestCase1, "module1/TestCase1.cpp");
