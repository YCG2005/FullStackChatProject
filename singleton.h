#ifndef SINGLETON_H
#define SINGLETON_H

#include "global.h"

/**************************************************
*
* @file         singleton.h
* @brief        单例模板基类
*
* @author       YCG
* @date         2024/09/01
* @history
*
***************************************************/

template <typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton<T>& st) = delete;                 // 拷贝构造
    Singleton& operator = (const Singleton<T>& st) = delete;    // 拷贝赋值
    static std::shared_ptr<T> _instance;

public:
    static std::shared_ptr<T> GetInstance(){
        // 线程安全
        static std::once_flag s_flag;                           // 只初始化一次的 bool
        std::call_once(s_flag,[&](){                            // call_once 第一次在 s_flag 为 false 时调用一次，后续不再执行
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;
    }

    void PrintAddress(){
        std::cout << _instance.get() << std::endl;              // 返回实例对象的类型
    }

    ~Singleton(){
        std::cout << "This is Singleton destruct" << std::endl;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;           // 静态对象全局实例化

#endif // SINGLETON_H
