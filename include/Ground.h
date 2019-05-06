//
// Created by mrokita on 05.05.19.
//

#ifndef ANGRYGUNS_GROUND_H
#define ANGRYGUNS_GROUND_H


#include "Sprite.h"

class Ground : public Sprite {
public:
    Ground(int width, int height){
        this->height = height;
        this->width = width;
    }
    void draw(const std::shared_ptr<sf::RenderWindow> &window) override;
private:
    int height;
    int width;
protected:
    b2BodyType getBodyType() const override;

    void addFixtures() override;

    b2BodyDef getBodyDef(float x, float y) override;
};


#endif //ANGRYGUNS_GROUND_H
