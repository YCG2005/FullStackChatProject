#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

/**************************************************
*
* @file         registerdialog.h
* @brief        注册界面
*
* @author       YCG
* @date         2024/08/30
* @history
*
***************************************************/

namespace Ui {
class registerdialog;
}

class registerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerdialog(QWidget *parent = nullptr);
    ~registerdialog();

private:
    Ui::registerdialog *ui;
};

#endif // REGISTERDIALOG_H
