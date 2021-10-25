#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>

/*
 * sort中的自定义排序：相同的值位置不变。暂时没找到如何定义相同值调换规则的方法
 */

#define ESP 1E-8

using namespace std;

class ca{
public:

};


int main(){
    map<int, ca*> mapv;
    ca *ca1;
    ca *ca2;
    ca *ca3;
    ca *ca4;
    ca *ca5;
    mapv.insert(make_pair(1,ca1));
    mapv.insert(make_pair(2,ca2));
    mapv.insert(make_pair(3,ca3));
    mapv.insert(make_pair(4,ca4));
    mapv.insert(make_pair(5,ca5));

    if(mapv[4] != nullptr){
        cout << "yes" << endl;

    } else{
        cout << "none" << endl;
    }

}