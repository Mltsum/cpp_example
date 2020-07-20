// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>
#include <fstream>
#include <string>

/*
 *  文件按行读出
 */

using namespace  std;
int main () {

    string path = "D:\\Working_repo\\06.deeplearning\\mnn_src\\MNN_Test_Demo\\deliver\\classification_name\\eye.txt";
    ifstream fin;
    fin.open(path);
    if(!fin){
        cout << "文件读取失败" << endl;
    }
    /*
     * 挨个字符输出
     */
//    char ch;
//    while(fin.get(ch)){
//        cout << ch;
//    }

    /*
     * 以行输出
     */
    string emptys = "  ";
    string line;
    while(getline(fin, line)){
        cout << line.c_str() << endl;
        /*
         * 拆分
         */
        vector<string> lineElements;
        int pos1 = 0;
        int pos2 = line.find(emptys.c_str());
        while(pos2 != string::npos){
            lineElements.push_back(line.substr(pos1, pos2-pos1));
            pos1 = pos2 + emptys.size();
            pos2 = line.find(emptys.c_str(), pos1);
        }

        /*
         * 将三个属性全部分隔开
         */
        do{
            lineElements.push_back(line.substr(pos1, pos2-pos1));
            pos1 = pos2 + emptys.size();
            pos2 = line.find(emptys.c_str(), pos1);
        }while((pos2 > lineElements.size()+1));
    }
    fin.close();

    /*
     * substr?
     */
//    vector<string> v;
//    string string1 = "hello world";
//    string1.substr(0,3);
//    v.push_back(string1.substr(0,3));




  return 0;
}