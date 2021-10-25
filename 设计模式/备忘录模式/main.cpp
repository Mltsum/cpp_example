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
 * 设计模式之备忘录模式
 *    所谓备忘录模式就是在[不破坏封装]的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，这样可以在以后将对象恢复到原先保存的状态。
 *
 *    目前实现比较小了。
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 操作记录
 */
class Operator{
public:
    Operator(){}
    ~Operator(){}

    void setContent(std::string &str){
        this->content = str;
    }

    std::string getContent(){
        return content;
    }

private:
    std::string content;
};

/**
 * 获取备份操作
 */
class BackUp{
public:
    BackUp(): mCurIndex(0){

    }
    ~BackUp(){
    }

    /**
     * 插入一条备份
     * @param str
     */
    void insertContent(std::string str){
        int curIndex = mContentsMap.size();
        mContentsMap[curIndex] = str;
        mCurIndex = mContentsMap.size() > 1? mContentsMap.size()-1 : mContentsMap.size();
        cout << "insert content : " << str << endl;
    }

    /**
     * 获取上一条备份的内容
     * @param str
     * @return
     */
    bool previousContent(std::string &str){
        if(mCurIndex > 0){
            mCurIndex = mCurIndex - 1;
            str = mContentsMap[mCurIndex];
            return true;
        }
        return false;
    }

    /**
     * 获取下一条备份的内容
     * @param str
     * @return
     */
    bool nextContent(std::string &str){
        if(mCurIndex < mContentsMap.size()-1){
            mCurIndex = mCurIndex + 1;
            str = mContentsMap[mCurIndex];
            return true;
        }
        return false;
    }

    /**
     * 检查是否可以获取上一次备份的操作
     * @return
     */
    bool canPre(){
        return mCurIndex > 0;
    }

    /**
     * 检查是否可以获取下一次备份的操作
     * @return
     */
    bool canNext(){
        return mCurIndex < mContentsMap.size() - 1;
    }

private:
    // int : 存入的index, std::string : 存储的内容
    std::map<int, std::string> mContentsMap;

    // 当前map的索引
    int mCurIndex;
};

/**
 * 撤销和重做操作
 */
class UndoRedo{
public:
    UndoRedo(Operator *opera, BackUp *backup):mOperator(opera), mBackUp(backup){

    }
    ~UndoRedo(){}

    /**
     * 撤销，恢复上次的状态
     * @return
     */
    bool undo(){
        std::string str;
        if(mBackUp->previousContent(str)){
            cout << "undo : " << str << endl;
            return true;
        }
        return false;
    }

    /**
     * 重做
     * @return
     */
    bool redo(){
        std::string str;
        if(mBackUp->nextContent(str)){
            mOperator->setContent(str);
            cout << "redo : " << str << endl;
            return true;
        }
        return false;
    }

    /**
     * 可以撤销
     * @return
     */
    bool canUndo(){
        return mBackUp->canPre();
    }

    /**
     * 可以重做
     * @return
     */
    bool canRedo(){
        return mBackUp->canNext();
    }

private:
    Operator *mOperator;
    BackUp *mBackUp;
};



int main(int argc, const char* argv[]) {

    Operator *opera = new Operator();
    BackUp *backUp = new BackUp();
    UndoRedo *undoRedo = new UndoRedo(opera,backUp);

    std::string str("这是第一条内容!");
    opera->setContent(str);
    backUp->insertContent(opera->getContent());

    std::string str1("这是第二条内容!");
    opera->setContent(str1);
    backUp->insertContent(opera->getContent());

    std::string str2("这是第三条内容!");
    opera->setContent(str2);
    backUp->insertContent(opera->getContent());

    while(undoRedo->canUndo()){
        undoRedo->undo();
    }

    while(undoRedo->canRedo()){
        undoRedo->redo();
    }
    cout << "current Content is " << opera->getContent() << endl;
   return 0;
}