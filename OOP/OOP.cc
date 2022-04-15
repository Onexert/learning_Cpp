/*
继承加组合不同情况下的构造和析构
*/

#include <iostream>

using namespace std;
#if 1
/*
1.   Base　　Derived 既继承　Base 又组合　Composition
    　|
   Derived -> Composition
运行结果：　　Base:[Inside Constructor]
　　　　　　　Composition:[Inside Constructor]
　　　　　　　Derived:[Inside Constructor]
　　　　　　　Derived: [Inside Destructor]
　　　　　　　Compositito: [Inside Destructor]
　　　　　　　Base: [Inside Destructor]
构造：先构造Base(继承类)再构造Composition(组合)最后在构造自己
Derived::Derived:Base(),Composition() {}
Derived::~Derived()
{
    ~Composition();
    ~Base():
}
析构：与构造顺序相反
*/

class Base
{
public:
    Base()
    {
        cout << "Base:[Inside Constructor]\n";
    }
    ~Base()
    {
        cout << "Base: [Inside Destructor]\n";
    }
};

class Composition
{
public:
    Composition(/* args */)
    {
        cout << "Composition:[Inside Constructor]\n";
    }
    ~Composition() /* data */
    {
        cout << "Compositito: [Inside Destructor]\n";
    }

private:
    int a;
};

class Derived : public Base
{

public:
    /* data */
    Derived();
    ~Derived();

protected:
    int data;
    Composition composition;
};

Derived::Derived() : Base()
{
    cout << "Derived:[Inside Constructor]\n";
}

Derived::~Derived()
{
    cout << "Derived: [Inside Destructor]\n";
}

int main()
{
    int x = 0;
    if (x == 0)
        Derived de;
    cin.get();
    return 0;
}
#else
/*
2. Derived 继承Base,Base 组合 Composition
　　Derived　-> Base -> Composition
构造：
    Base::Base:Composition（）
    Derived::Derived:Base() {}
析构：
Derived::~Derived()
{
    ~Base();
    ~Composition();
}

输出结果：　
        Composition:[Inside Constructor]
        Base:[Inside Constructor]
        Derived:[Inside Constructor]
        Derived: [Inside Destructor]
        Base: [Inside Destructor]
        Compositito: [Inside Destructor]
*/
class Base;

class Composition
{
public:
    Composition(/* args */);

    ~Composition(); /* data */

protected:
    int data;
    size_t size;
};

Composition::Composition()
{
    cout << "Composition:[Inside Constructor]\n";
}
Composition::~Composition()
{
    cout << "Compositito: [Inside Destructor]\n";
}
class Base
{
private:
    Composition a;
    int base;

public:
    Base();

    ~Base();
};

Base::Base()
{
    cout << "Base:[Inside Constructor]\n";
}
Base::~Base()
{
    cout << "Base: [Inside Destructor]\n";
}
class Derived : public Base
{

public:
    /* data */
    Derived();
    ~Derived();
};

Derived::Derived()
{
    cout << "Derived:[Inside Constructor]\n";
}

Derived::~Derived()
{
    cout << "Derived: [Inside Destructor]\n";
}

int main()
{
    int x = 0;
    if (x == 0)
        Derived de;
    cin.get();
    return 0;
}

#endif