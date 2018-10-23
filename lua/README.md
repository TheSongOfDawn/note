### 变量
```
-- test.lua 文件脚本
    a = 5               -- 全局变量
    local b = 5         -- 局部变量

    function joke()
        c = 5           -- 全局变量
        local d = 6     -- 局部变量
    end

    joke()
    print(c,d)          --> 5 nil

    do 
        local a = 6     -- 局部变量
        b = 6           -- 对局部变量重新赋值
        print(a,b);     --> 6 6
    end

    print(a,b)      --> 5 6
```

### table
```
    第一，所有元素之间，总是用逗号 "，" 隔开；
　　第二，所有索引值都需要用 "["和"]" 括起来；如果是字符串，还可以去掉引号和中括号； 即如果没有[]括起，则认为是字符串索引
　　第三，如果不写索引，则索引就会被认为是数字，并按顺序自动从 1往后编；
    -- 初始化表
    mytable = {}

    -- 指定值
    mytable[1]= "Lua"

    -- 移除引用
    mytable = nil
    -- lua 垃圾回收会释放内存
    tt = {"hello" ,33}
    value = 4
    tab = {[tt] = "table",key = value, ["flag" ] = nil, 11}
    print(tab[tt])
    print(tab.key)
    print(tab[1 ])//以上写法都是对的
    
    look = {[www] = "ok"}这样是不对的，www没有赋值，所以默认为nil因此出错table index is nil
    
```
### String
```
    --string的格式化
    string.format("%s %d","asd",123)
    --连接两个字符串
    print("abc".."def")
    
```
### 数据库访问
```
    require "luasql.mysql"

    --创建环境对象
    env = luasql.mysql()

    --连接数据库
    conn = env:connect("数据库名","用户名","密码","IP地址",端口)

    --设置数据库的编码格式
    conn:execute"SET NAMES UTF8"

    --执行数据库操作
    cur = conn:execute("select * from role")

    row = cur:fetch({},"a")

    --文件对象的创建
    file = io.open("role.txt","w+");

    while row do
        var = string.format("%d %s\n", row.id, row.name)

        print(var)

        file:write(var)

        row = cur:fetch(row,"a")
    end


    file:close()  --关闭文件对象
    conn:close()  --关闭数据库连接
    env:close()   --关闭数据库环境
```

### C++调用lua函数
```
    lua_State*L m_luaState=lua_open()
    luabind::call_function<string>(m_luaState, functionNameString, Param0,Param1,...);
    
```