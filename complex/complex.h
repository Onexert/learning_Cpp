#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>

class complex
{
private:
    double re, im; /* data */
public:
    // 列表初始化 加快运行速度
    complex(double r, double i)
        : re(r), im(i)
    {
    }
    double real() const { return re; } // 函数在class内定义为inline函数
    double imag() const { return im; } // 常量成员函数 const修饰函数

    complex &operator+=(const complex &);

     // 成员函数是该类其他对象的友元函数
    int func(const complex &param)
    {
        return param.im + param.re;
    }
    // 友元函数破坏了封装性 可以访问对象的私有成员 友元函数不属于成员函数 定义在类的外面
friend complex &__doapl(complex *, const complex &);
friend int test_friend(const complex& c, const complex& b);
};

inline complex &__doapl(complex *ths, const complex &r)
{
    ths->re += r.re;
    ths->im += r.im;

    return *ths;
}

// +=重载之后 默认会传递一个指针指向被作用的对象
// 所有的成员函数都包含一个隐藏的参数 this 调用者的指针
// 重载需要返回引用
inline complex &complex::operator+=(const complex &x)
{
    // this 指向调用者 是指针
    return __doapl(this, x);
}

inline double real(const complex &x)
{
    return x.real();
}

inline double imag(const complex &x)
{
    return x.imag();
}

inline complex operator+(const complex &x, const complex &y)
{
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator+(double x, const complex &y)
{
    return complex(x + real(y), imag(y));
}

inline complex operator+(const complex &x, double y)
{
    return complex(real(x) + y, imag(x));
}

inline complex operator+(const complex &x)
{
    return x;
}

inline complex operator-(const complex &x)
{
    return complex(-real(x), -imag(x));
}

std::ostream &operator<<(std::ostream &os, const complex &x)
{
    return os << '(' << real(x) << ','
              << imag(x) << ')';
}
#endif