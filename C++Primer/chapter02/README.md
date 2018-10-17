# 2.1
    ## 1
    short 短整型 16 位
    int 整型 16位
    long 长整型 32位
    long long 长整型 64位.C++ 11中新定义的.
    C++ 语言规定 一个int至少和一个short一样大，一个long至少和int一样大，一个longlong至少和一个long一样大。
    ## 2 
    带符号的类型可以表示正数 负数和0，无符号的类型仅能表示大于等于0的值。
    无符号类型中所有比特都用来存储值，例如 8比特的unsigned char可以表示0~255区间的值，
    C++标准并没有规定带符号的类型应该如何表示，但约定了再表示范围内正值和负值应该平衡。8 bit的signed char 理论上应该可以表示 -127~127之剑的值。大多数计算机将实际的表示范围定为-128~127.
    ## 3
    float 单精度浮点数,6位有效数字.通常,float占一个字(32 bits)
    double 双进度浮点数 10位有效数字.double占2个字(64 bits)
    另8 bits=1 字
# 2.2
    利率:float 单精度足以表示.
    本金 和 付款采用double,double能够满足计算精度和大数.
    
# 2.3
    32 
    4294967264.两个数都是unsigned的，但相减结果为负数，带符号的数会自动的转化为无符号数。
    当前int所占位数为32位，用当前int最大值减去该绝对值就是所得的值.
    32
    -32
    0
    0 无符号的类型表示大于等于0的值。
# 2.4 
    略
# 2.5
    a. 'a'是字符值字面值常量.L'a'是宽字符型字面值，类型是wchar_t
    "  a"是字符串字面值,L"a"是宽字符串字面值.字符串的结尾有 空字符('\0'),"a"实际包含字符a和空字符
    b. [u l ll为后缀] 
    10 整型十进制 
    10u整型无符号数
    10L 字面值类型为 长整型
    10uL 字面值类型为  长无符号整型
    012 八进制整型
    0xc 16进制整型
    
    3.14 浮点数double类型 [默认的,浮点型字面值是一个double]
    3.14f float类型
    3.14L long double 类型
    10 整型
    10u 整型无符号数
    10. double类型
    10e-2 double类型
    
# 2.6 
    第一组定义的month和day是十进制的,第二组是八进制的
# 2.7
    a. 输出:Who goes with Fergus  其中 \145被转义成了 字符 e, \012被转义成了 换行符
    b.浮点型字面值表现为一个小数或以科学计数法表示的指数，其中指数部分用E或e标识. 3.14e1L=31.4
    c. 1024f ,float类型
    d.3.14L long double
    
# 2.8
    cout<<"2\115\12"; // \115 -M \12 -\n
    cout<<"2\t\115\12";
    
# 2.9 
    a. cin >> int i; // >>是将输入流中的数据赋值给右边的变量 而对变量赋值并不是初始化的工作，也就是该变量未经初始化。[我觉得纠结这个没多大意义，不如好好写程序]
    b. int a ={3.14} ; // a= 3 , 列表初始化 如果我们使用列表初始化且初始值存在丢失信息的风险 则 编译器将报错
    c.double s=w=999.99; //w 没有声明 
    d.int i=3.14;// a=3,但编译器不会报错

# 2.10
    string global_str; //初始化为空串
    int g_int; // 0
    int main() {
        int local_int;
        string local_str;
        cout<<global_str<<endl;// kong
        cout<<local_str<<endl; // kong
        cout<<g_int<<endl; // 0
        cout<<local_int<<endl; // 0
    }

# 2.11 
    a. extern int ix = 1024 ; // 定义
    b.int iy ; // 定义
    c.extern int iz ; //声明
     // 定义 赋值 初始化 声明
     //初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除，以一个新值代替.
     //变量能且只能定义一次，但可以多次声明
     // 声明使得名字为程序所知。定义负责创建与名字相关的实体.
     //如果你想声明一个变量而非定义它，就在变量名前面添加关键字 extern,而且不要显示的初始化变量
