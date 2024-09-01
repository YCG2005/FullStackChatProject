#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "global.h"

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

private slots:
    void on_get_code_clicked();
    void slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err);

private:
    void showTip(QString str, bool email_ok);
    void initHttpHandlders();
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handlers;

private:
    Ui::registerdialog *ui;
};

#endif // REGISTERDIALOG_H
