程序默认包含头文件 和相关声明
#include <string>
using std::string;

# 3.1
    头文件不应包含using 声明
    ::string 意味着使用 命名空间 std的string
# 3.2
    触发getline函数返回的那个换行符实际上被丢弃了,得到的对象中并不包含该换行符.
    如果一条表达式中已经有了size()函数 就不要使用int了,这样可以避免混用int和unsigned可能带来的问题.
    因为某些历史原因与为了与C兼容 所以C++ 语言中的字符串字面值并不是标准库的string的对象。
    切记 字符串字面值与string是不同的类型.
## 3.2
```
void function1()
{
	string str;
	getline(cin,str);
	cout<<str;
}
void function2()
{
	string str;
	cin>>str;
	cout<<str;
}
```

## 3.3
    自带的运算符:string对象会自动忽略开头的空白(即空格符 换行符 制表符等)并从第一个真正的字符开始读取,直到遇到下一处空白为止.
    而getline是从给定的输入流中读入内容，直到遇到换行符为止，此时读入了换行符 但是不将换行符读到string中 也就是不存换行符.
    
## 3.4
```
void function1()
{
	string str1,str2;
	cin>>str1>>str2;
	if(str1!=str2)
	{
		cout<<"str1 is not equal str2"<<endl;
		if(str1>str2)
			cout<<str1<<endl;
		else
			cout<<str2<<endl;
	}
	else
	{
		cout<<"str1 is equal to str2"<<endl;
	}
}
void function2()
{
	string str1,str2;
	cin>>str1>>str2;
	if(str1.size()>str2.size())
		cout<<str1<<endl;
	else
		cout<<str2;
}
```
## 3.5
```
void function1()
{
	string str1;
	vector<string> vStr;
	while(cin>>str1)
	{
		vStr.push_back(str1);
	}
	string sTemp="";
	for(vector<string>::iterator it=vStr.begin();it!=vStr.end();it++)
	{
		sTemp=sTemp+(*it)+" ";
	}
	cout<<sTemp<<endl;
}
```
## 3.6
    cctype中定义了一组标准库函数来处理字符相关特性的操作
    string对象的下表必须大于等于0而小于s.size() 使用超出范围的小标将引发不可预知的错误，
    使用下标访问空string也会引发不可预知的错误
    
```
void function1()
{
	string str1;
	str1="abcdefg";
	for(auto &c:str1)
	{
		c='X';
	}
	cout<<str1<<endl;
}
```
## 3.7 
    可以通过编译运行
## 3.8 略
## 3.9
    string s;
    cout<<s[0]<<endl;
    不合法，string s,s并未初始化 会引发不可预知的错误
## 3.10
```
#include <cctype>
void function1()
{
	string str1="cin>>str1;";
	
	for(char c:str1)
	{
	    if(ispunct(c))
	        continue;
	    cout<<c;
	}
}

```
## 3.11
    const string s ="Keep out!";
    for(auto &c:s) 
    //for语句合法 ,c的类型是const char* ,如果不对c进行修改 则可以通过编译
    //如果对c进行修改 则会出现编译错误error: invalid conversion from ‘const char*’ to ‘char’ 

# 3.3
    vector是模板而非类型，由vector生成的类型必须包含vector中元素的类型 例如vector<int>
    某些编译器可能仍需以老式的声明语句来处理元素为vector的vector对象 如 vector<vector> >
## 3.12
    a. vector<vector<int> > ivec; //right
    b.vector<string> svec=ivec;//类型转化错误
    c.vector<string> svec(10,"null"); //right
    
## 3.13 
    a. vector<int> v1; // 0 个元素 
    b.vector<int> v2(10); // 10个元素 每个元素都是0
    c.vector<int> v3 (10,42);//10个元素 每个元素都是42
    d.vector<int> v4{10}; //一个元素 值为10
    e.vector<int> v5{10,42}; //两个元素 值为 10 42
    f.vector<string> v6{10}; //v6有10个默认初始化的string
    gvector<string> v7{10,"hi"};//有10 个值为 "hi"的元素

    范围for语句内不应改变其所遍历序列的大小

