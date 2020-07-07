#include <iostream>
#include <array>
#include <memory>

/*
 * 判断子串
 */

#include <io.h>
#include <string>

using namespace std;

int main(){
    std::string str1 = "1572832113092_c67fe250-46d1-40d4-8d71-e7a7d71bd9e2.webp";
    std::string str2 = "webp";

    cout <<  str1.find(str2) << endl;       // result is 51(position)

    if(str1.find(str2) != std::string::npos){
        cout << "include" << endl;
    } else {
        cout << "not include" << endl;
    }
}