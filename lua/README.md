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