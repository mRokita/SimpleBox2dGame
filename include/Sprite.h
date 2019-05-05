#ifndef ANGRYGUNS_SPRITE_H
#define ANGRYGUNS_SPRITE_H

#include <Box2D/Dynamics/b2Body.h>
#include <SFML/Graphics.hpp>
#include "AngryGuns.h"

class Sprite : public Drawable {
protected:
    virtual b2BodyType getBodyType() const { return b2_staticBody;}
    b2Body* m_body;

    virtual b2BodyDef getBodyDef(float x, float y){
        b2BodyDef bodyDef ;
        bodyDef.userData = this;
        bodyDef.position.Set(x/AngryGuns::SCALE, y/AngryGuns::SCALE);
        bodyDef.type = getBodyType();
        return bodyDef;
    }

    void applyBox2dPosition(sf::Transformable &transformable){
        transformable.setPosition(m_body->GetPosition().x*AngryGuns::SCALE,
                                   m_body->GetPosition().y*AngryGuns::SCALE);
        transformable.setRotation(180/b2_pi * m_body->GetAngle());
    }



    virtual void addFixtures(){};

public:

    float getX(){
        return m_body->GetPosition().x*AngryGuns::SCALE;
    }
    void addToGame(float x, float y){
        b2BodyDef def = getBodyDef(x, y);
        m_body = AngryGuns::getInstance()->createBody(&def);
        addFixtures();
    }
};


#endif //ANGRYGUNS_SPRITE_H
