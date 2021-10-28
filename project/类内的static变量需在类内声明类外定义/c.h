
#include "LeakDetector.hpp"

class C {
public:
    //    LEAK_DETECTOR(C)
    C() {}
    ~C() {}
    int element;
};