## 3.14 & 3.15
    vector<string> v2;
    string s;
    while(cin>>s)
    {
        v2.push_back(s);
    }
# 3.3.3
    要使用size_type 需要首先指定它是由哪种类型定义的 vector 对象的类型总是包含着元素的类型
    exp:vector<int>::size_type;;vector::size_type
    vector对象以及string的下标运算符可用于访问已存在的元素 而不能用于添加元素
    只能对确已知存在的元素执行下表操作 编译器不会检查下标访问一个不存在的元素这种错误.
    
# 3.16 略
# 3.17 
void function1()
{
    vector<string> s;
    string str;
    s.push_back("abcdEh");
    s.push_back("GhijLK");
    
    for(vector<string>::iterator it=s.begin();it!=s.end();it++)
    {
        for(string::iterator strit=(*it).begin();strit!=(*it).end();strit++)
        {
            if(islower(*strit))
                (*strit)-=32; //转大写是-= 小写是+=
        }
        cout<<*it<<endl;
    }
    
}
# 3.18 
    不合法 ,改成 ivec.push_back(42);因为现在的ivec没有包含任何对象

# 3.19
    vector<int> v1(10,42); #√
    vector<int> v2{42,42,42,42,42,42,...}#10个42
    vector<int> v3={42,42,42,42,42,...} #10个42
# 3.20
```
void function1()
{
	vector<int> v1;
	int t;
	while(cin>>t)
	{
		v1.push_back(t);
	}
	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
		int t=*it;
		cout<<((it++)!=v1.end()?t+*it:t)<<endl;
	}
	vector<int>::reverse_iterator it2=v1.rbegin();
	//reverse_iterator 不能与iterator直接相比较 
	for(vector<int>::iterator it1=v1.begin();it1!=v1.end();it1++,it2++)
	{
		cout<<*it1+*it2<<endl;
	}
	 
}
```
# 3.21
    如果容器为空 则begin与end返回的是同一个迭代器，都是尾后迭代器
    因为end返回的迭代器并不实际指示某个元素 所以不能对其进行递增或者解引用操作
    但凡使用了迭代器的循环体 都不要向迭代器所属的容器添加元素
    略
# 3.22&3.23
```
void function1()
{
	vector<int> v1;
	for(int i=0;i<10;i++)
	{
	 	v1.push_back(i);
	}
	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
		*it=(*it)*2;
		cout<<*it<<endl;
	}
}
```
# 二分搜索
```
   //text必须是有序的
   //begin end表示我们搜索的范围
   auto beg=text.begin,end=text.end();
   auto mid= text.begin()+(end-begin)/2;
   //当还有元素尚未检查并且我们还没有找到sought的时候执行循环
   while(mid!=end&&*mid!=sought)
   {
    if(sought<*mid)//要找的元素在前半部分
        end=mid;    //调整搜索的范围忽略掉后半部分
    else            //要找的元素在后半部分
        beg= mid + 1;//在mid之后找
    mid = beg+(end - beg) / 2;//新的中间点
   }
```
# 3.24&3.25
    vector<unsigned> scores(11,0);
    unsigned grade;
    while(cin>>grade){
        vector<unsigned>::iterator it=scores.begin();
        *(it+grade/10)++;//这里是错的 因为括号打开后 先进行的是自增 然后再与前面的解引用相结合
            //所以这一段代码是自增迭代器位置 而并没有使向量的值增加
           (*(it+grade/10))++;
        
    }
    
# 3.26
    二分搜索程序中 为什么用的是mid=beg+(end-beg)/2.而非(beg+end)/2;?
    1数学上两者得到的结果是完全一样的。但是beg＋end操作很可能会出现溢出的风险，
    但是后一种写法不会出现比end要大的中间数据，所以比较安全。
  2你要是看c＋＋stl源码就会发现用的也是第二种，因为考虑了通用性，用第一种如果beg和end是指针或者迭代器的话是无法编译通过的，
  因为指针和迭代器运算不支持相加运算，却支持相减运算，所以第二种通用性强。
  （迭代器的话要求是随机访问迭代器random access iterator）。
  
