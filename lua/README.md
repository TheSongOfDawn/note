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
luasql官方文档地址:http://realtimelogic.com/ba/doc/en/lua/luasql.html
luasql源码:https://github.com/keplerproject/luasql
####  环境对象
    环境对象是由储存在 luasql 表中的各种数据库初始化函数创建的，这些函数的名称和它们对应的数据库名称是一样的。例如：
    env = luasql.odbc()
    这会使用ODBC驱动创建一个环境对象。JDBC驱动比较特殊，你还必须让它知道应该使用哪种内部驱动器，因此在创建环境对象时，你应该把驱动的类名作为参数传递给 luasql.jdbc  函数。例如：

    env = luasql.jdbc("com.mysql.jdbc.Driver")

方法

    env:close()
　　关闭环境对象。必须在与它相关的所有数据库连接都关闭以后才应该调用这个函数。
　　返回值：关闭成功返回 true，关闭失败或者环境对象已经被关闭了返回 false。

env:connect(sourcename[,username[,password]])
　用指定的用户名(username)和密码(password)连接到数据源(sourcename)。
　　sourcename 根据数据库驱动的不同而改变。有些只使用一个简单的数据库名称即可，例如 MySQL, PostgreSQL 和 SQLite；ODBC 驱动需要一个 DSN 名称；Oracle 驱动需要一个服务名称；JDBC 驱动则需要一个字符串，就像“jdbc:<database system>://<database name>”一样。
　　另见: PostgreSQL 扩展 和 MySQL 扩展。
　　返回值：一个连接对象。

连接对象

　　连接对象包含数据源连接的特殊属性，它是由 environment:connect 创建的。

方法

conn:close()
　　关闭数据库连接。只有在所有的游标都关闭的情况下才有可能成功关闭连接。
　　返回值：关闭成功返回 true，关闭失败或者连接已经关闭了返回 false。

conn:commit()
　　提交当前事务处理。此方法在不支持事务处理的数据库上不会正常工作。 　　
    返回值：提交成功返回 true，提交失败或者数据库不支持事务处理则返回 false。
conn:execute(statement) 
　　执行给定的 SQL 语句
　　返回值：一个游标对象，或者一个数字，指示有多少条记录受此语句的影响。

conn:rollback()
　　回滚当前事务处理。此方法在不支持事务处理的数据库上不会正常工作。 
　　返回值：回滚成功返回 true，回滚失败或者数据库不支持事务处理则返回 false。
conn:setautocommit(boolean) 
　　打开或者关闭“自动提交事务处理”功能。这个方法在不支持事务处理的数据库上不会正常工作。
在支持事务处理单不支持自动提交事务处理的数据库上，会根据数据库驱动的不同而有不同的结果。
　　返回值：设置成功返回 true，设置失败或者数据库不支持事务处理则返回 false。

游标对象

　　游标对象包含从 SQL 语句执行结果提取数据的各种方法。它是由 connection:execute 创建的。

方法　　

cur:close()
　　关闭游标对象。
　　返回值：关闭成功返回 true，关闭失败或者游标对象已经关闭了返回 false。
cur:fetch([table[,modestring]])
　　获取 SQL 语句执行结果中的下一条记录结果。
　　如果调用此方法时没有传递任何参数，结果会直接返回给方法的调用者。如果传递了 table 参数，结果会被复制到一个表（Lua 概念中的表）中并被返回。同时，你还可以指定一个 mode 参数，指示返回的表的所以方式。它有以下两个值：
"n" 
　　结果表以数字为索引标识符（默认）

"a" 
　　结果以字母为索引标识符
数字索引标识符的位置由执行的 SQL 语句中 select 后面的字段顺序决定的；字母索引标识符则是根据字段的名称来定的。
　　可选的 table 参数是用来储存下一条记录的。
　　此方法不保证返回结果的类型，这要由你所使用的数据库驱动确定。目前来说，PostgreSQL 和 MySQL 驱动会把所有的结果都转换为字符串，而 ODBC 和 Oracle 驱动则会根据字段类型返回对应的 Lua 类型的值
　　返回值：如上所述的数据结果，或者在没有任何记录结果时返回 nil。注意这并不是唯一返回 nil 的情况，当获取的结果有效时也可能返回 nil。

