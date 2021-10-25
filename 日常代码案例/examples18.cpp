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

std::vector<int> classIdx;
std::vector<std::vector<float>> weights;
std::vector<std::vector<float>> bias;

using namespace  std;
int main () {

    string path = "/Users/mingren/Documents/02.MNNHome/Ocr/on_device_TSR/models/multi_frame/SVM_weights.txt";
    ifstream fin;
    fin.open(path);
    if(!fin){
        cout << "文件读取失败" << endl;
    }

    /*
     * 以行输出
     */
    string emptys = " ";
    string line;
    while(getline(fin, line)){
        cout << line.c_str() << endl;
        /*
         * 拆分
         */
        vector<string> lineElements;
        vector<float> weightsElements;
        vector<float> biasElements;
        int pos1 = 0;
        int pos2 = line.find(emptys.c_str());
//        while(pos2 != string::npos){
//            lineElements.push_back(line.substr(pos1, pos2-pos1));
//            pos1 = pos2 + emptys.size();
//            pos2 = line.find(emptys.c_str(), pos1);
//        }

        /*
         * 将三个属性全部分隔开
         */
        int first_pos;
        do{
            lineElements.push_back(line.substr(pos1, pos2-pos1));
            std::string element = line.substr(pos1, pos2-pos1);
            if(pos1 == 0){
                classIdx.push_back(atoi(element.c_str()));
                first_pos = pos2 + emptys.size();
            }
            pos1 = pos2 + emptys.size();
            pos2 = line.find(emptys.c_str(), pos1);
            if (pos1 != first_pos && pos2 != -1){
                weightsElements.push_back(atof(element.c_str()));
            }else if (pos1 != first_pos && pos2 == -1) {
                biasElements.push_back(atof(element.c_str()));
            }
            cout << pos1 << " " << pos2 << endl;
        }while((pos2 > 0));
        weights.push_back(weightsElements);
        bias.push_back(biasElements);
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
