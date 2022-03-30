#include <iostream>

#include "complex.h"

int main()
{
    complex test(1,4);
    complex test1(1,5);



    test += test1;
    std::cout << "test plus test1 result: "<<test <<", test1 "<< test1 <<std::endl;
    std::cout << "友元函数测试："<<test.func(test1) << std::endl;
    test = test1 + 1.0;
    std::cout << "+ 操作符重构测试： 复数加上一个常数" << test <<std::endl;

    test = 1.0 + test1;
    std::cout << "+ 操作符重构测试： 常数加上一个复数" <<test << std::endl;
    test  = test + test1;
    std::cout << "+ 操作符重构测试： 复数相加" << test << std::endl;
    std::cin.get();
}