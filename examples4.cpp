#include <iostream>
#include <array>
#include <memory>

/*
 * 智能指针unique_ptr申请固定长度的数组
 */

#include <io.h>
#include <string>

using namespace std;

int main(){
    std::unique_ptr<float> vars;
    if(vars == nullptr){
        cout << "ptr is nullptr" << endl;
    }

    /*
     * 申请固定长度数组内存
     */
    std::unique_ptr<float> float_ptr(new float[10]);
    for (int i = 0; i < 10; ++i) {
        float_ptr[i] = i;
        cout << float_ptr[i] << " " << endl;
    }

}