# 3.27
    不清楚元素的确切个数 请使用vector
    一些编译器支持数组的赋值 这就是所谓的编译器扩展 但一般来说 最好避免使用非标准特性 
    因为含有非标准特性的程序很可能在其他编译器上无法正常工作
    想要理解数组的声明的含义 最好的办法是从数组的名字开始按照由内向外的顺序阅读
    unsigned buf_size = 1024;
    a. int ia[buf_size];//非常量  定义非法
    b.int ia[4*7-14];//pass
    c.int ia[txt_size()];//非常量 编译不通过
        //当txt_size是constexptr时正确 语义为常量表达式 也就是在编译期可以求值的表达式
    d.char st[11] = "fundamental";//[Error] initializer-string for array of chars is too long [-fpermissive]
                                    //去掉一个或者多个就可以编译通过了 初始值不能过多
# 3.28
    string sa[10];//空串
    int ia[10];//0000000
    int main(){
        string sa2[10];//空串
        int ia2[10];//乱码
        
    }

# 3.29 
    1.数组的大小确定 不能随意向数组中增加元素
        数组的维度必须是常量表达式 即在初始化必须给出 整个运行过程中也不会改变
    2.数组不允许拷贝和赋值，不能将数组的内容拷贝给其他数组作为其初始值
        也不能将数组为其他数组赋值
        int a[]={0,1,2};
        int a2[]=a;//×
        a2=a;//×
    3. 数组使用过程中容易产生数组越界 而vector有迭代器可以尽力避免越界。
# 3.5.2
    大多数常见的安全问题都源于缓冲区溢出错误 当数组或者其他类似数据结构的下标
    越界并试图访问非法内存区域时 就会产生此类错误。
    数组下标从0开始
# 3.30
    constexpr size_t array_int=10;
    int ia[array_int];
    for(size_t i =0;i<array_int;i++)
        ia[i]=i;
# 3.31 3.32 
# 3.33 不初始化 则数组内的数将未定义
# 3.5.3
    在大多数表达式中 使用数组类型的对象其实是使用一个指向该数组首元素的指针
    一个指针如果指向了某种内置类型数组的尾元素的下一位置 则其具备与vector的end函数返回的与迭代器类似的功能
     特别要注意 尾后指针不能执行解引用和递增操作。
     内置的下表运算符所用的索引值不是无符号类型 这一点与vector和string不一样
# 3.34
    两个指针相减的结果是它们之间的距离 参与运算的两个指针必须是指向同一个数组中的元素
    相减的结果的类型为ptrdiff_t的标准库类型 和size_t一样 因为差值可能为负值
    所以ptrdiff_t是一种带符号类型。
    p1+=p2-p1;//让p1指向p2所指向的位置
        //如果两个指针指不是指向同一个数组中的元素 相加减则非法。
# 3.35
    int *pbeg=begin(arr),*pend=end(arr);
    while(pbeg!=pend)
    {
        *pbeg=0;
        ++pbeg;
    }
# 3.36
```
bool compare2Arr(int *a,int a_size,int*b,int b_size)
{
	int begin_a=0;
	int end_a=a_size,end_b=	b_size;
	if(a_size!=b_size)
	{
		return false; 
	}
	while(begin_a!=end_a)
	{
		if(*(a+begin_a)==*(b+begin_a)) 
			begin_a++;
		else
			return false;
	}
	return true;
}
```
# 3.37
```
	const char ca[]={'h','e','l','l','o'};
	const char *cp=ca;
	while(*cp){
		cout<<*cp<<endl;
		cp++;
	}
    //h
    //e
    //l
    //l
    //o
```
# 3.36
    数组中的指针只是指向数组中的某一个元素，如果将两个指针相加，就是把指向数组某一元素的地址相加
    并没有什么意义
# 3.37
    