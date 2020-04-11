/*
 *@author: 缪庆瑞
 *@date:   2020.04.11
 *@brief:  基类行编辑框
 * 1.该类继承自QLineEdit，父类已经集成了关于行编辑框可能用到的大部分功能接口，所以在使用时
 * 直接调用父类的相关接口(包括样式表的设置)基本能满足需求。
 * 2.该类重新实现了mouseReleaseEvent()方法，添加了编辑信号(鼠标点击并释放)，外部不需要再对
 * 编辑框单独安装事件过滤器，即可对点击编辑操作进行处理
 * 3.该类添加了用于在编辑框两端设置部件的功能接口，可以放置任意可显示部件并调节间距细节。为了
 * 保持良好的移植性，部件的交互需要在类外(或者该类的派生类)实现，类内不做处理。
 */
#ifndef BASELINEEDIT_H
#define BASELINEEDIT_H

#include <QLineEdit>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QResizeEvent>


class BaseLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit BaseLineEdit(QWidget *parent = 0,QWidget *leftWid = 0,QWidget *rightWid = 0);
    void setLeftRightLayoutMargin(int left,int right,int top=0,int bottom=0);//设置行编辑框左右布局margin

protected:
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

private:
    void autoAdjustTextMargins();//自动调整编辑框文本的margins

    QHBoxLayout *leftRightLayout;//行编辑框布局(用来布局左/右侧部件)
    QWidget *leftWidget;//行编辑框左侧部件
    QWidget *rightWidget;//行编辑框右侧部件

signals:
    void editSig();//编辑信号

public slots:
};

#endif // BASELINEEDIT_H
