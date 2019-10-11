#include <iostream>

using namespace std;

/**
 * 懒汉单例 唯一实例定义在类的静态区域 线程不安全
 */
class LazySingleton
{
private:
    LazySingleton()
    {
        cout << "懒汉模式!" << endl;
    }

    LazySingleton(const LazySingleton &) = delete;
    LazySingleton &operator=(const LazySingleton &) = delete;
    static LazySingleton *instance;

public:
    ~LazySingleton()
    {
        cout << "懒汉析构！" << endl;
    }

    static LazySingleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new LazySingleton();
        }

        return instance;
    }
};
LazySingleton *LazySingleton::instance = nullptr;

/**
 * 饿汉单例 唯一实例定义在getInstance的静态区域
 */

class HugurySingleton
{
private:
    HugurySingleton()
    {
        cout << "饿汉单例构造！" << endl;
    }
    HugurySingleton(const LazySingleton &) = delete;
    HugurySingleton &operator=(const LazySingleton &) = delete;

public:
    static HugurySingleton *getInstance()
    {
        static HugurySingleton instance;
        return &instance;
    }
};

/**
 * 双重检查锁 单例
 */

class SafeSingleton
{
private:
    SafeSingleton()
    {
        cout << "安全单例构造！" << endl;
    }

    static SafeSingleton *instance;

public:
    static SafeSingleton *getInstance()
    {
        if (instance == nullptr)
        {
            lock(); //伪代码，加锁
            if (instance == nullptr)
            {
                instance = new SafeSingleton();
            }
            unlock(); //释放锁
        }

        return instance;
    }
};

SafeSingleton *SafeSingleton::instance = nullptr;