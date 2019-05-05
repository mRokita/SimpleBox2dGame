//
// Created by mrokita on 05.05.19.
//

#ifndef ANGRYGUNS_SINGLETON_H
#define ANGRYGUNS_SINGLETON_H

#include <memory>

template <class T>
class Singleton {
public:
    ~ Singleton() = default;
    static std::shared_ptr<T> getInstance(){
        static std::weak_ptr<T> _instance;
        if(auto inst = _instance.lock()){
            return inst;
        }
        auto ptr = std::shared_ptr<T>(new T());
        _instance = ptr;
        return ptr;
    }

protected:
    Singleton() = default;

};


#endif //ANGRYGUNS_SINGLETON_H
