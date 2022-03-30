#ifndef __SCREEN__
#define __SCREEN__

#include <iostream>
#include <string>
#include <vector>

class Screen
{
public:
    typedef std::string::size_type pos; //定义别名 与下一句等价
    // using pos = std::string::size_type;
    Screen() = default;                                                             //生成默认构造函数
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {} //构造函数
    char get() const { return contents[cursor]; }                                   //读取光标处的字符，隐式内联
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }
    void some_member() const;

private:
    mutable size_t access_ctr;
    pos cursor = 0; //光标位置
    pos height = 0, width = 0; //Screen 的长和宽
    std::string contents;//字符
    void do_display(std::ostream &os) const { os << contents; }
};

class Window_mgr
{
private:
    //这个Window_mgr 追踪的Screen
    //默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; //计算行的位置
    cursor = row + c;    //在行内将光标移动到指定列
    return *this;        //以左值形式返回对象
}

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;      //计算行的位置
    return contents[row + c]; //返回给定列的字符
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c; //设置当前光标所在位置的新值
    return *this;         //以左值形式返回对象
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;//设置给定位置的新值
    return *this;
}
void Screen::some_member() const
{
    ++access_ctr; //保存一个计数值，用于记录成员函数被调用的次数
}

#endif