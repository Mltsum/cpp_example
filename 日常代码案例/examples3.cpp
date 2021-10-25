#include <stdio.h>
#include <iostream>
/*
 * io.h 存放了便利文件夹的api; 貌似只能在windows下用
 */
#include <io.h>
#include <string>

using namespace std;

int main(){
    std::string inpath = "D:\\\\Working_repo\\\\test\\\\test_images_src\\\\*.txt";
    long handle;
    struct _finddata_t fileinfo;
    handle = _findfirst(inpath.c_str(), &fileinfo);
    if(handle == -1){
        return -1;
    }
    do{
        std::cout << fileinfo.name << std::endl;
    }while (!_findnext(handle, &fileinfo));

    _findclose(handle);
}