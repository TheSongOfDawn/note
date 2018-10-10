###String
```
    --string的格式化
    string.format("%s %d","asd",123)
    --连接两个字符串
    print("abc".."def")
    
```

### C++调用lua函数
```
    lua_State*L m_luaState=lua_open()
    luabind::call_function<string>(m_luaState, functionNameString, Param0,Param1,...);
    
```