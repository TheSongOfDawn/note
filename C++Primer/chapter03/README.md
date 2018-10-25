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
    string对象的下表必须大于等于0而小鱼s.size() 使用超出范围的小标将引发不可预知的错误，
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