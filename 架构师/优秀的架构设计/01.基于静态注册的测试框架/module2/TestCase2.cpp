//
// Created by mingren on 2021/10/25.
//

#include <iostream>
#include "../TestSuite.h"

class TestCase2 : public TestCase {
public:
    virtual bool run() {
        std::cout << "running TestCase2" << std::endl;
        return true;
    }
};
TestSuiteRegister(TestCase2, "module2/TestCase2.cpp");
