//
// Created by ZHP on 6/16/21.
//

#include "LeakDetector.hpp"

std::vector<LeakDetector*> LeakDetector::all;

// std::recursive_mutex LeakDetector::mutex;  // NOLINT

void LeakDetector::debugPrintObjects(const std::function<void(const std::string&)>& logger) {
    //    std::lock_guard<std::recursive_mutex> auto_lock(mutex);
    for (auto& it : all) {
        auto name = it->name;
        logger(name);
    }
}

int LeakDetector::run(const std::function<void()>& runnable) {
    auto before = getCurrentCount();
    runnable();
    auto after = getCurrentCount();
    return after - before;  // NOLINT
}
