>参考 [linw7的github](https://github.com/linw7/Skill-Tree/blob/master/Linux%E5%B7%A5%E5%85%B7.md)

# 开发及调试

## 编辑器：vim

基本上 vi/vim 共分为三种模式，分别是命令模式（Command mode），输入模式（Insert mode）和底线命令模式（Last line mode）。 这三种模式的作用分别是：

### 命令模式：
用户刚刚启动 vi/vim，便进入了命令模式。

此状态下敲击键盘动作会被Vim识别为命令，而非输入字符。比如我们此时按下i，并不会输入一个字符，i被当作了一个命令。

以下是常用的几个命令：

i 切换到输入模式，以输入字符。
x 删除当前光标所在处的字符。
: 切换到底线命令模式，以在最底一行输入命令。
若想要编辑文本：启动Vim，进入了命令模式，按下i，切换到输入模式。

命令模式只有一些最基本的命令，因此仍要依靠底线命令模式输入更多命令。

### 输入模式
在命令模式下按下i就进入了输入模式。

在输入模式中，可以使用以下按键：

字符按键以及Shift组合，输入字符
ENTER，回车键，换行
BACK SPACE，退格键，删除光标前一个字符
DEL，删除键，删除光标后一个字符
方向键，在文本中移动光标
HOME/END，移动光标到行首/行尾
Page Up/Page Down，上/下翻页
Insert，切换光标为输入/替换模式，光标将变成竖线/下划线
ESC，退出输入模式，切换到命令模式
### 底线命令模式
在命令模式下按下:（英文冒号）就进入了底线命令模式。

底线命令模式可以输入单个或多个字符的命令，可用的命令非常多。

在底线命令模式中，基本的命令有（已经省略了冒号）：

q 退出程序
w 保存文件
按ESC键可随时退出底线命令模式。

简单的说，我们可以将这三个模式想成底下的图标来表示：

![VIM/VI工作模式](https://github.com/TheSongOfDawn/note/blob/master/pic/vim-1.png)

### 其余常用的命令
```
命令模式下:
gg 移动到这个档案的第一行，相当于 1G 啊！ 
n<Enter>	n 为数字。光标向下移动 n 行
/word 向光标之下寻找一个名称为 word 的字符串。例如要在档案内搜寻 vbird 这个字符串，就输入 /vbird 即可！ 
?word	向光标之上寻找一个字符串名称为 word 的字符串。
:n1,n2s/word1/word2/g	n1 与 n2 为数字。在第 n1 与 n2 行之间寻找 word1 这个字符串，并将该字符串取代为 word2 ！举例来说，在 100 到 200 行之间搜寻 vbird 并取代为 VBIRD 则：
『:100,200s/vbird/VBIRD/g』。
dd	删除游标所在的那一整行(常用)
ndd	n 为数字。删除光标所在的向下 n 行，例如 20dd 则是删除 20 行 
yy	复制游标所在的那一行(常用)
nyy	n 为数字。复制光标所在的向下 n 行，例如 20yy 则是复制 20 行(常用)
:set nu	显示行号，设定之后，会在每一行的前缀显示该行的行号
:set nonu	与 set nu 相反，为取消行号！
```

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

## 编译器：gcc/g++


## 调试工具：gdb


## 查看依赖库：ldd

## 二进制文件分析：objdump

## ELF文件格式分析：readelf

## 跟踪进程中系统调用：strace

## 跟踪进程栈：pstack

## 进程内存映射：pmap

#文件处理

文件查找：find 路径 -name 要查找的文件/路径名

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

## 工作中用到的
bg:将任务放在后台执行

fg：将任务调到前台来使用 fg%进程id

jobs:列出所有后台进程

ps aux | grep xx: 查看某xx进程的状态

top:可以实时动态地查看系统的整体运行情况，是一个综合了多方信息监测系统性能和运行信息的实用工具。通过top命令所提供的互动式界面，用热键可以管理。

telnet: 用于登录远程主机，对远程主机进行管理，

ping: 测试主机之剑网络的联通性.

ssh: 是openssh套件中客户端连接工具，可以给予加密协议实现安全的远程登录服务器。

less:用来浏览文字档案的内容，与more不同的是less允许用户向前或者向后浏览文件.
用PageUp键向上翻页，用PageDown键向下翻页。要退出less程序，应按Q键。

cat:连接文件并打印到标准输出设备上，经常用来显示文件的内容，

tail:用于输入文件中的尾部内容。tail命令默认在屏幕上显示指定文件的末尾10行。如果给定的文件不止一个，则在显示的每个文件前面加一个文件名标题。如果没有指定文件或者文件名为“-”，则读取标准输入。
 -f 显示文件最新追加的内容

chmod:用来变更文件或目录的权限. chmod +x Xt* 给Xt*加上可执行权限

kill:用来删除执行中的程序或工作。kill可将指定的信息送至程序。预设的信息为SIGTERM(15),可将指定程序终止。若仍无法终止该程序，可使用SIGKILL(9)信息尝试强制删除程序。

cp:用来将一个或多个源文件或者目录复制到指定的目的文件或目录。它可以将单个源文件复制成一个指定文件名的具体的文件或一个已经存在的目录下。cp命令还支持同时复制多个文件，当一次复制多个文件时，目标文件参数必须是一个已经存在的目录，否则将出现错误。

mv:用来对文件或目录重新命名，或者将文件从一个目录移到·另一个目录中。source表示源文件或目录，target表示目标文件或目录。如果将一个文件移到一个已经存在的目标文件中，则目标文件的内容将被覆盖。

nohup:可以将程序以忽略挂起信号的方式运行起来，被运行的程序的输出信息将不会显示到终端。

scp:用于在Linux下进行远程拷贝文件的命令,且传输是加密的.scp还非常不占资源，不会提高多少系统负荷.

mkdir:用来创建目录。该命令创建由dirname命名的目录。如果在目录名的前面没有加任何路径名，则在当前目录下创建由dirname指定的目录；如果给出了一个已经存在的路径，将会在该目录下创建一个指定的目录。在创建目录时，应保证新建的目录与它所在目录下的文件没有重名。 

rmdir:删除空目录。

VIRT: 虚拟内存 进程“需要的”虚拟内存大小，包括进程使用的库、代码、数据等
RES：resident memory usage 常驻内存.进程当前使用的内存大小，但不包括swap out

shutdown -r time 重启 
千万不要-h 这个是关了然后不会重启的

cd /home/rzrk/redis/bin
./redis-cli keys "*MINICOUNTER*" | xargs /home/rzrk/redis/bin/redis-cli del 删除柜台上的redis

lsof -i | grep user 
根据用户查看进程和端口号
netstat -nap | grep pid 根据进程pid查端口
netstat -nap | grep port_ 根据端口号port 查看进程
netstat -nao | findstr XXX

md5sum filename
在当前工作目录下，验证filename 文件的md5值.

find / -name httpd.conf　　#在根目录下查找文件httpd.conf，/表示在整个硬盘查找

unzip filename.zip 解压zip
zip -r perflog.zip perflog/ 压缩文件
tar -xzvf filename.tar.gz 解压tar.gz
make all makefile命令
netstat -aon|findstr "49157" 查看端口号
ip addr 查看本机ip mac 不一定有ipconfig 

查看磁盘是否满了 df -hl 
某文件夹的大小 du -h --max-depth=1 /home/rzrk/
查看mysql配置 cat /etc/my.cnf
help xcopy
svn已经更新到最新了，但编译出来的东西却是低版本的 ？
查看自己用到的脚本有没有加执行权限
新创建的脚本是没有执行权限的
chmod +x ./test.sh  #使脚本具有执行权限
less xtcounterservice.log.2019-01-22 | grep -C 20 nil > lkcat.txt
cp -Rf /home/user1/* /root/temp/
将 /home/user1目录下的所有东西拷到/root/temp/下而不拷贝user1目录本身。
即格式为：cp -Rf 原路径/ 目的路径/
make zImage -j8  是指在编译指定文件时用多少个线程进行编译的意思
WSL——Windows Subsystem for Linux是一个为在Windows 10上能够原生运行Linux二进制可执行文件（ELF格式）的兼容层。
windows的东西在 /mnt文件夹里面
svn up -r 版本号  //版本号不带r
