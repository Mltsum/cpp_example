//
// Created by mingren on 2022/11/30.
//

#ifndef TEST_CLASSMACRO_H
#define TEST_CLASSMACRO_H

#include <iostream>
#include <mutex>

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

#define GET_INSTANCE(TYPE)  TYPE::getInstance()

#define DEF_INSTANCE(TYPE)  static TYPE * getInstance();

#define IMPL_INSTANCE(TYPE,IMPL)                            \
static std::mutex mMutex;                                   \
static TYPE* sInstance = nullptr;                           \
TYPE* TYPE::getInstance(){                                  \
    static std::unique_lock<std::mutex> lock(mMutex);       \
    if(nullptr == sInstance){                               \
        sInstance = new IMPL();                             \
    }                                                       \
    return sInstance;                                       \
}

/**
 * 创建对象,创建的对象需自己释放
 * TYPE:接口类名
 * CREATE获取的对象需自行释放
 */
#define CREATE(TYPE)                        \
 TYPE::create()                             \

// TYPE:接口类名
#define DEF_CREATE(TYPE)                    \
static TYPE* create();                      \

// TYPE:接口类名,IMPL:实现类名
#define IMPL_CREATE(TYPE,IMPL)              \
TYPE* TYPE::create(){                       \
    return new IMPL();                      \
}                                           \


#endif //TEST_CLASSMACRO_H