cur:getcolnames()
　　返回值: 一个由字段名称组成的表。
cur:getcoltypes() 
　　返回值：一个由字段类型组成的表。

PostgreSQL 扩展

　　除了上面所说的通用的方法特性外，PostgreSQL 驱动还额外提供以下特性：

env:connect(sourcename[,username[,password[,hostname[,port]]]])
　　PostgreSQL 驱动的这个方法还提供了另外两个可选的参数，指明了连接的主机名和端口号。当然，你也可以只用地一个参数就可以包含所有的连接信息，就像 PostgreSQL 手册中 PQconnectdb 函数的参数一样（例如，environment:connect("dbname=<name> user=<username>")）
　　另见：环境对象。
　　返回值：一个连接对象。

cur:numrows()
　　另见：游标对象
　　返回值：SQL  查询结果的纪录条数。
MySQL 扩展

　　除了上面所说的通用的方法特性外，MySQL 驱动还额外提供以下特性：

env:connect(sourcename[,username[,password[,hostname[,port]]]])
　　MySQL 驱动的这个方法还提供了另外两个可选的参数，指明了连接的主机名和端口号。
　　另见：环境对象。
　　返回值：一个连接对象。

Oracle 扩展

　　除了上面所说的通用的方法特性外，Oracle 驱动还额外提供以下特性：

cur:numrows()
　　另见：游标对象
　　返回值：SQL  查询结果的纪录条数。
    
    
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
### 遇到过的问题
```

Q:#INF00 
A:未定义的 就插入不进去

#关于lua命令行输出 
 如果lua输出有乱码 或者输出不正确的拼接字符串 改一下命令行试试
windows下的命令行输出默认是936 gbk,然后要输出utf8则必须把属性改为65001

#数据库
 插入有两种情况，成功与失败。成功了会返回影响的行数 失败了则会将cur置成null值
   local cur, dbErrorMsg = con:execute(strQuery)
    if cur == nil then
        flag=true
#迭代器
泛型for在自己内部保存迭代器 实际上它保存三个值 迭代函数 状态常量 控制变量
泛型for迭代器提供了集合的key/value对 语法格式如下:
for k,v in pairs(t) do
    print(k,v)
end
pairs: 迭代 table，可以遍历表中所有的 key 可以返回 nil
 ipairs: 迭代数组，不能返回 nil,如果遇到 nil 则退出

local tab= { 
[1] = "a", 
[3] = "b", 
[4] = "c" 
} 
for i,v in pairs(tab) do        -- 输出 "a" ,"b", "c"  ,
    print( tab[i] ) 
end 

for i,v in ipairs(tab) do    -- 输出 "a" ,k=2时断开 
    print( tab[i] ) 
end


求table的长度
取长度操作符 #
table t 的长度被定义成一个整数下标 n 。 它满足 t[n] 不是 nil 而 t[n+1] 为 nil； 此外，如果 t[1] 为 nil ，n 就可能是零。

```
### 打印table
```
function print_r ( t )  
    local print_r_cache={}
    local function sub_print_r(t,indent)
        if (print_r_cache[tostring(t)]) then
            print(indent.."*"..tostring(t))
        else
            print_r_cache[tostring(t)]=true
            if (type(t)=="table") then
                for pos,val in pairs(t) do
                    if (type(val)=="table") then
                        print(indent.."["..pos.."] => "..tostring(t).." {")
                        sub_print_r(val,indent..string.rep(" ",string.len(pos)+8))
                        print(indent..string.rep(" ",string.len(pos)+6).."}")
                    elseif (type(val)=="string") then
                        print(indent.."["..pos..'] => "'..val..'"')
                    else
                        print(indent.."["..pos.."] => "..tostring(val))
                    end
                end
            else
                print(indent..tostring(t))
            end
        end
    end
    if (type(t)=="table") then
        print(tostring(t).." {")
        sub_print_r(t,"  ")
        print("}")
    else
        sub_print_r(t,"  ")
    end
    print()
end
```

#lua中区分大小写，而notepad++不区分大小写 
#在写参数的时候要注意
#求有序表的时候可以用# 或者table.getn
 table中最好不要有nil值
 求无序表的时候 请 for k,v in pairs(table) do index=