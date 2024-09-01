#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>
#include <functional>
#include <QRegularExpression>       // 正则表达式
#include <QDebug>
#include <QByteArray>               // json 对象序列化
#include <QJsonDocument>
#include <iostream>
#include <memory>
#include <mutex>
#include "QStyle"

/**
 * @brief repolish 刷新样式表
 */
extern std::function<void(QWidget *)> repolish;

// 不同操作事件的id，用于辨识进行了什么操作
enum ReqId{
    ID_GET_VARIFY_CODE = 1001,  // 获取验证码
    ID_REG_USER = 1002          // 注册用户
};

// 验证码
enum Modules{
    REGISTERMOD = 0
};

// 错误码
enum ErrorCodes{
    SUCCESS = 0,
    ERR_JSON = 1,   // JSON 解析失败
    ERR_NETWORK = 2
};

#endif // GLOBAL_H
