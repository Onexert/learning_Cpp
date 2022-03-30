#include <iostream>
#include "Sales_data.h"
#include "Screen.h"

using namespace std;

int main()
{
    /*
    {
        Sales_data total; //保存当前求和结果的变量

    if (read(cin,total)) //读入第一条交易
    {
        Sales_data trans;//保存下一条交易数据的变量
        while(read(cin,trans))//读入剩余的交易
        {
            if (total.isbn() == trans.isbn())//检测isbn
            {
                total.combine(trans);//更新变量total当前值
            }
            else
            {
                print(cout,total) << endl;//输出结果
                total = trans;//处理下一本书
            }

        }
        print(cout,total) << endl;//输出最后一条交易
    }
    else
       { cerr << "No data?!" << endl;}//没有输入，通知用户
}
*/

    Screen myScreen(5, 5, 'X');
    myScreen.display(cout);
    cout << "\n";
    myScreen.move(4, 0).set('#').display(cout);
    cout<<endl;
    char ch = myScreen.get();
    
    cout << ch << endl;
    myScreen.display(cout);
    cout << "\n";

    return 0;
}
