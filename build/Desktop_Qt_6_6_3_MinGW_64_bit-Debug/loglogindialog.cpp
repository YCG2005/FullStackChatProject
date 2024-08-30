#include "loglogindialog.h"
#include "ui_loglogindialog.h"

loglogindialog::loglogindialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loglogindialog)
{
    ui->setupUi(this);
    connect(ui->reg_btn, &QPushButton::clicked, this, &loglogindialog::switchRegister);
}

loglogindialog::~loglogindialog()
{
    delete ui;
}
