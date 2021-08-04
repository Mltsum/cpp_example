#include <dirent.h>
#include <string.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <array>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <tuple>
#include <vector>

using namespace std;

/**
 * 关于C++的memcpy
 *    memecpy 的拷贝是以字节为单位的不论是传入的是浮点指针还是uchar
 *
 *    验证 vector 的push_back是否调用拷贝构造
 */

static int cons = 0;
static int dcons = 0;

class LaneContour {
public:
    double              area;
    int                 label;
    std::vector<double> contour;

    LaneContour(double areaTmp, int labelTmp, double contourTmp) : area(areaTmp), label(labelTmp), contour(contourTmp) {
        cons++;
        cout << "==>构造 = " << cons << endl;
    };

    LaneContour(const LaneContour &obj) {
        cons++;
        cout << "==>拷贝构造 = " << cons << endl;
    }

    ~LaneContour() {
        dcons++;
        cout << "==>析构 = " << dcons << endl;
    };
};

typedef std::vector<LaneContour> contoursPerLabel;

bool func(contoursPerLabel &labels) {
    LaneContour laneContour(0.1, 10, 2.0);
    // vector的push back 其实调用的是拷贝构造
    labels.push_back(laneContour);
    return true;
}

int main(int argc, const char *argv[]) {
    /**
     * 验证 vector 的push_back是否调用拷贝构造
     */
    for (int i = 0; i < 2; ++i) {
        contoursPerLabel tmp;
        func(tmp);
        cout << "---------------" << endl;
    }

    /**
     * 验证memcpy的size是否是字节，答案是是
     */
    float data[10];
    float data2[10];

    for (int i = 0; i < 10; ++i) {
        data[i] = i;
    }

    for (int i = 0; i < 10; ++i) {
        cout << "data[" << i << "] = " << data[i] << endl;
    }

    memcpy(data2, data, 10 * 4);

    cout << "--------------------------" << endl;

    for (int i = 0; i < 10; ++i) {
        cout << "data2[" << i << "] = " << data2[i] << endl;
    }

    return 0;
}