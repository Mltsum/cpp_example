// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  map可以存放指针
 *
 */
#define LENTH 10
class Interpreter{
public:

private:
    int m_data;
};

using namespace  std;
int main () {

    /*
     * 注意指针的书写形式
     */
    map<int, Interpreter*> mInterpreter;

    Interpreter *interpreter = new Interpreter();

    mInterpreter.insert(pair<int, Interpreter*>(1, interpreter));


    return 0;
}