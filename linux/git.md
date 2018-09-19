> 内容摘自
[廖雪峰的git教程](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)

 [ TOC ] 

# 安装git
 Linux 上安装:
    Debian或者Ubuntu : sudo apt-get install git
    Windows :从官网上 [下载安装程序](https://git-scm.com/downloads)
    
安装完成后，还需要最后一步设置，在命令行输入:
```
git config --global user.name "your name"
git config --global user.email "email@example.com"
```
注意git config命令的--global参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置，当然也可以对某个仓库指定不同的用户名和Email地址。

# 创建版本库(repository)
什么是版本库:版本库又名仓库，英文名repository，你可以简单理解成一个目录，这个目录里面的所有文件都可以被Git管理起来，每个文件的修改、删除，Git都能跟踪，以便任何时刻都可以追踪历史，或者在将来某个时刻可以“还原”。
1.新建一个目录
2.通过git init 把这个目录变成git可以管理的仓库


# 把文件添加到版本库
1.用命令git add告诉Git，把文件添加到仓库
2.用命令git commit告诉Git，把文件提交到仓库 -m 为提交说明

#时光穿梭
```
要随时掌握工作区的状态，使用git status命令。

如果git status告诉你有文件被修改过，用git diff可以查看修改内容。
```
# 版本回退
```
HEAD指向的版本就是当前版本，因此，Git允许我们在版本的历史之间穿梭，使用命令git reset --hard commit_id。

穿梭前，用git log可以查看提交历史，以便确定要回退到哪个版本。

要重返未来，用git reflog查看命令历史，以便确定要回到未来的哪个版本。
```

# 重要概念:
工作区:电脑里能看到的目录。

版本库:工作区有一个隐藏目录.git，这个不算工作区，而是Git的版本库。

暂存区:Git的版本库里存了很多东西，其中最重要的就是称为stage（或者叫index）的暂存区，还有Git为我们自动创建的第一个分支master，以及指向master的一个指针叫HEAD。

[](https://github.com/TheSongOfDawn/note/blob/master/pic/git-1.jpg)

[如何在本地环境配置github](https://segmentfault.com/a/1190000002533334)
# git的基本命令
```
git pull：从其他的版本库（既可以是远程的也可以是本地的）将代码更新到本地，例如：'git pull origin master'就是将origin这个版本库的代码更新到本地的master主枝，该功能类似于SVN的update
git add：是 将当前更改或者新增的文件加入到Git的索引中，加入到Git的索引中就表示记入了版本历史中，这也是提交之前所需要执行的一步，例如'git add app/model/user.rb'就会增加app/model/user.rb文件到Git的索引中，该功能类似于SVN的add
git rm：从当前的工作空间中和索引中删除文件，例如'git rm app/model/user.rb'，该功能类似于SVN的rm、del
git commit：提交当前工作空间的修改内容，类似于SVN的commit命令，例如'git commit -m story #3, add user model'，提交的时候必须用-m来输入一条提交信息，该功能类似于SVN的commit
git push：将本地commit的代码更新到远程版本库中，例如'git push origin'就会将本地的代码更新到名为orgin的远程版本库中
git log：查看历史日志，该功能类似于SVN的log
git revert：还原一个版本的修改，必须提供一个具体的Git版本号，例如'git revert bbaf6fb5060b4875b18ff9ff637ce118256d6f20'，Git的版本号都是生成的一个哈希值

```