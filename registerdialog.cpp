#include "registerdialog.h"
#include "ui_registerdialog.h"

registerdialog::registerdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerdialog)
{
    ui->setupUi(this);
}

registerdialog::~registerdialog()
{
    delete ui;
}
