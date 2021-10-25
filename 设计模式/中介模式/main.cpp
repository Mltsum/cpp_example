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
 * 设计模式之中介者模式(桥模式)
 * 主要解决：对象与对象之间存在大量的关联关系，这样势必会导致系统的结构变得很复杂，同时若一个对象发生改变，我们也需要跟踪与之相关联的对象，同时做出相应的处理。
 * 何时使用：多个类相互耦合，形成了网状结构。
 * 如何解决：将上述网状结构分离为星型结构。
 *
 * 编译时依赖转换为运行时依赖。
 *
 * 多态是大部分设计模式的基础。
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

class Mediator;
/**
 * 对象基类
 * 只有顶层的虚函数加上virtual，其余子类在覆写时全部用override来标记。
 */
class Object {
public:
    Object(){}
    virtual ~Object(){}
    virtual void setMediator(Mediator* media) = 0;
    virtual void sendMsg(std::string &msg) = 0;
    virtual void receiveMsg(std::string &msg) = 0;

protected:
    Mediator* mMediator;        // 各个Object必须绑定一个中介者。 这个中介最好显示的绑定。
};

/**
 * 设置中介者
 */
class Mediator {
public:
    Mediator(){}
    ~Mediator(){}

    void setObj(Object* obj){
        mObject = obj;
    }
    void sendMsg(std::string &msg){
        mObject->receiveMsg(msg);
    }
private:
    Object *mObject;       // 其中中介要实现各个Object的联系，必须要有一个指针来实现动态绑定。
};

/**
 * 对象1
 * final : 表示本类禁止任何类继承本类
 */
class Manager final : public Object
{
public:
    void setMediator(Mediator* media) override
    {
        mMediator = media;
    }
    void sendMsg(std::string &str) override
    {
        std::cout << "Send message=>>Manager" << std::endl;
        mMediator->sendMsg(str);
    }
    void receiveMsg(std::string &str) override
    {
        std::cout << "我是管理者，我接收到的信息是:" << str << std::endl;
    }
};

class Staff final : public Object
{
public:
    void setMediator(Mediator* media) override
    {
        mMediator = media;
    }
    void sendMsg(std::string &str) override
    {
        std::cout << "Send message=>>Staff" << std::endl;
        mMediator->sendMsg(str);
    }
    void receiveMsg(std::string &str) override
    {
        std::cout << "我是员工，我接收到的信息是:" << str << std::endl;
    }
};

class Boss final : public Object
{
public:
    void setMediator(Mediator* media) override
    {
        mMediator = media;
    }
    void sendMsg(std::string &str) override
    {
        std::cout << "Send message=>>Boss" << std::endl;
        mMediator->sendMsg(str);
    }
    void receiveMsg(std::string &str) override
    {
        std::cout << "我是老板，我接收到的信息是:" << str << std::endl;
    }
};

int main(int argc, const char* argv[]) {
    std::string msg;

    /**
     * 设置各个角色
     */
    Mediator *mediator = new Mediator();
    Manager *manager = new Manager();
    Staff *staff = new Staff();
    Boss *boss = new Boss();

    /**
     * 各个角色来设置自己的中介是谁
     */
    manager->setMediator(mediator);
    staff->setMediator(mediator);
    boss->setMediator(mediator);

    /**
     * 中介开始发号施令
     */
    mediator->setObj(manager);
    msg = "主管,你是个傻逼！";
    mediator->sendMsg(msg);

    mediator->setObj(staff);
    msg = "员工，我们是好朋友";
    mediator->sendMsg(msg);

    mediator->setObj(boss);
    msg = "老板，给我一万个月的年终奖可好";
    mediator->sendMsg(msg);

    CHECK_AND_DELETE(manager)
    CHECK_AND_DELETE(staff)
    CHECK_AND_DELETE(boss)

    return 0;
}
