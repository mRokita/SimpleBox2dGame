//
// Created by mrokita on 12.05.19.
//

#ifndef ANGRYGUNS_CBLOCK_H
#define ANGRYGUNS_CBLOCK_H


#include "Block.h"

class CBlock : public Block {
public:
    void draw(const std::shared_ptr<sf::RenderWindow> &window) override;

protected:
    void addFixtures() override {
        addSquareBoxFixture(20, 20);
        addSquareBoxFixture(-20, -20);
        addSquareBoxFixture(20, -20);
        addSquareBoxFixture(-20, 20);
    }

public:
    std::vector<sf::Vector2f> getHoleDimensions() override;

public:
    bool isInHole() override;
};


#endif //ANGRYGUNS_TBLOCK_H
