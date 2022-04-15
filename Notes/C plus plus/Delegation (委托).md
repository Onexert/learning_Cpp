## **Delegation（委托）** composition by reference
对于委托而言，正如小标题部分写的这样—— composition by reference ，他也可以看做是一种复合 （compositon） 但是他是使用指针相连。

**类有可能先创建，但是有指针，等到需要用到右边时才创建右边（生命期————不同步）**
![[Pasted image 20220411154741.png]]
这个模式叫 **Handle/Body(PIml)**
> A -> Handle
```cpp
//用一个指针指向为我们实现所有功能的那个类
class stringRep;
class string{
public:
	string();
	string(const char *s);
	string(const string &s);
	string & operator=(const string &s1);
	~string()
private:
	stringRep *rep; //piml
	...
};
/*比如此段程序，表示左边的一个类*/
```

> B -> Body
```cpp
//此段程序表示右边的一个类
namespace{
	class stringRep{
		friend cl右边ass string;
		stringRep(const char *s);
		~stringRep();
		int count;
		char *rep;
	};
}
```
打个比方说，现在有一个类 **A** ，有一个类 **B** ，的类 **A** 中有的类 **B** ，但是这个 **“有”** 稍微有点虚，不是那么的扎实，只是有一个指针指向它，至于什么时候才拥有 **B** 现在还不知道。

A B 的程序对外不变，A 不用修改，A 只是对外的接口；真正的实现在 B。当 A 需要动作时，都是通过调用 B 来服务的。B 不管怎么变都不影响 A，也就不影响客户端。

这种做法就是**编译防火墙**，即 A 不用再编译，要编译的只有B，使用一个指针指向为我实现所有功能的类

![[Pasted image 20220411172753.png]]

a, b, c 共享同一个 Hello。

#cpp #OOP #OOD  #委托