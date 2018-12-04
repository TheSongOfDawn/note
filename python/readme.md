# 2018.12.4
···
前两天在用Python 结合RPC 测试服务器下单处理能力，用到了Python多线程，多进程，日志等模块。这里记录一下收获。
先说测试后的心得:
1.能用多进程/线程就用。
2.对于资源，能不共享就不共享，能不加锁就不加锁。
3.程序尽量轻装上阵，能去就去，能不引用相关模块就不用。

Python 多进程知识参考:
multiprocessing 官方文档:
https://docs.python.org/2/library/multiprocessing.html
多核CPU上python多线程并行的一个假象：
http://www.cnblogs.com/skying555/p/6527189.html
所用到的日志模块:
python 多进程日志 logging(并不是真正的多进程 还是需要加锁的才能输出正确)：
https://www.jianshu.com/p/d874a05edf19
进程安全的ConcurrentLogHandler(真正的多进程 可性能也相应的变慢了)：
https://blog.csdn.net/qq_25730711/article/details/53393190
涉及到其他的Python多进程知识还有 锁，线程池，Manager等相关知识这里就不列举了。
···
