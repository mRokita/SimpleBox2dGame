//
// Created by mrokita on 12.05.19.
//

#ifndef ANGRYGUNS_TBLOCK_H
#define ANGRYGUNS_TBLOCK_H


#include "Block.h"

class TBlock : public Block {
public:
    void draw(const std::shared_ptr<sf::RenderWindow> &window) override;

protected:
    void addFixtures() override {
        addSquareBoxFixture(0, -20);
        addSquareBoxFixture(0, 20);
        addSquareBoxFixture(40, -20);
        addSquareBoxFixture(-40, -20);
    }

public:
    std::vector<sf::Vector2f> getHoleDimensions() override;

public:
    bool isInHole() override;
};


#endif //ANGRYGUNS_TBLOCK_H
