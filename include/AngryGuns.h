#ifndef ANGRYGUNS_ANGRYGUNS_H
#define ANGRYGUNS_ANGRYGUNS_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Singleton.h"


class AngryGuns : public Singleton<AngryGuns> {
    /* Main class, responsible for lifecycle of the game */
public:
    static constexpr float SCALE = 100.f;
    ~AngryGuns() {m_alive = false;}
    static std::shared_ptr<AngryGuns> getInstance(){
        static std::weak_ptr<AngryGuns> _instance;
        if(auto inst = _instance.lock()){
            return inst;
        }
        auto ptr = std::shared_ptr<AngryGuns>(new AngryGuns());
        _instance = ptr;
        return ptr;
    }
    b2Body* createBody(b2BodyDef* def){
        return this->m_world->CreateBody(def);
    }
    void start();
    void stop();
private:
    std::unique_ptr<b2World> m_world{new b2World(b2Vec2(0.f, 9.8f))};
    bool m_alive; /* Setting to false breaks the main loop */;
    AngryGuns () {m_alive = true;}
};

#endif //ANGRYGUNS_ANGRYGUNS_H
