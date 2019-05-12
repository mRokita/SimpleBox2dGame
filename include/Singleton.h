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

    static T & getInstance(){
        static T _instance;
        return _instance;
    }


protected:
    Singleton() = default;

};



#endif //ANGRYGUNS_SINGLETON_H
