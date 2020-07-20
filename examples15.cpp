// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <map>
#include <list>

/*
 * 自定义sort的比较函数
 *     1) 可以传入一个函数指针，或者传入一个函数对象
 *     2) sort 会修改容器中的值
 *     3) 如何对map中的value进行排序？
 *          1. map是序列式容器，本身已经按照value进行排序
 *          2. sort算法只能对序列容器进行排序，就是线性的（如vector，list，deque）。map也是一个集合容器，它里面存储的元素是pair，但是它不是线性存储的
 *            （前面提过，像红黑树），所以利用sort不能直接和map结合进行排序。
 *          3. 一种思路是转换为pair,存放到list或者vector中，再自定义比较函数。
 */
using namespace std;

const static float esp = 1E-6;

bool Compare(pair<int,float> val1, pair<int, float> val2){
    if(val1.second - val2.second < esp){
        return 0;
    }
    return val1.second > val2.second;
}

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  /*
   * 注意sort中排序的用法
   */
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  /*
   *
   */
    list<pair<int, float>> probs;
    for (int i = 0; i < 10; ++i) {
        probs.push_back(pair<int, float>(i, i*0.1));
    }
    probs.sort(Compare);

    /*
     * 如何取出其中的第一个值(front或者begin指针)或者中间的任何一个值？
     */
    cout << probs.front().second << endl;
    cout << probs.begin()->second << endl;
    probs.pop_front();


  return 0;
}