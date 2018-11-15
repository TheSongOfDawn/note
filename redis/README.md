### 部分笔记来源:Redis教程
 [Redis W3Cschool](https://www.w3cschool.cn/redis/redis-intro.html)
 
# Redis 简介
```
Redis 是完全开源免费的，遵守BSD协议，是一个高性能的key-value数据库。

Redis 与其他 key - value 缓存产品有以下三个特点：

Redis支持数据的持久化，可以将内存中的数据保持在磁盘中，重启的时候可以再次加载进行使用。
Redis不仅仅支持简单的key-value类型的数据，同时还提供list，set，zset，hash等数据结构的存储。
Redis支持数据的备份，即master-slave模式的数据备份。
```
# Redis 优势
    性能极高 – Redis能读的速度是110000次/s,写的速度是81000次/s 。
    丰富的数据类型 – Redis支持二进制案例的 Strings, Lists, Hashes, Sets 及 Ordered Sets 数据类型操作。
    原子 – Redis的所有操作都是原子性的，同时Redis还支持对几个操作全并后的原子性执行。
    丰富的特性 – Redis还支持 publish/subscribe, 通知, key 过期等等特性。

# Redis与其他key-value存储有什么不同？
    Redis有着更为复杂的数据结构并且提供对他们的原子性操作，这是一个不同于其他数据库的进化路径。Redis的数据类型都是基于基本数据结构的同时对程序员透明，无需进行额外的抽象。
    Redis运行在内存中但是可以持久化到磁盘，所以在对不同数据集进行高速读写时需要权衡内存，应为数据量不能大于硬件内存。在内存数据库方面的另一个优点是， 相比在磁盘上相同的复杂的数据结构，在内存中操作起来非常简单，这样Redis可以做很多内部复杂性很强的事情。 同时，在磁盘格式方面他们是紧凑的以追加的方式产生的，因为他们并不需要进行随机访问。

# 命令操作
    启动 redis 客户端，打开终端并输入命令 redis-cli。该命令会连接本地的 redis 服务。
    清空整个Redis服务器的数据(删除所有数据库的所有key)
    redis 命令行中 flushall
    显示当前数据库的key数量 dbsize  --默认是0数据库
    切换到num号数据库 select num
    删除当前数据库所有的key flushdb
    判断是否存在某个key exists key
    查看当前数据库下所有的key: keys *，keys后面可以跟匹配类型例如：keys a*显示所有以a开头的key