# BaseLineEdit
这是一个基于Qt的行编辑框基础组件。该组件在QLineEdit的基础上，增加了鼠标点击信号和在编辑框两端设置部件的接口。
## 示例
![1.png](./screenshot/1.png)
## 功能概述：
* 该类继承自QLineEdit，父类已经集成了关于行编辑框可能用到的大部分功能接口，所以在使用时直接调用父类的相关接口(包括样式表的设置)基本能满足需求。  
* 该类重新实现了mouseReleaseEvent()方法，添加了编辑信号(鼠标点击并释放)，外部不需要再对编辑框单独安装事件过滤器，即可对点击编辑操作进行处理
* 该类添加了用于在编辑框两端设置部件的功能接口，可以放置任意可显示部件并调节间距细节。为了保持良好的移植性，部件的交互需要在类外(或者该类的派生类)实现，类内不做处理。
```
	//构造方法传递左右部件指针
	explicit BaseLineEdit(QWidget *parent = 0,QWidget *leftWid = 0,QWidget *rightWid = 0);
    //设置行编辑框左右布局margin
    void setLeftRightLayoutMargin(int left,int right,int top=0,int bottom=0);
    //编辑信号
    void editSig();
```
## 作者联系方式:
**邮箱:justdoit_mqr@163.com**  
**新浪微博:@为-何-而来**  