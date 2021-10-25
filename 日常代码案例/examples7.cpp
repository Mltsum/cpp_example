#include <iostream>
#include <array>
#include <memory>

/*
 *  1. c++中的undefine行为：1）内存的越界访问  2）空指针的访问
 *  2. c++中的接口:指的是函数的签名，或者类的可访问元素（比如某个class的public, private, protect接口）
 *  3. 操作符重载
 *  4. TR1（technical report 1）：是一份规范，描述c++标准程序库的许多新机能
 *      std::tr1::ignore()
 *  5. boost库
 *
 */

using namespace std;

/*
 * rhs : right-handle-side    lhs: left-handle-side
 */
// Overloaded 'operator*' must have at least one parameter of class or enumeration type
//const int operator*(const int &lhs, const int &rhs);


class Box
{
public:

    double getVolume(void)
    {
        return length * breadth * height;
    }
    void setLength( double len )
    {
        length = len;
    }

    void setBreadth( double bre )
    {
        breadth = bre;
    }

    void setHeight( double hei )
    {
        height = hei;
    }

    /*
     * 重载 + 运算符，用于把两个 Box 对象相加
     * 对象作为参数进行传递，对象的属性使用 this 运算符进行访问
     */
    Box operator+(const Box& b)
    {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }

private:
    double length;      // 长度
    double breadth;     // 宽度
    double height;      // 高度
};
// 程序的主函数
int main( )
{
    Box Box1;                // 声明 Box1，类型为 Box
    Box Box2;                // 声明 Box2，类型为 Box
    Box Box3;                // 声明 Box3，类型为 Box
    double volume = 0.0;     // 把体积存储在该变量中

    // Box1 详述
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    // Box2 详述
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    // Box1 的体积
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume <<endl;

    // Box2 的体积
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume <<endl;

    // 把两个对象相加，得到 Box3
    Box3 = Box1 + Box2;

    // Box3 的体积
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume <<endl;

    return 0;
}