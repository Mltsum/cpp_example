#include <iostream>
#include <array>
#include <memory>

/*
 *  1. c++中的%d %ld %lld
 *      %d = int = 32bit
 *      #ld = long = 32bit
 *      %lld = long long = 64bit
 */

using namespace std;


// 程序的主函数
int main( )
{
    const static int imageChannel = 3;
    const static int imageWidth = 512;
    const static int imageHeight = 288;

    printf("%d\n",imageChannel*imageWidth*imageHeight);
    printf("%Id\n",imageChannel*imageWidth*imageHeight);
    /*
     * %I32d, 不能用lld。
     */
    printf("%I32d\n",imageChannel*imageWidth*imageHeight);

    return 0;
}