//
// Created by mrokita on 12.05.19.
//

#ifndef ANGRYGUNS_SBLOCK_H
#define ANGRYGUNS_SBLOCK_H


#include "Block.h"

class SBlock : public Block {
public:
    void draw(const std::shared_ptr<sf::RenderWindow> &window) override;

protected:
    void addFixtures() override {
        addSquareBoxFixture(20, 0);
        addSquareBoxFixture(-20, 0);
        addSquareBoxFixture(20, 40);
        addSquareBoxFixture(-20, -40);
    }

public:
    std::vector<sf::Vector2f> getHoleDimensions() override;

public:
    bool isInHole() override;
};


#endif //ANGRYGUNS_SBLOCK_H
