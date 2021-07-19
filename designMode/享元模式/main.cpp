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
 * 设计模式之享元模式
 *    享元模式主要用于避免重复创建相同的对象，以减少内存占用和提高性能
 *    在有大量对象时，有可能会造成内存溢出，我们把其中共同的部分抽象出来，如果有相同的业务请求，直接返回在内存中已有的对象，避免重新创建。
 *     1、系统中有大量对象。
 *     2、这些对象消耗大量内存。
 *     3、这些对象的状态大部分可以外部化。
 *     4、这些对象可以按照内蕴状态分为很多组，当把外蕴对象从对象中剔除出来时，每一组对象都可以用一个对象来代替。
 *     5、系统不依赖于这些对象身份，这些对象是不可分辨的。
 */

#define CHECK_AND_DELETE(ptr) { if(ptr){delete(ptr); (ptr)=NULL;} }

enum ShapeType
{
    SHAPE_TRIANGLE = 0x0000,
    SHAPE_RECTANGLE= 0x0001,
    SHAPE_POLY	   = 0x0002,
    SHAPE_CIRCLE   = 0x0003
};


class Shape{
public:
    Shape(){}
    ~Shape(){}

    virtual void addShape(Shape *){}
    virtual bool removeShape(Shape*){ return false;}
    virtual void showInfo() = 0;

    int id;

protected:
    std::vector<Shape*> vectorLine;

private:
    static int lineCount;
};
int Shape::lineCount = 0;


class Triangle : public Shape
{
public:
    Triangle() :Shape() {}
    ~Triangle() {}

    virtual void addShape(Shape* pShape) override {
        vectorLine.push_back(pShape);
    }

    virtual bool removeShape(Shape* pShape) override {
        for (auto itr = vectorLine.begin(); itr != vectorLine.end(); itr++)
        {
            if (pShape->id == (*itr)->id)
            {
                vectorLine.erase(itr);
                return true;
            }
        }
        return false;
    }

    virtual void showInfo() override {
        std::cout << "ShowInfo in Triangle!" << std::endl;
        for (auto itr : vectorLine)
        {
            itr->showInfo();
        }
    }
};


class Rectamgle :public Shape
{
public:
    Rectamgle() :Shape() {}
    ~Rectamgle() {}

    virtual void addShape(Shape* pShape) override
    {
        vectorLine.push_back(pShape);
    }

    virtual bool removeShape(Shape* pShape) override {
        for (auto itr = vectorLine.begin(); itr != vectorLine.end(); itr++)
        {
            if (pShape->id == (*itr)->id)
            {
                vectorLine.erase(itr);
                return true;
            }
        }
        return false;
    }

    virtual void showInfo() override {
        std::cout << "ShowInfo in Rectamgle!" << std::endl;
        for (auto itr : vectorLine)
        {
            itr->showInfo();
        }
    }
};


class Polygon :public Shape
{
public:
    Polygon() :Shape() {}
    ~Polygon() {}

    virtual void addShape(Shape* pShape) override {
        vectorLine.push_back(pShape);
    }

    virtual bool removeShape(Shape* pShape) override {
        for (auto itr = vectorLine.begin(); itr != vectorLine.end(); itr++)
        {
            if (pShape->id == (*itr)->id)
            {
                vectorLine.erase(itr);
                return true;
            }
        }
        return false;
    }

    virtual void showInfo() override {
        std::cout << "ShowInfo in Polygon!" << std::endl;
        for (auto itr : vectorLine)
        {
            itr->showInfo();
        }
    }
};


class Circle :public Shape
{
public:
    Circle() :Shape() {}
    ~Circle() {}
    virtual void showInfo() override {
        std::cout << "ShowInfo in Circle!" << std::endl;
        for (auto itr : vectorLine)
        {
            itr->showInfo();
        }
    }
};


class ShapeFactory
{
public:
    ShapeFactory() {}
    ~ShapeFactory()
    {
        for (auto itr = mShapeMap.begin();itr != mShapeMap.end();itr++)
        {
            itr = mShapeMap.erase(itr);
        }
    }
    Shape* GetShape(ShapeType type)
    {
        auto itr = mShapeMap.find(type);
        if (itr != mShapeMap.end())
        {
            std::cout << "Get shape without new object!" << std::endl;
            return itr->second;
        }
        else
        {
            switch (type)
            {
                case SHAPE_TRIANGLE:
                {
                    Triangle* triangle = new Triangle();
                    mShapeMap[SHAPE_TRIANGLE] = triangle;
                    return triangle;
                }
                    break;
                case SHAPE_RECTANGLE:
                {
                    Rectamgle* rectangle = new Rectamgle();
                    mShapeMap[SHAPE_TRIANGLE] = rectangle;
                    return rectangle;
                }
                    break;
                case SHAPE_POLY:
                {
                    Polygon* poly = new Polygon();
                    mShapeMap[SHAPE_POLY] = poly;
                    return poly;
                }
                    break;
                case SHAPE_CIRCLE:
                {
                    Circle* circle = new Circle();
                    mShapeMap[SHAPE_CIRCLE] = circle;
                    return circle;
                }
                    break;
                default:
                    break;
            }
        }
    }

private:
    std::map<ShapeType, Shape*> mShapeMap;
};

int main(int argc, const char* argv[]) {

    ShapeFactory* factory = new ShapeFactory();

    Shape* triangle = factory->GetShape(SHAPE_TRIANGLE);
    triangle->showInfo();

    Shape* rect = factory->GetShape(SHAPE_RECTANGLE);
    rect->showInfo();

    Shape* poly = factory->GetShape(SHAPE_POLY);
    poly->showInfo();

    Shape* circle = factory->GetShape(SHAPE_CIRCLE);
    circle->showInfo();

    Shape* poly_copy = factory->GetShape(SHAPE_POLY);
    poly_copy->showInfo();

   return 0;
}