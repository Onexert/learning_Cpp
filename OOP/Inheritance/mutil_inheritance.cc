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

class PaintCost
{
public:
    int getCost(int area)
    {
        return area * 70;
    }
};

// 子类
class Rectangle : public Shape, public PaintCost
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

    int area = Rect.getArea();

    cout << "Total Area: "<< area<<endl;

    cout<< "Total paint cost: $" <<Rect.getCost(area)<< endl;

    cin.get();
    return 0;
}