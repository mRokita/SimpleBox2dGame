#ifndef ANGRYGUNS_SPRITE_H
#define ANGRYGUNS_SPRITE_H

#include <Box2D/Dynamics/b2Body.h>
#include <SFML/Graphics.hpp>
#include "AngryBlocks.h"

class Sprite : public Drawable {
protected:
    virtual b2BodyType getBodyType() const { return b2_staticBody;}

    virtual b2BodyDef getBodyDef(float x, float y){
        b2BodyDef bodyDef ;
        bodyDef.userData = this;
        bodyDef.position.Set(x/AngryBlocks::SCALE, y/AngryBlocks::SCALE);
        bodyDef.type = getBodyType();
        return bodyDef;
    }

    void applyBox2dPosition(sf::Transformable &transformable){
        return applyBox2dPosition(transformable, 0.f, 0.f);
    }

    void applyBox2dPosition(sf::Transformable &transformable, float offsetx, float offsety){
        transformable.setPosition(m_body->GetPosition().x*AngryBlocks::SCALE+offsetx,
                                  m_body->GetPosition().y*AngryBlocks::SCALE+offsety);
        transformable.setRotation(180/b2_pi * m_body->GetAngle());
    }

    virtual void initialize(){};


    virtual void addFixtures(){};

public:
    b2Body* m_body;

    ~Sprite(){
        removeFromGame();
    }
    virtual void startContact(Sprite* sprite){}

    virtual void endContact(Sprite* sprite){}

    float getX(){
        return m_body->GetPosition().x*AngryBlocks::SCALE;
    }

    void addToGame(float x, float y){
        b2BodyDef def = getBodyDef(x, y);
        m_body = AngryBlocks::getInstance().createBody(def);
        if(m_body != nullptr) onAddedToGame(m_body);
    }

    bool isAlive(){
        return m_body != nullptr;
    }
    void removeFromGame(){
        if (m_body != nullptr) AngryBlocks::getInstance().destroyBody(m_body);
        m_body = nullptr;
    }
    void onAddedToGame(b2Body* body){
//        std::cout << "B: " << body << std::endl;
        this->m_body = body;
        addFixtures();
        initialize();
    }
};


#endif //ANGRYGUNS_SPRITE_H
