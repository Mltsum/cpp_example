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
    const static int64_t var64 = 100;

    printf("%d\n",imageChannel*imageWidth*imageHeight);
    printf("%Id\n",imageChannel*imageWidth*imageHeight);
    /*
     * 32bit的数据 %I32d, 不能用lld。
     */
    printf("%I32d\n",imageChannel*imageWidth*imageHeight);

    /*
     * 64bit的数据用%lld或者%I64d
     */
    printf("%lld\n",var64);


    return 0;
}