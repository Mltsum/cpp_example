#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

/*
 * sort中的自定义排序：相同的值位置不变。暂时没找到如何定义相同值调换规则的方法
 */

#define ESP 1E-8

using namespace std;

bool CompByValue(pair<int,float> val1, pair<int, float> val2){
    if(abs(val1.second - val2.second) < ESP){
        return val1.second < val2.second;
    }
    return val1.second > val2.second;
}

int CompByValue1(pair<int,float> val1, pair<int, float> val2){
//    if(abs(val1.second - val2.second) <= ESP){
//        return 0;
//    }
    return val1.second > val2.second;
}

int main(){

    vector<pair<int, float>> vecf;
    vecf.push_back(pair<int, float>(0,0.073061117));
    vecf.push_back(pair<int, float>(1,0.173061117));
    vecf.push_back(pair<int, float>(2,0.173061117));
    vecf.push_back(pair<int, float>(3,0.273061117));

//    sort(vecf.begin(), vecf.end(),CompByValue);
    sort(vecf.begin(), vecf.end(),CompByValue1);

}