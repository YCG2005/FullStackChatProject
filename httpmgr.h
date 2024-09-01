#ifndef HTTPMGR_H
#define HTTPMGR_H

#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>        // 网络管理
#include <QNetworkReply>
#include <QJsonObject>

/**************************************************
*
* @file         httpmgr.h
* @brief        网络模块
*
* @author       YCG
* @date         2024/09/01
* @history
*
***************************************************/

// 使用 CRTP 实现静态多态
class HttpMgr : public QObject, public Singleton<HttpMgr>,
                public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT;       // 信号和槽的宏

public:
    ~HttpMgr();     // 设置成public方便基类析构时访问
private:
    friend class Singleton<HttpMgr>;
    HttpMgr();
    QNetworkAccessManager _manager;
    void PostHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod);        // 发送 http请求

signals:
    void sig_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod);
public slots:
    void slot_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod);
    void sig_reg_mod_finish(ReqId id, QString res, ErrorCodes err);
};

#endif // HTTPMGR_H
