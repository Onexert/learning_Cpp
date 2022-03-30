#include <iostream>

class Apple
{
private:
    int people[100]; /* data */
public:
    Apple(int i);
    const int apple_number;
    void take(int num) const;
    int add(int num);
    int add(int num) const;
    int getCount() const;
};

Apple::Apple(int i) : apple_number(i)
{
}

int Apple::add(int num)
{
    take(num);
}

int Apple::add(int num) const
{
    take(num);
}

void Apple::take(int num) const
{
    std::cout<<"take func"<<num<<std::endl;
}

int Apple::getCount() const
{
    take(1);
    return apple_number;
}

int main()
{
    Apple a(2);
    std::cout << a.getCount()<<std::endl;
    a.add(10);
    const Apple b(3);
    b.add(100);
    return 0;
}