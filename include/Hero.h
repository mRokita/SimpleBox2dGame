//
// Created by mrokita on 05.05.19.
//

#ifndef ANGRYGUNS_HERO_H
#define ANGRYGUNS_HERO_H


#include <memory>
#include "Sprite.h"
#include "Singleton.h"


class Hero : public Sprite, public Singleton<Hero>{
public:
    void onKeyPressed(sf::Event event){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            const b2Vec2 impulse(0.5f*m_body->GetMass(), 0.f);
            if(m_body->GetLinearVelocity().x < 10.f)
                m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(), true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            const b2Vec2 impulse(-0.5f*m_body->GetMass(), 0.f);
            if(m_body->GetLinearVelocity().x > -5.f)
                m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(), true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W ) && m_body->GetLinearVelocity().y == .0f){
            const b2Vec2 impulse(0.f, -10.f*m_body->GetMass());
            m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(), true);
        }
    }

protected:
    b2BodyDef getBodyDef(float x, float y) override;

public:

    void draw(const std::shared_ptr<sf::RenderWindow> &window) override;

protected:
    b2BodyType getBodyType() const override;

    void addFixtures() override;

};


#endif //ANGRYGUNS_HERO_H
