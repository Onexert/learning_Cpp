#ifndef __SCALES_DATA__
#define __SCALES_DATA__

#include <iostream>
#include <string>
#include <vector>

// struct Sales_data
// {
//     Sales_data() = default;
//     Sales_data(const std::string &s) : bookNo(s) {}
//     Sales_data(const std::string &s, unsigned n, double p);
//     Sales_data(std::istream &);

//     std::string isbn() const { return bookNo; } /* 返回对象的ISBN */
//     Sales_data &combine(const Sales_data &);    // 用于将一个Sales_data对象加到另一个对象上
//     double avg_price() const;
//     std::string bookNo;
//     unsigned units_sold = 0;
//     double revenue = 0.0;
// };

class Sales_data
{
    //为sales_data的非成员函数所做的友元声明
    friend Sales_data add(const Sales_data &, const Sales_data &);  //执行两个对象的假发
    friend std::ostream &print(std::ostream &, const Sales_data &); //读用户输入数据
    friend std::istream &read(std::istream &, Sales_data &);        //将数据输出
private:
    inline double avg_price() const
    {
        return units_sold ? revenue / units_sold : 0;
    } /* data */
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    Sales_data() = default;
    Sales_data(const std::string s = "") : bookNo(s) {} //
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n)
    {
    }
    Sales_data(std::istream &is) { read(is, *this); }

    std::string isbn() const { return bookNo; } /* 返回对象的ISBN */
    Sales_data &combine(const Sales_data &);    // 用于将一个Sales_data对象加到另一个对象上
};

// Sales_data add(const Sales_data &, const Sales_data &);  //执行两个对象的假发
// std::ostream &print(std::ostream &, const Sales_data &); //读用户输入数据
// std::istream &read(std::istream &, Sales_data &);        //将数据输出

/*
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this); // read函数的作用是从is中读取一条交易信息然后存入this对象中
}


inline double Sales_data::avg_price() const
{
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else
        return 0;
}

*/

inline Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; //把 rhs 的成员加到 this 对象的成员上
    revenue = +rhs.revenue;
    return *this; // 返回调用该函数的对象
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; //将 lsh 的数据成员拷贝给 sum
    sum.combine(rhs);     ///把 rsh 的数据成员加到 sum 中

    return sum;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();

    return os;
}
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;

    return is;
}

#endif