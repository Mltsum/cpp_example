#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>
#include <array>

/*
 *  error: undefined reference to 'vtable for DetectionProcess'
 *  在继承接口类之后，继承的接口函数必须实现， 且函数返回合理。
 *
 */

using namespace  std;

class Base{
public:
    virtual ~Base(){}
    virtual void func1() = 0;
};

class Child : public Base{

    virtual void func1(){
        cout << "func1" << endl;
    }

};


int main () {

    Child *child = new Child();


    if(child){
        delete child;
    }

    return 0;
}