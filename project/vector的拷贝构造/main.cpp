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

    LaneContour(const LaneContour &obj) {       // 使用引用的原因是方式防止赋值递归调用。 加const：如果在函数中不会改变引用类型参数的值，加不加const的效果是一样的。而且不加const，编译器也不会报错。但是为了整个程序的安全，还是加上const，防止对引用类型参数值的意外修改。
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