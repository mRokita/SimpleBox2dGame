//
// Created by mrokita on 05.05.19.
//

#ifndef ANGRYGUNS_BOX_H
#define ANGRYGUNS_BOX_H


#include "Sprite.h"

class Box : public Sprite {
    b2BodyType getBodyType() const override;

public:
protected:
    void addFixtures() override;

    b2BodyDef getBodyDef(float x, float y) override;

public:
    void draw(const std::shared_ptr<sf::RenderWindow> &window) override;

};



#endif //ANGRYGUNS_BOX_H
