#ifndef ANGRYGUNS_ANGRYBLOCKS_H
#define ANGRYGUNS_ANGRYBLOCKS_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Singleton.h"
#include <queue>


class AngryBlocks : public Singleton<AngryBlocks> {
    /* Main class, responsible for lifecycle of the game */
public:
    static constexpr float SCALE = 100.f;

    b2Body* createBody(b2BodyDef def){
        if(m_world->IsLocked()){
            m_bodiesToCreate.push(def);
            return nullptr;
        } else {
            return m_world->CreateBody(&def);
        }
    }

    void destroyBody(b2Body* body){
        if(m_world->GetBodyCount() == 0) return;
        if(!m_world->IsLocked()){
            m_world->DestroyBody(body);
        } else {
            m_bodiesToDestroy.push(body);
        }
    }
    float getOffset(){
        return m_offset;
    }
    long long getCurrentFrame(){return this->m_currentFrame;}
    void start();
    void stop();
    AngryBlocks () {m_alive = true; m_currentFrame = 0;}
private:
    float m_offset = 0;
    std::queue<b2Body*> m_bodiesToDestroy;
    std::queue<b2BodyDef> m_bodiesToCreate;
    std::unique_ptr<b2World> m_world{new b2World(b2Vec2(0.f, 9.8f))};
    long long m_currentFrame;
    bool m_alive; /* Setting to false breaks the main loop */;
};

#endif //ANGRYGUNS_ANGRYBLOCKS_H
