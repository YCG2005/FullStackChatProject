#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"
#include "httpmgr.h"

registerdialog::registerdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerdialog)
{
    ui->setupUi(this);
    ui->pass_edit->setEchoMode(QLineEdit::Password);
    ui->confirm_edit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);
    connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_reg_mod_finish, this,
            &registerdialog::slot_reg_mod_finish);

    initHttpHandlders();
}

registerdialog::~registerdialog()
{
    delete ui;
}

void registerdialog::showTip(QString str, bool email_ok)
{
    if(email_ok){
        ui->err_tip->setProperty("state","normal");                         // 动态设置对象属性的函数
    }else{
        ui->err_tip->setProperty("state","err");
        qDebug() << ui->err_tip->property("state");
    }
    ui->err_tip->setText(str);
    repolish(ui->err_tip);
}

void registerdialog::initHttpHandlders()
{
    // 注册获取验证码回包的逻辑
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE, [this](const QJsonObject& jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip("参数错误", false);
            return ;
        }

        auto email = jsonObj["email"].toString();
        showTip(tr("验证码已经发送到邮箱，注意查收！"), true);
        qDebug() << "email is" << email ;
    });
}

void registerdialog::on_get_code_clicked()
{
    auto email = ui->email_edit->text();                                    // 获取email文本
    QRegularExpression regex(R"((\w+)(\.|_)?(\w+)@(\w+)(\.(\w+))+)");       // 设置正则表达式匹配模式
    bool match = regex.match(email).hasMatch();                             // match 方法在email中按regex设置的模式匹配内容，hasMatch 方法判断匹配是否成功，返回bool对象
    if(match){
        // 发送http验证码
    }else{
        showTip(tr("邮箱地址不正确"), false);
    }
}

void registerdialog::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS){
        showTip(tr("网络请求错误"), false);
        return;
    }

    // 解析 JSON 字符串，res 转化为QByteArray(字节数组)
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull()){
        showTip(tr("json解析失败"), false);
        return ;
    }

    // json 解析错误
    if(!jsonDoc.isObject()){
        showTip(tr("json解析失败"), false);
        return ;
    }

    _handlers[id](jsonDoc.object());
    return ;
}

