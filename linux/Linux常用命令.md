>参考 [linw7的github](https://github.com/linw7/Skill-Tree/blob/master/Linux%E5%B7%A5%E5%85%B7.md)
[arkingc/note](https://github.com/arkingc/note/blob/master/Linux/Linux常用命令.md)

## 编辑器：vim
[详见](https://coolshell.cn/articles/5426.html)
基本上 vi/vim 共分为三种模式，分别是命令模式（Command mode），输入模式（Insert mode）和底线命令模式（Last line mode）。 这三种模式的作用分别是：

### 命令模式：
```
用户刚刚启动 vi/vim，便进入了命令模式。

此状态下敲击键盘动作会被Vim识别为命令，而非输入字符。比如我们此时按下i，并不会输入一个字符，i被当作了一个命令。

以下是常用的几个命令：

i 切换到输入模式，以输入字符。
x 删除当前光标所在处的字符。
: 切换到底线命令模式，以在最底一行输入命令。
若想要编辑文本：启动Vim，进入了命令模式，按下i，切换到输入模式。

命令模式只有一些最基本的命令，因此仍要依靠底线命令模式输入更多命令。
```
### 输入模式
```
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
```
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
1. 除此之外需要了解预处理->编译->汇编->链接等一系列流程。
2. [详见](http://www.cnblogs.com/lidan/archive/2011/05/25/2239517.html)

## 调试工具：gdb [详见](https://linuxtools-rst.readthedocs.io/zh_CN/latest/tool/gdb.html)
```
举例
    gdb service core_service
    bt
```

## 查看依赖库：ldd
```
# ldd后接可执行文件
# 第一列为程序依赖什么库，第二列为系统提供的与程序需要的库所对应的库，第三列为库加载的开始地址
# 前两列可以判断系统提供的库和需要的库是否匹配，第三列可以知道当前库在进程地址空间中对应的开始位置

ldd a.out
```
## 二进制文件分析：objdump
1. 反汇编 需要理解汇编语言
2. [详见](http://man.linuxde.net/objdump)
3. ps:暂时工作中没有遇到

## ELF文件格式分析：readelf

## 跟踪进程中系统调用：strace

## 跟踪进程栈：pstack

## 进程内存映射：pmap

# 文件处理

## 文件查找：find 
```
find [查找目录] [查找条件]

查找目录：
    .：在当前目录及子目录下查找（默认）
    A：在目录A及A的子目录下查找
查找条件：
    -name：根据文件名查找
    -regex：使用正则表达式匹配
    -type：按类型查找（f:文件，d:目录，l:链接...）
    -atime：按访问时间查找（n:n天前的一天内，+n:n天前(不含n天本身)，-n:n天内(不含n天)）
    -mtime：按修改时间查找（n:n天前的一天内，+n:n天前(不含n天本身)，-n:n天内(不含n天)）
    -size：按大小查找（单位k，+nk:"比nk更大"，-nk:"比nk更小"）
    -perm：按权限查找（644：权限等于644的文件）
    -user/-nouser：用户名等于/用户名不等于
    -group/-nogroup：组名等于/组名不等于
```
示例
```
#1.在当前目录及子目录下查找后缀为cpp的文件
find . -name *.cpp

#2.使用正则表达式查找
find -regex ".*.cpp$"
```
## 文件拷贝
```
cp [选项] 源路径 目的路径

选项：
    -a：将所有属性一起复制（包括拥有者、时间等信息）
    -i：目标文件存在时，进行询问
    -r：递归复制
```
### 打包解包
```
tar [-j|-z] [cv] [-f 压缩包名] 目录
tar [-j|-z] [xv] [-f 解压包名] [-C 解压路径]

选项：
    -c/-x：打包/解包
    -j/-z：bzip2格式/gzip格式
    -v：显示过程
```
### [显示行号]查看文件 :nl
 行号计算不包括空行

## 文本搜索：grep
```
grep [选项] 模式串 文件
输出 | grep [选项] 模式串

选项
    -e：使用多个模式串
    -i：忽略大小写
    -n：打印行号
    -c：统计次数（一行算一次）
```

## 排序：sort
```
sort [选项] 文件
输出 | sort [选项]

选项
    -d：按字典序排序（默认）
    -n：按数字排序
    -k："-k n"表示按各行第n列进行排序
    -r：反序
```
## 转换：tr
```
#set1、set2为字符集，可以是单个字符，也可以是字符串
输出 | tr [选项] set1 set2

选项：
    -d：删除字符
    -s：字符压缩
举例
    # 转换在内存进行，不改变文件
    # 将打开文件中所有目标字符替换
    cat test | tr '1' '2'

    # 转换在内存进行，不改变文件
    # -d删除(delete)
    cat test | tr -d '1'

    # 转换在内存进行，不改变文件
    # -s位于后部
    cat test | tr ' ' -s
```
## 按列切分文本：cut
```
cut [选项] 文件
输出 | cut [选项]

选项：
    -d：分隔符（-d ':' 以’:‘为分隔符）
    -f：选择域（-f 1,2 输出分隔后第1列和第2列）
    -c：字符范围（-c n-m 输出第n到m个字符。如果没有m，输出到末尾）
举例
    # 截取的内存进行，不改变文件
    # -b(byte)以字节为单位，-c(character)以字符为单位，-f以字段为单位
    # 数字为具体列范围
    cut -f 1,2 test

    # 截取的内存进行，不改变文件
    # -d后接界定符
    cut -f 2 -d ',' new
```
## 按列拼接文本：paste
```
paste [选项] file1 file2

选项：
    -d：指定拼接时使用的分隔符（默认使用tab作为分隔符）
举例
    #在内存中拼接，不改变文件
    # 将两个文件按对应列拼接
    # 最后加上-d "x"会将x作为指定分隔符（paste test1 test2 -d ","）
    # 两文件列数可以不同 
    paste test1 test2

    # 在内存中拼接，不改变文件
    # 按照-d之后给出的界定符拼接
    paste test1 test2 -d ","
```
## 统计行和字符：wc
```
wc [选项] 文件
输出 | wc [选项]

选项：
    -c：统计字符数
    -w：统计单词数
    -l：统计行数

举例
    # -l统计行数(line)，-w统计单词数(word)，-c统计字符数(character)
    wc -l test
```
## 文本替换：sed [详见](https://coolshell.cn/articles/9104.html)
```
处理大文件用.
sed常用于一整行的处理。如果有一个100万行的文件，要在第100行加某些文字，此时由于文件太大，不适合用vim处理。因此使用sed是个很好的选择

sed [选项] '[动作]' 文件
输入 | sed [选项] '[动作]'

选项：
    -n：安静模式，只输出sed处理过的行（否则未处理行也会输出）
    -i：结果直接作用到文件（没指定时不会修改文件）
    -e：在命令行模式上输入动作
    -f：从文件中读取动作

动作：[n1[,n2]] function
function:
    a/i：在后插入/在前插入
    d：删除
    p：打印
    s：替换

#1.插入
nl /etc/passwd | sed '2a drink tea' #在第2行后插入一行："drink tea"
nl /etc/passwd | sed '2a aaa \
> bbb' #在第2行后插入两行："aaa"和"bbb"

#2.删除
nl /etc/passwd | sed '2,5d' #删除2~5行
sed '/^$/d' ip #将ip文件中的空行删除

#3.打印2~5行（安静模式，不使用安静模式2~5行会打印2次）
nl /etc/passwd | sed -n '2,5p'

#4.替换
nl /etc/passwd | sed '2s/daemon/root/g' #将第二行的daemon替换成root
ifconfig | grep 'inet addr' | sed 's/^.*addr://g' #将所有开头的“inet addr:”删除
```

## 数据流处理：awk [详见](https://coolshell.cn/articles/9070.html)
```
相比于sed常用于一整行的处理，awk则比较倾向于将一行分成数个“字段”来处理。因此，相当适合小型的数据处理

awk '条件类型1{动作1} 条件类型2{动作2} ...' filename
输出 | awk '条件类型1{动作1} 条件类型2{动作2} ...'

变量：
    $0：整行
    $1：按分隔符分隔后的第1列
    $2：按分隔符分隔后的第2列
    $k：按分隔符分隔后的第k列
    NF：每一行拥有的字段数
    NR：目前所处理的行数
    FS：目前的分隔字符（默认是空格或tab）
条件判断：>、<、>=、<=、==、!=
命令分隔：使用';'或Enter

#1.打印last -n 5结果中每行经过分隔符(默认情况下为空格或tab)分隔后的第1列和第3列
last -n 5 | awk '{print $1 "\t" $3}'

#2.以':'作为分隔符，打印第3列小于10的所有行的第1列和第3列
cat /etc/passwd | awk '{FS=":"} $3<10{print $1 "\t" $3}'      #（第一行不会处理）
cat /etc/passwd | awk 'BEGIN{FS=":"} $3<10{print $1 "\t" $3}' #（第一行会处理）

#3.假设test文件由3列数字组成，以空格分隔。该命令会计算每行的和然后打印
awk '{total=$1+$2+$3;printf "%10d %10d %10d %10.2f\n",$1,$2,$3,total}' test
```

# 性能分析

## 进程查询：ps
```
#1.列出仅与自身环境有关的进程，最上层的父进程是允许该ps命令的bash而没有扩展到init进程中去
ps -l

#2.列出系统所有进程的信息
ps aux
ps -ef    #aux会截断COMMAND列，-ef不会。aux是BSD风格，-ef是System V风格
ps axjf   #以"进程树"的方式显示所有进程
ps -lA    #输出格式同ps -l
```
1. F:进程标志，说明进程的权限
    *  4：root权限
    *  1：仅能fork而不能exec
    *  0：既非4也非1
2. S:进程的状态
    * R(running)：正在运行
    * S(Sleep)：可被唤醒的睡眠
    * D：不可被唤醒的睡眠（通常可能在等待I/O）
    * T：停止，可能是在后台暂停
    * Z(Zombie)：僵尸进程
3. C:CPU使用率
4. PRI/NI：Priority/Nice的缩写，CPU优先级(越小越高)
5. ADDR/SZ/WCHAN：内存相关，ADDR指出进程在内存的哪个部分，running进程一般显示'-'。SZ为进程使用的内存。WCHAN表示进程当前是否运行中'-'，当进程睡眠时，指出进程等待的事件
6. TTY：进程运行的终端机 与终端机无关则显示'?'。tty1~tty6是本机的登陆者程序，pts/0等表示由网络连接进主机的进程
7. TIME：进程用掉的CPU时间
8. USER：进程所属用户
9. %CPU/%MEM：进程消耗的CPU百分比和内存百分比
10. VSZ：进程用掉的虚拟内存(KB)
11. RSS：进程占用的固定内存(KB)
12. STAT：进程目前的状态，与ps -l结果中的S等同
13. START：进程启动的时间
14. TIME：进程实际使用的CPU运行时间
...
## 进程监控：top
```
top [选项]

选项：
    -d：跟秒数指定更新间隔
    -n：与-b搭配，指定需要进行几次top输出，重定向时常用
    -p：指定PID，监控特定进程

top模式下的命令：

?：显示可用的命令
P：以CPU使用情况排序
M：以内存使用情况排序
N：以PID排序
q：退出
1：多核情况下切换CPU
%Cpu(s)后面的“wa”表示I/O wait，过高说明长时间等待I/O，I/O存在瓶颈
```
## 打开文件查询：lsof
```
lsof [选项]

选项：
    -i：-i:端口号查看端口被占用的情况
    -u：后跟用户名查看具体用户打开的文件
    -p：后跟PID查看指定进程打开的文件
    +d：后跟目录查看指定目录下被进程打开的文件，"+D"递归
```
## 内存使用量：free
```
free [选项]

选项：
    -b|-k|-m|-g：单位
    -t：列出物理内存与swap的汇总情况    

buffers：主要缓存dentry和inode等元数据
cached：主要缓存文件内容，即page cache
- buffers/cache：实际使用的内存。used-buffers-cached
+ buffers/cache：可用内存。free+buffers+cached（在内存紧张时，buffers和cached可以回收）
```
## 监控性能指标：sar
```
监控CPU负载
# 加上-q可以查看运行队列中进程数，系统上进程大小，平均负载等
# 这里"1"表示采样时间间隔是1秒，这里"2"表示采样次数为2

sar -q 1 2
监控CPU使用率
# 可以显示CPU使用情况
# 参数意义同上

sar -u 1 2
监控内存

查询内存
# 可以显示内存使用情况
# 参数意义同上 

sar -r 1 2
页面交换查询
# 可以查看是否发生大量页面交换，吞吐率大幅下降时可用
# 参数意义同上

sar -W 1 2
```
# 网络工具

### 网卡配置：ifconfig[链路层]
```
# 可以显示已激活的网络设备信息
ifconfig

# 前一个参数为具体网卡，后一个为开关信息
# up为打开，down为关闭
ifconfig eth0 up

# 前一个参数为具体网卡，后一个为配置的IP地址
ifconfig eth0 192.168.1.1

前一个参数为具体网卡，后面为MTU的大小
# 设置链路层MTU值，通常为1500
ifconfig eth0 mtu 1500

# 开启arp如下，若关闭则-arp
ifconfig eth0 arp
```
### 查看当前网络连接：netstat
```
netstat [选项]

选项：
    -a：将所有的连接、监听、Socket数据都列出来（如，默认情况下，不会列出监听状态的连接）
    -t：列出tcp连接
    -u：列出udp连接
    -n：将连接的进程服务名称以端口号显示（如下图中Local Address会换成10.0.2.15:22）
    -l：列出处于监听状态的连接
    -p：添加一列，显示网络服务进程的PID（需要root权限）
    -i：显示网络接口列表，可以配合ifconfig一起分析
    -s：打印网络统计数据，包括某个协议下的收发包数量

Active Internet connections（w/o servers）：网络相关的连接
Recv-Q：接收队列(已接收还未递交给应用)
Send-Q：发送队列(接收方未确认的数据)
Local Address：本地IP(主机):端口(服务名)
Foreign Address：远端IP:端口
Recv-Q和Send-Q通常应该为0，如果长时间不为0可能存在问题

Active UNIX domain sockets（w/o servers）：本地相关的套接字
RefCnt：连接到此socket的进程数
Flags：连接标识
Type：socket访问的类型
Path：连接到此socket的相关程序的路径
```
## 查看路由表：route

## 检查网络连通性：ping

## 转发路径：traceroute

## 网络Debug分析：nc

## 命令行抓包：tcpdump

## 域名解析工具：dig

## 网络请求：curl

# 其他
## 终止进程：kill
```
杀死具体进程
kill PID
kill -9 PID
```
## 修改文件权限：chmod
```
# 可以对三种使用者设置权限，u(user, owner)，g(group)，o(other)
# 文件可以有三种权限，r(read)，w(write)，x(execute)
# 这里u+r表示文件所有者在原有基础上增加文件读取权限
# 这里777分别对应，u=7，g=7，o=7，具体数字含义自行google

chmod u+r file
chmod 777 file
```
## 创建链接：ln
```
# 硬连接 文件inode中链接数会增加，只有链接数减为0时文件才真正被删除
ln file1 file2

# -s(symbol)为符号链接，仅仅是引用路径
# 相比于硬链接最大特点是可以跨文件系统
# 类似于Windows创建快捷方式，实际文件删除则链接失效
ln -s file1 file2
```
## 显示文件尾：tail
```
# -f参数可以不立即回传结束信号，当文件有新写入数据时会及时更新
# 查看日志时常用
tail -f  -n test
```
## 版本控制：git[详见](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/)
## 设置别名：alias
```
# 常用命令添加别名 ".bashrc"文件中配置常用命令别名，生效后在命令行只需要使用别名即可代替原先很长的命令
alias rm='rm -i'
```
## 工作中用到的
```
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
tar -xvf file.tar //解压 tar包
```