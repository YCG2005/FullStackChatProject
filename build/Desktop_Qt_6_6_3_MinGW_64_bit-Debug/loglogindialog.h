#ifndef LOGLOGINDIALOG_H
#define LOGLOGINDIALOG_H

#include <QDialog>

/**************************************************
*
* @file         loglogindialog.h
* @brief        登录界面
*
* @author       YCG
* @date         2024/08/30
* @history
*
***************************************************/

namespace Ui {
class loglogindialog;
}

class loglogindialog : public QDialog           // QDialog -- 继承自QWidget，管理对话框窗口（如消息框，输入框）
{
    Q_OBJECT

public:
    explicit loglogindialog(QWidget *parent = nullptr);
    ~loglogindialog();

private:
    Ui::loglogindialog *ui;

signals:
    void switchRegister();      // 信号不需要实现，定义在发送放
};

#endif // LOGLOGINDIALOG_H
