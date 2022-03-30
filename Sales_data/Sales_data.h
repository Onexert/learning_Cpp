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
    double avg_price() const
    {
        return units_sold ? revenue / units_sold : 0;
    } /* data */
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n)
    {
    }
    Sales_data(std::istream &);

    std::string isbn() const { return bookNo; } /* 返回对象的ISBN */
    Sales_data &combine(const Sales_data &);    // 用于将一个Sales_data对象加到另一个对象上
};


Sales_data add(const Sales_data &, const Sales_data &);  //执行两个对象的假发
std::ostream &print(std::ostream &, const Sales_data &); //读用户输入数据
std::istream &read(std::istream &, Sales_data &);        //将数据输出

#endif