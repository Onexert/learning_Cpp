#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>

template <typename T>
class complex;

template <typename T>
    complex<T> &__doapl(complex<T> *, const complex<T> &);

template <typename T>
class complex
{
private:
    T re, im; /* data */
public:
    // 列表初始化 加快运行速度
    complex(T r, T i)
        : re(r), im(i)
    {
    }
    T real() const { return re; } // 函数在class内定义为inline函数
    T imag() const { return im; } // 常量成员函数 const修饰函数

    complex &operator+=(const complex &);

     // 成员函数是该类其他对象的友元函数
    int func(const complex &param)
    {
        return param.im + param.re;
    }
    // 友元函数破坏了封装性 可以访问对象的私有成员 友元函数不属于成员函数 定义在类的外面
//TODO: __doapl <T> 的原理: 
friend complex<T> &__doapl<T>(complex<T> *, const complex<T> &);
//friend int test_friend(const complex& c, const complex& b);
};

template <typename T>
inline complex<T> &__doapl(complex<T> *ths, const complex<T> &r)
{
    ths->re += r.re;
    ths->im += r.im;

    return *ths;
}

// +=重载之后 默认会传递一个指针指向被作用的对象
// 所有的成员函数都包含一个隐藏的参数 this 调用者的指针
// 重载需要返回引用
template <typename T>
inline complex<T> &complex<T>::operator+=(const complex<T> &x)
{
    // this 指向调用者 是指针
    return __doapl(this, x);
}

template <typename T>
inline T real(const complex<T> &x)
{
    return x.real();
}

template <typename T>
inline T imag(const complex<T> &x)
{
    return x.imag();
}

template <typename T>
inline complex<T> operator+(const complex<T> &x, const complex<T> &y)
{
    return complex(real(x) + real(y), imag(x) + imag(y));
}

template <typename T>
inline complex<T> operator+(T x, const complex<T> &y)
{
    return complex(x + real(y), imag(y));
}

template <typename T>
inline complex<T> operator+(const complex<T> &x, T y)
{
    return complex(real(x) + y, imag(x));
}

template <typename T>
inline complex<T> operator+(const complex<T> &x)
{
    return x;
}

template <typename T>
inline complex<T> operator-(const complex<T> &x)
{
    return complex(-real(x), -imag(x));
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const complex<T> &x)
{
    return os << '(' << real(x) << ','
              << imag(x) << ')';
}
#endif