#include <dirent.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <thread>
#include <string>
#include <vector>
#include <functional>
#include <tuple>
#include <string.h>

using namespace std;

/**
 * 设计模式之原型模式(克隆模式)
 *    当需要大批的创建对象时，可以更加灵活的创建。
 *    可以快速保存对象在某个时间点的快照。
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 普通类: 缺点是，在大批创建对象后，如果需要修改类，则全部的对象应用都需要修改。
 */
class Resume{
public:
    Resume(){}
    void setPersonalInfo(const std::string &name, const std::string &age, const std::string &sex){
        this->name = name;
        this->age = age;
        this->sex = sex;
    }
private:
    std::string name;
    std::string sex;
    std::string age;
};

/**
 * 原型模式(克隆模式)
 * 核心是1) 拷贝构造函数 2) return new ResumeWithClone(*this);
 * 当对象比较复杂时，clone可以克隆出当前对象的当前状态！！！, 相当于对对象实现一个当前时间点的快照。
 */
class ResumeWithClone{
public:
    ResumeWithClone(){
        std::cout << "ResumeWithClone Construct !" << std::endl;
    }

    // 涉及到指针时，会有深拷贝和浅拷贝的区别，这点要注意。
    ResumeWithClone(const ResumeWithClone& resumeWithClone){
        this->name = resumeWithClone.name;
        this->age = resumeWithClone.age;
        this->sex = resumeWithClone.sex;
        this->education = resumeWithClone.education;
        std::cout << "ResumeWithClone copy Construct !" << std::endl;
    }

    void SetPersonalInfo(const std::string& name, const std::string& age)
    {
        this->name = name;
        this->age = age;
    }
    void SetEducation(const std::string& educatoin)
    {
        this->education = educatoin;
    }
    void PrintResume()
    {
        std::cout << name << ", " << age  << ", " << education << std::endl;
    }

    // 调用拷贝构造
    ResumeWithClone * clone(){
        return new ResumeWithClone(*this);
    }

private:
    std::string name;
    std::string sex;
    std::string age;
    std::string education;
};

int main(int argc, const char* argv[]) {

    // 普通类构造多个对象
    Resume *resume1 = new Resume();
    Resume *resume2 = new Resume();

    // 原型类构造多个对象
    ResumeWithClone *rc = new ResumeWithClone();
    rc->SetEducation("GDUT");
    rc->PrintResume();

    // 利用原型类进行拷贝，可以避免改变原形类，得更改所有对象的情况。
    ResumeWithClone *rc1 = rc->clone();
    rc1->SetEducation("MIT");
    rc1->PrintResume();

    return 0;
}
