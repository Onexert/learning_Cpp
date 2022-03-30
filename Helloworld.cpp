#include <iostream>

// extern int ext; //被const修饰的变量在不同文件的访问
// extern const int ext;

const int b = 10; //被 const 修饰的变量不能修改，且必须初始化

/**
 * const 与 point
 */


int main()
{
    // // std::cout << (ext + 10) << std::endl;
    // const int *p;
    //  int val = 3;
    // p = &val;
    // int *ptr = &val;
    // *ptr = 4;

    // std::cout << *p << std::endl;
    // std::cout << *ptr << std::endl;

    // int *const ptr1 = &val;
    // int *t = &val;
    // *t = 1;
    // std::cout << *ptr1 << std::endl;
    return 0;
}
