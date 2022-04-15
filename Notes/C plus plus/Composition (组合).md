## Composition(组合), 表示has-a
### 1. 符号表示
![[Pasted image 20220411151412.png]]
```cpp
template <class T>
class queue {
	...
protected:
	deque<T> c; //底层容器
public:
//以下完全利用 c 的操作函数完成
	bool empty() const {return c.empty();}
    size_type size() const {return c.size();}
    reference front() {return c.front();}
    reference back() {return c.back();}

    void push(const value_type &x) {c.push_back(x);}
    void pop() {c.pop_front();}
}
```

即queue里面的所有功能都没有自己写，他都是通过 C 来调用 deque 的成员函数来完成的，所有的功能都在 deque 中已经完成了，而 queue 是借用 deque 已经完成的功能来实现自己的功能。

对于上述的特例，进一步阐述 composition（复合） ，因为 **deque** 的功能比较强大，而 queue 的功能都能通过借用 deque 来完成；这是 23种设计模式中的 Adapter(改造)，简单的说即： A 拥有 B 则为 composition 

复合是queue里有deque，但是以上例子比较特殊，不仅有复合关系，而且queue的所有函数都是借助deque的函数来实现的——这种关系就是设计模式中的**适配器模式**。适配器模式就是已经有一个很强大的P1，但是客户想要另一个P2，P1完全满足客户需求，只是名称和接口不一样，于是可以借用P1来完成P2，此时P2就是**Adapter**。

### 2. 内存占用
![[Pasted image 20220411000244.png]]
### 3. Composition(组合)下的构造与析构
![[Pasted image 20220411152447.png]]

#### 构造由内而外
**Container 的构造函数首先调用 Componet 的 default 构造函数, 然后才执行自己.**
**当类 B 含有多个构造函数时，此时编译器不知道该调用哪一个构造函数，则此时需要程序设计者在写 composition（复合） 的构造函数时写上具体调用类B的哪一个构造函数。**
```cpp
Container::Container():Component(){}; //其中companent为default默认构造函数，写的时候可以不加上
``` 
#### 析构由外而内
**Container 的析构函数首先执行自己, 然后才调用 Component 的析构函数**
```cpp
Container::~Container(){~Component()};
```

#cpp #OOP #OOD #组合