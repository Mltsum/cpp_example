//
// Created by ZHP on 6/16/21.
//

#ifndef ZHP_LEAK_DETECTOR_H
#define ZHP_LEAK_DETECTOR_H

#include <assert.h>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <typeinfo>
#include <vector>

#define LEAK_DETECTOR(type) LeakDetector __leak_companion {#type};

/**
 * 这个类是用来检测内存泄漏的。
 *
 * 作为要检测的类的伴生对象。
 * 当创建时，静态计数 +1，析构时 -1。
 */
class LeakDetector {
public:
    LeakDetector(const std::string& tag) {
        this->name = tag;
        // std::cout << "新对象创建: " << tag << std::endl;
        std::lock_guard<std::recursive_mutex> auto_lock(mutex);
        all.push_back(this);
    }

    ~LeakDetector() {
        std::lock_guard<std::recursive_mutex> auto_lock(mutex);
        for (auto it = all.begin(); it != all.end(); it++) {
            if (*it == this) {
                all.erase(it);
                break;
            }
        }
        // std::cout << "旧对象释放: " << this->name << std::endl;
    }

    std::string name;

    static std::vector<LeakDetector*> all;

    static std::recursive_mutex mutex;

    static size_t getCurrentCount() { return all.size(); }

    static void assertCount(size_t size) { assert(size == getCurrentCount()); }

    static void debugPrintObjects(const std::function<void(const std::string&)>& logger);

    static int run(const std::function<void()>& runnable);
};

#endif
