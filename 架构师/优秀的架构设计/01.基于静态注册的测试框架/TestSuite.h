//
//  MNNTestSuite.h
//  MNN
//
//  Created by MNN on 2019/01/10.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef TEST_MNNTEST_H
#define TEST_MNNTEST_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

/**
 * 测试Case的基类
 */
class TestCase {
    friend class TestSuite;

public:
    /**
     * @brief deinitializer
     */
    virtual ~TestCase() = default;

    /**
     * @brief run test case
     */
    virtual bool run() = 0;

private:
    /** case name */
    std::string name;
};

/** test suite */
class TestSuite {
public:
    /**
     * @brief deinitializer
     */
    ~TestSuite();

    /**
     * @brief get shared instance
     * @return shared instance
     */
    static TestSuite* get();

public:
    /**
     * @brief register runable test case
     * @param test test case
     * @param name case name
     */
    void add(TestCase* test, const char* name);

    /**
     * @brief run all registered test case
     */
    static void runAll();

    /**
     * @brief run registered test case that matches in name
     * @param name case name
     */
    static void run(const char* name);

private:
    /** get shared instance */
    static TestSuite* gInstance;

    /** registered test cases */
    std::vector<TestCase*> mTests;
};

/**
 static register for test case
 */
template <class Case>
class TestRegister {
public:
    /**
     * @brief initializer. register test case to suite.
     * @param name test case name
     */
    TestRegister(const char* name) { TestSuite::get()->add(new Case, name); }
    /**
     * @brief deinitializer
     */
    ~TestRegister() {}
};

#define TestSuiteRegister(Case, name) static TestRegister<Case> __r##Case(name)
#define TEST_ASSERT(x)                                        \
    {                                                         \
        int res = (x);                                        \
        if (!res) {                                           \
            printf("Error for %s, %d\n", __func__, __LINE__); \
            return false;                                     \
        }                                                     \
    }

#endif
