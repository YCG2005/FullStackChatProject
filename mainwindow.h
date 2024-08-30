#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loglogindialog.h"
#include "registerdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void SlotSwitchReg();       // 槽，接收信号并执行

private:
    Ui::MainWindow *ui;
    loglogindialog * _login_dig;
    registerdialog * _reg_dlg;
};
#endif // MAINWINDOW_H
