#include "global.h"

std::function<void(QWidget*)> repolish = [](QWidget* w){
    w->style()->unpolish(w);        // 去除样式表
    w->style()->polish(w);          // 刷新样式表
};
