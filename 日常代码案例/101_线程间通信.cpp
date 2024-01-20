/* ***************************************************
 * Copyright © 2020 AutoNavi Software Co.,Ltd. All rights reserved.
 * File:    main.cpp
 * Purpose: for unite test
 * Author:  mingren (mingren.ms@autonavi.com)
 * Version: 1.0
 * Date:    2020/11/18
 * Update:
 *****************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <thread>


class Model1{
public:
    bool proc(){
        std::cout<< "-> running model1...." << std::endl;
    }

    void setFlag(bool flag){
        this->flag = flag;
    }

    bool getFlag(){
     return this->flag;
    }

private:
    bool flag;
};


void switch_func(Model1 *model){
    bool init_flag = false;
    while(true){
        init_flag = !init_flag;
        model->setFlag(init_flag);
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}

void proc_func(Model1 *model){
    while(true){
        if(model->getFlag()){
            std::cout<< "-> mode1 running...." << std::endl;
        } else {
            std::cout<< "-> mode2 running...." << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    std::cout<< "-> enter main...." << std::endl;

    Model1 *model1 = new Model1;
    model1->setFlag(false);

    std::thread thread1(switch_func, model1);
    std::thread thread2(proc_func, model1);

    thread1.join();
    thread2.join();

    std::cout<< "-> exit main...." << std::endl;
    return 0;
}
