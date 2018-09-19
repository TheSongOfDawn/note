>参考 [linw7的github](https://github.com/linw7/Skill-Tree/blob/master/Linux%E5%B7%A5%E5%85%B7.md)

# 开发及调试

## 编辑器：vim
![VIM/VI工作模式](https://github.com/TheSongOfDawn/note/blob/master/pic/vim-1.png)
### How to quit the Vim Editor?
```
:q to quit (short for :quit)
:q! to quit without saving (short for :quit!)
:wq to write and quit
:wq! to write and quit even if file has only read permission (if file does not have write permission: force write)
:x to write and quit (similar to :wq, but only write if there are changes)
:exit to write and exit (same as :x)
:qa to quit all (short for :quitall)
:cq to quit without saving and make Vim return non-zero error (i.e. exit with error)
```
###其余常用的命令
```
:set nu	显示行号，设定之后，会在每一行的前缀显示该行的行号
:set nonu	与 set nu 相反，为取消行号！
```
编译器：gcc/g++
调试工具：gdb
查看依赖库：ldd
二进制文件分析：objdump
ELF文件格式分析：readelf
跟踪进程中系统调用：strace
跟踪进程栈：pstack
进程内存映射：pmap
#文件处理

文件查找：find
文本搜索：grep
排序：sort
转换：tr
按列切分文本：cut
按列拼接文本：paste
统计行和字符：wc
文本替换：sed
数据流处理：awk
#性能分析

进程查询：ps
进程监控：top
打开文件查询：lsof
内存使用量：free
监控性能指标：sar
#网络工具

网卡配置：ifconfig
查看当前网络连接：netstat
查看路由表：route
检查网络连通性：ping
转发路径：traceroute
网络Debug分析：nc
命令行抓包：tcpdump
域名解析工具：dig
网络请求：curl
#其他
终止进程：kill
修改文件权限：chmod
创建链接：ln
显示文件尾：tail
版本控制：git
设置别名：alias