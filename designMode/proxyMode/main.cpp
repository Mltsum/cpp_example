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
 * 设计模式之代理模式
 *     一个类，代表另一个类的功能
 *     创建具有现有对象的对象，以便向外界提供功能接口。
 *     相当于一个类实现功能。其他的类其实是套壳。当这个功能改变时，其他类的功能也会改变
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

/**
 * 设置一个游戏类
 */
class Game{
public:
    Game(std::string name){ mGameName = name;}
    ~Game(){}
    std::string getGameName(){ return mGameName;}

private:
    std::string mGameName;
};

/**
 * 定义玩家类型
 */
class Player{
public:
    Player(Game *game){
        mGame = game;
    }
    virtual ~Player(){}

    virtual void printGameName() = 0;
    virtual void PlayGame() = 0;

protected:
    Game * mGame;
};

/**
 * 代理玩家
 */
class ProxyPlayer :public Player
{
public:
    ProxyPlayer(Game* game):Player(game)
    {
        mGame = game;
    }
    ~ProxyPlayer(){}

    void printGameName()
    {
        std::cout << "I am ProxyPlayer,Game name:" << mGame->getGameName()<< std::endl;
    }
    void PlayGame()
    {
        std::cout << "Start play game with ProxyPlayer." << std::endl;
    }
};

/**
 * 初级玩家
 */
class PrimaryPlayer :public Player
{
public:
    PrimaryPlayer(Game* game):Player(game)
    {
        mProxyPlayer = new ProxyPlayer(game);
    }
    ~PrimaryPlayer(){
        if(mProxyPlayer){
            delete mProxyPlayer;
        }
    }

    void printGameName()
    {
        std::cout << "I am PrimaryPlayer,Game name:" << mGame->getGameName()<< std::endl;
        mProxyPlayer->printGameName();
    }
    void PlayGame()
    {
        std::cout << "Start play game with PrimaryPlayer." << std::endl;
        mProxyPlayer->PlayGame();
    }

private:
    ProxyPlayer* mProxyPlayer;
};

/**
 * 中级玩家
 */
class MediumPlayer :public Player
{
public:
    MediumPlayer(Game* game):Player(game)
    {
        mProxyPlayer = new ProxyPlayer(game);
    }
    ~MediumPlayer(){
        if(mProxyPlayer){
            delete mProxyPlayer;
        }
    }

    void printGameName()
    {
        std::cout << "I am MediumPlayer,Game name:" << mGame->getGameName()<< std::endl;
        mProxyPlayer->printGameName();
    }
    void PlayGame()
    {
        std::cout << "Start play game with MediumPlayer." << std::endl;
        mProxyPlayer->PlayGame();
    }

private:
    ProxyPlayer* mProxyPlayer;
};


int main(int argc, const char* argv[]) {

    // 定义一个游戏
    std::string gameName = "LOL";
    Game *game = new Game(gameName);

    // 代理玩游戏
    cout << "*********** 代理玩游戏 ***********" << endl;
    ProxyPlayer *proxyPlayer = new ProxyPlayer(game);
    proxyPlayer->printGameName();
    proxyPlayer->PlayGame();

    // 初级玩家玩游戏
    cout << "*********** 初级玩游戏 ***********" << endl;
    PrimaryPlayer *primaryPlayer = new PrimaryPlayer(game);
    primaryPlayer->printGameName();
    primaryPlayer->PlayGame();

    // 中级玩家玩游戏
    cout << "*********** 中级玩游戏 ***********" << endl;
    MediumPlayer *mediumPlayer = new MediumPlayer(game);
    mediumPlayer->printGameName();
    mediumPlayer->PlayGame();

    CHECK_AND_DELETE(game)
    CHECK_AND_DELETE(proxyPlayer)
    CHECK_AND_DELETE(primaryPlayer)
    CHECK_AND_DELETE(mediumPlayer)
    return 0;
}
