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
 * 设计模式之命令模式
 *    将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化, 对请求排队或记录请求日志，以及支持可撤销的操作。
 *    在OOP中，一切都是对象，将请求封装成对象，符合OOP的设计思想，当将客户的单个请求封装成对象以后，我们就可以对这个请求存储更多的信息，使请求拥有更多的能力。
 *    命令模式同样能够把[请求发送者]和[接收者]解耦，使得命令发送者不用去关心请求将以何种方式被处理。
 *
 * 函数模版 和 此思路是一致的。
 *
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 输出类
 */
class Detail{
public:
    // 定义Stream命令执行的场景
    void printStream() { std::cout << "Output type is stream." << std::endl; }

    // 定义Text命令执行的场景
    void printText() { std::cout << "Output type is text." << std::endl; }
};

/**
 * 定义命令类
 */
class Command{                      // 核心是这个虚接口，这样就方便用类来管理不同命令的对象。是命令模式可以执行的核心。
public:
    Command(Detail *detail){
        this->mDetail = detail;
    }

    /**
     * 将command的执行做成接口开放
     */
    virtual void excute() = 0;      // 虚接口规范，接口规范更严格。

protected:
    Detail *mDetail;
};

/**
 * 定义Text命令
 */
class CommandText : public Command{
public:
    // 定义基类细节
    CommandText(Detail *detail):Command(detail){
    }

    // 定义Text命令引发的动作
    void excute() override {
        mDetail->printText();
    }
};

/**
 * 定义Stream命令
 */
class CommandStream : public Command {
public:
    CommandStream(Detail *detail):Command(detail){

    }

    // 定义Stream命令引发的动作
    void excute() override {
        mDetail->printStream();
    }
};

/**
 * 命令管理类
 */
class CommandManager{
public:
    CommandManager(){}
    ~CommandManager(){
        for(auto cmd : mCommands){
            CHECK_AND_DELETE(cmd)
        }
    }
    // 添加命令
    void insertCommand(Command *cmd){
        mCommands.push_back(cmd);
    }

    // 打印全部命令
    bool printCommads(){
        int idx = 0;
        for(auto cmd : mCommands){
            cmd->excute();
        }
    }

private:
    std::vector<Command *> mCommands;
};


int main(int argc, const char* argv[]) {

    /**
     * 定义命令操作的对象
     */
     Detail *detail = new Detail();

    /**
     * 定义不同类型的命令
     */
     CommandStream *commandStream = new CommandStream(detail);
     CommandText *commandText = new CommandText(detail);

    /**
     * 定义命令管理的中间件
     */
     CommandManager *commandManager = new CommandManager();
     commandManager->insertCommand(commandStream);
     commandManager->insertCommand(commandText);

     /**
      * 执行命令
      */
     commandManager->printCommads();

   return 0;
}