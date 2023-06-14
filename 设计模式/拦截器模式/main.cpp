#include "opencv2/opencv.hpp"

/**
 * 拦截器模式:
 * 认证/授权/记录日志，或者跟踪请求.
 * 适用于操作Target前后处理时, 业务中"变化"和"扩展比较频繁"的情况。
 * 必备要素:
 * 要素1: 抽象的切片以及可扩展的切片实例; 目标进程;
 * 要素2: 定义切片和target管理和运行顺序的切片链;
 * 要素3: 应用: 插入切片，执行target, 会自动按照(2)定义的顺序执行。
 */

/**
 * 定义切片接口
 */
class Interceptor{
public:
    virtual void execute(std::string request) = 0;
};

/**
 * 创建切片实体
 */
class AuthenticationInterceptor : public Interceptor{
public:
    void execute(std::string request) override{
        std::cout << "Authenticating request:" << request << std::endl;
    }
};

class LogInterceptor: public Interceptor{
public:
    void execute(std::string request) override{
        std::cout << "debug log:" << request << std::endl;
    }
};

/**
 * 创建执行对象
 */
class Target{
public:
    std::string execute(std::string request){
        std::cout << "Executing request:" << request << std::endl;
        return "success";
    }
};

/**
 * 创建切片器链
 */
class InterceptorChain{
public:
    void addInterceptors(Interceptor *interceptor){
        this->interceptors.push_back(interceptor);
    }

    void setTarget(Target target){
        this->target = target;
    }

    std::string execute(std::string request){
        for(auto &interceptor : this->interceptors){
            interceptor->execute(request);
        }
        return target.execute(request);
    }
private:
    std::list<Interceptor*> interceptors;
    Target target;
};

class InterceptorManager{
public:
    InterceptorManager(Target target){
        this->interceptorChain = new InterceptorChain();
        this->interceptorChain->setTarget(target);
    }

    ~InterceptorManager(){
        if(this->interceptorChain){
            delete this->interceptorChain;
            this->interceptorChain = nullptr;
        }
    }

    void addInterceptor(Interceptor *interceptor){
        if(this->interceptorChain){
            this->interceptorChain->addInterceptors(interceptor);
        } else {
            std::cout << "this->InterceptorsChain nullptr, raise error!!!" << std::endl;
        }
    }

    std::string interceptorRequest(std::string request){
        std::string res;
        if(this->interceptorChain){
            res = interceptorChain->execute(request);
        } else {
            std::cout << "this->InterceptorsChain nullptr, raise error!!!" << std::endl;
        }
        return res;
    }

private:
    InterceptorChain *interceptorChain;
};

/**
 * 创建客户端client
 */
class Client{
public:
    void setInterceptorManager(InterceptorManager *manager){
        this->interceptorManager = manager;
    }

    std::string sendRequest(std::string request){
        return this->interceptorManager->interceptorRequest(request);
    }

private:
    InterceptorManager *interceptorManager;
};


int main(int argc, char** argv) {
    Target target;
    InterceptorManager *interceptorManager = new InterceptorManager(target);
    AuthenticationInterceptor *authenticationInterceptor = new AuthenticationInterceptor();
    LogInterceptor *logInterceptor = new LogInterceptor();
    interceptorManager->addInterceptor(authenticationInterceptor);
    interceptorManager->addInterceptor(logInterceptor);

    Client client;
    client.setInterceptorManager(interceptorManager);
    std::cout << client.sendRequest("HOME") << std::endl;
    return 0;
}