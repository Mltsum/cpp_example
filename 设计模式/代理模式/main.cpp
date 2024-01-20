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
 *     相当于一个类实现功能。其他的类其实是套壳。当这个功能改变时，其他类的功能也会改变;
 *     强调的是"变"与"不变";
 *
 *     针对场景:
 *        1. 对象创建开销很大
 *        2. 对象某些操作需要安全控制
 *        3. 进程外访问
 *
 *        直接访问会给类带来安全风险或者代码额外开销
 *
 *    使用代理模式具有以下几个优点：
    1、代理模式能将代理对象与真实被调用的目标对象分离。(真实的角色就是实现实际的业务逻辑，不用关心其他非本职责的事务，通过后期的代理完成一件事务，附带的结果就是编程简洁清晰)
    2、一定程度上降低了系统的耦合度，扩展性好。(具体主题角色是随时都会发生变化的，只要它实现了接口，甭管它如何变化，都逃不脱如来佛的手掌(接口)，那我们的代理类完全就可以在不做任何修改的情况下使用。)
    3、可以起到保护目标对象的作用。(防止目标对象被意外的读写,改变等)
    4、可以对目标对象的功能增强，保护，融合等。(对目标对象的功能进行权限隔离，保护，增强，融合等)
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