# 2.12 标识符
    C++ 保留关键字和操作符替代名不能用作用户自定义标识符. 用户
    a. int double = 3.14 . X
    b. int _ ;//编译通过 __两个下划线也通过 ___也能通过
    c.int c-22; // 不能有操作符
    d. int 1_or_2=1; // 不能以数字开头
    e.double Double=3.14;// OK

# 2.13
```
#include <iostream>

using namespace std;
int i =42;
int main() {
	int i=100;//覆盖了全局变量
	cout<<i<<endl;// 100
	int j =i;
	cout<<j<<endl;//100
    cout<<::i<<endl; // 显示的访问全局变量
	return 0;
}
```
# 2.14
```

int main() {
	int i =100,sum=0;
	for(int i=0;i!=10;i++)
	{
		sum+=i;
	}
	cout<<i<<'\12'<<sum<<endl;// 输出 100\n45
	return 0;
}
//可以运行 第二个i的作用域就只有{}内,
```

# 2.15 

```
    引用并非对象，它只是为一个已经存在的对象所起的另外一个名字.
    
    a.int ival = 1.01; //合法
    b.int&rval1=1.01;  // invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘double’ 
                       //引用类型的初始值必须是一个对象
    c.int &rval2=ival; // bingo
    d.int &rval3; //引用必须初始化
```
# 2.16
    int i=0,&r1=i;
    double d=0,&r2=d;
    a.r2=3.14159; 合法
    b.r2=r1; 合法
    c.i=r2; 合法
    d.	r1=d; 合法
    
# 2.17
    int i,&ri=i;
    i=5;ri=10;
    cout<<i<<"\t"<<ri; // 10 10
    
# 2.18 
    解引用操作只适用于那些确实指向了某个对象的有效指针
    	int ival=42;
	int *p=&ival;
	*p=43;
	cout<<*p<<endl;  // 43
	cout<<ival<<endl;  // 43
    
# 2.19 说明指针和引用的主要区别
    1.指针本身就是一个对象，允许对指针进行赋值，拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象
    2.指针无需在定义时赋初值和其他内置类型一样，在块作用域的指针如果没有被初始化，也将拥有一个不确定的值
    
    引用本身不是一个对象 不能存在定义指向引用的指针 但是指针是一个对象 所以存在对指针的引用.
    
# 2.20
    int i=42;
    int *p=&i; //指针指向i
    *p=*p**p; // 相当于i*i
    cout<<*p; // 1764
    
# 2.21
    int i=0;
    a.double *dp=&i; //非法,常量指针可以指向一个非常量，但其他所有情况所有的指针类型都要和它所指的对象严格匹配
    b.int *ip=i;  //非法，指针存放的是一个对象的地址指针的值被赋值为i
    c. int *p=&i; // p指向i
# 2.22 假设P是一个int 类型指针:
    if(p) //如果p存放的地址不为空
    if(*p) //如果p指向对象的值是否为0

# 2.23 给定指针p，判断它是否指向了一个合法的对象
    通过if(p)来判断 如果p指向了一个合法的对象则它的值必定不是0，条件值为true
    	int i=0;
	int *p;
	if(p)
	{
		cout<<"p is not defined";
	}else
	{
		cout<<"???"; 
	}
    //程序输出 ???
# 2.24
    int *ip=0; //ip被初始化，但没有指向任何对象 ip合法，且是一个空指针
    在下面的代码中为什么p合法而lp非法
    int i=42; void *p=&i; long *lp=&i;
    因为 p 是void* 可用于存放任何对象的地址
    而lp是long型的指针，只能存放long型的对象 
    
# 2.25
    面对一条比较复杂的指针或者因用那个的声明语句时 从右往左阅读有助于弄清真实含义.
    a.int *ip,i,&r=i; // int类型指针，int,int引用
    b. int i,*ip=0;//int,int类型指针但是是个空指针
    c. int *ip，ip2; // int指针, int
    
# 2.26
    const 对象必须初始化
    如果利用一个对象去初始化另外一个对象，则他们是不是const对象都无关紧要.
    如果想在多个文件之间共享const对象，必须在变量的定义之前添加extern关键字.
    a. const int buf;//  uninitialized const 
    b.int cnt=0; // √
    c.const int sz=cnt;// √
    d.++cnt;++sz; // √ X const 对象不能改变  increment of read-only variable 'sz'
    
