# OS_Proj_Final 项目设计和功能说明文档
## 开发环境
* Ubuntu 16 32位</br>
* Bochs 2.6</br>
## 项目设计与功能
### 难度系数C 控制台的实现
实现对应用的调用，以及文件系统的相关操作(包括新建文件，查看文件，从头覆写文件，删除文件)</br>

#### 控制台指令
指令|参数1|参数2|说明
-|-|-|-
help|无|无|打开控制台指令说明
minesweeper|无|无|打开扫雷游戏
new|File Name|File Content(可为空)|新建文件
erase|File Name|无|删除文件
view|File Name|无|查看文件
edit|File Name|Edit Content(不可为空)|从文件头覆写文件

#### 效果截图

欢迎界面</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-10_17-58-23%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

帮助界面(在欢迎界面输入指令"help")</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-11_11-26-40%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

文件系统相关操作，从上到下依次为：</br>
* 新建文件("TEST")</br>
* 编辑文件</br>
* 查看文件内容</br>
* 查看无效文件内容("TEST1")</br>
* 输入无效指令</br>
* 编辑文件时无内容</br>
* 删除文件("TEST")</br>
* 查看刚刚删除的文件</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-11_11-35-08%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 难度系数D 用户级应用的添加
添加了一个扫雷小游戏

#### 扫雷游戏中控制台指令
指令|参数1|参数2|说明
-|-|-|-
e|无|无|返回游戏开始界面
m|无|无|显示扫雷棋盘
s|location x|location y|清扫位于(x,y)的区块(注意：x,y ∈ [1, 10] 且都为整数)
p|location x|location y|将(x,y)区块设上标记
u|location x|location y|将(x,y)区块的标记取消
c|无|无|显示指令列表
h|无|无|Hack：查看显示所有地雷的地图
n|location x|location y|Hack：清扫(x,y)区块，且绝对不会踩到地雷

#### 效果截图

游戏启动界面</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-10_17-58-23%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

游戏开始界面</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-10_17-58-38%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

游戏指令列表(图的上方 指令 "c")</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-10_17-58-55%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

游戏中界面(指令 "s" (扫雷)输入位置 "3 3")</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-10_17-59-22%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

结果</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-10_17-59-44%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

输入越界位置(指令 "s 12 12")
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-11_11-29-11%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

结果</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-11_11-29-28%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

输入无效指令("Hello World!")
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-11_11-30-38%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

结果</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-11_11-30-55%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

游戏失败界面(输入指令 "e" 返回主菜单)</br>
![截图](https://github.com/theForerunner/OS_Proj_Final/blob/master/doc_image/2018-09-10_18-00-03%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

## 成员及分工

学号|姓名|分工|分数占比
-|-|-|-
1652745|尹刘轩|控制台的完善|100%
1652748|侯贤达|应用程序的添加、撰写文档|100%

**************************************
## 运行环境
Bochs 2.6.9>\br>
在主目录下解压80m.img压缩文件，之后运行dd bash文件内代码，再运行bochs即可启动
