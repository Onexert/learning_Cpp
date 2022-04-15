#include <iostream>

using namespace std;

//父类
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHight(int H)
    {
        height = H;
    }

protected:
    int width;
    int height;
};

// 子类
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
};

int main()
{
    Rectangle Rect;
    Rect.setHight(5);
    Rect.setWidth(6);

    cout << "Total Area: "<< Rect.getArea()<<endl;

    cin.get();
    return 0;
}