# 2.27
    所谓指向常量的指针或引用 不过是指针或引用 自以为是罢了，他们觉得自己指向了常量，所以自觉的不去改变所指对象的值.
    a.int i=-1,&r=0; //第二个初始化不合法,等号右边应该是一个int的对象 而不是字面值
    b. int *const p2 = &i2;//合法，前提条件 int i2=10;定义了一个常量int类型指针 p2将一直指向i2
    c. const int i=-1,&r=0;//合法，初始化常量引用时允许用任意表达式作为初始值 只要改表达式的结果能转化为引用的类型即可,
       尤其 允许为一个常量引用绑定非常量的对象 字面值 甚至是一个表达式.
    d. const int *const p3=&i2;// 合法 p3是一个指向常量对象的常量指针
    e.const int *p1=&i2; //合法 可以指向int型常量 也可以指向int型非常量 ，但const int类型的对象只能用const int 指针来指
    f.const int &const r2;// int const&表示此引用所代表的int类型变量无法使用此引用修改.
                            const int&表示此引用所代表的是const int类型变量,同样也无法用此引用修改. 这里要初始化.
                            不合法
    g.const int i2=i,&r=i; // 合法 一个常量 ；一个常量引用

# 2.28
    a. int i,*const cp;//  X 常量指针必须初始化
    b. int *p1,*const p2; // 错，同上
    c.const int ic,&r=ic;// ic未初始化, r为常量引用
    d.const int *const p3; // 指向常量int型对象的常量指针 常量指针必须初始化 *const 就是const指针
    e.const int *p;//指针指向const int类型
    
# 2.29
    a i=ic; //对
    b.p1=p3; //错 不能将普通指针指向const int 所指的对象
    c.p1=&ic;//错 同上
    d.p3=&ic;// 对可以用指向const int类型对象的const指针指向const int对象 
    e.p2=p1; // 对，可以将常量指针指向普通指针所指的对象
    f.ic=*p3;  // ic is read-only,不能修改 const int
    
# 2.30
    顶层const 表示指针本身是一个常量
    底层const 表示指针所指对象是一个常量
     用于声明引用的const都是底层const
    a.const int v2=0; //顶层const
    b.int v1=v2;//底层const
    c.int *p1=&v1,&r1=v1;//底层const X2
    d.const int * p2=&v2,*const p3=&i,&r2=v2;//底层const  顶层const 底层const
    
# 2.31
    基于上诉练习 ，下面哪些语句是合法的。顶层 const和底层const在每个例子中有何体现.
    r1=v2;  //合法
    p1=p2;p2=p1;//p1=p2; 不合法 p2=p1;合法
    p1=p3;p2=p3;//p1=p3;不合法  p2=p3 合法
    
# 2.32
    一般来说 如果你认定变量是一个常量表达式，那就把它声明成constexpr类型
    constexpr int mf=20
    int null=0,*p=null;//非法 int null=0,*p=&null;
    
# 2.33
# 2.34
# 2.35
    const int i=42; //
    auto j=i; const auto &k=i; auto *p=&i; // int ;const int ;int;
    const auto j2=i,&k2=i;// const int ;常量int 引用
    
# 2.36
    int a=3,b=4;//a=3;b=4;
    decltype(a) c=a;//c=3;
    decltype((b)) d=a;//d=3 ; d是a的引用
    ++c;//C=4;
    ++d;//d=4，a=4
    
# 2.37
    #切记decltype((variable))[注意是双层括号]的结果永远是引用 而decltype(variable)结果只有
    当 variable本身就是一个引用时才是引用。
    
    赋值时会产生引用的一类典型表达式 引用的类型就是左值的类型 也就是说 如果i是int ,则表达式i=x的类型是int&
    int a=3,b=4;  // int int
    decltype(a) c=a;//int int int 
    decltype(a=b) d=a;// d是引用类型 a是 int 
    //输出结果是 3 4 3 3 