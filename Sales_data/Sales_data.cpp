#include "Sales_data.h"

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this); // read函数的作用是从is中读取一条交易信息然后存入this对象中
}

// inline double Sales_data::avg_price() const
// {
//     if (units_sold)
//     {
//         return revenue / units_sold; /* code */
//     }
//     else
//         return 0;
// }

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

