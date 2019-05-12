//
// Created by mrokita on 05.05.19.
//

#ifndef ANGRYGUNS_BLOCK_H
#define ANGRYGUNS_BLOCK_H


#include <memory>
#include "Sprite.h"
#include "Singleton.h"
#include <cmath>

class Block : public Sprite {
public:
    void onKeyPressed(sf::Event event);

    void draw(const std::shared_ptr<sf::RenderWindow> &window) override;
protected:
    void initialize() override;

    sf::RectangleShape getSquareBox(int offsetx, int offsety);
    void addSquareBoxFixture(int offsetx, int offsety);;
    long long m_lastFrameWhenJumped = 0;
    b2BodyDef getBodyDef(float x, float y) override;
    b2BodyType getBodyType() const override;

public:
    void startContact(Sprite *sprite) override;
    virtual bool isInHole() = 0;
    virtual std::vector<sf::Vector2f> getHoleDimensions() = 0;
protected:

    void addFixtures() override;

};


#endif //ANGRYGUNS_BLOCK_H
