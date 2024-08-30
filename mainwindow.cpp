#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)     // QWidget -- 界面基类，控件类
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);          // 初始化ui文件中所使用到的控件
    _login_dig = new loglogindialog();
    setCentralWidget(_login_dig);
    _login_dig->show();

    // 创建和注册消息链接
    connect(_login_dig, &loglogindialog::switchRegister, this, &MainWindow::SlotSwitchReg);
    _reg_dlg = new registerdialog();

}

MainWindow::~MainWindow()
{
    delete ui;
    if(_login_dig){
        delete _login_dig;
        _login_dig = nullptr;
    }
    if(_reg_dlg){
        delete _reg_dlg;
        _reg_dlg = nullptr;
    }
}

void MainWindow::SlotSwitchReg()
{
    setCentralWidget(_reg_dlg);
    _login_dig->hide();
    _reg_dlg->show();
}