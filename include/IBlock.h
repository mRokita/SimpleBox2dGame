//
// Created by mrokita on 12.05.19.
//

#ifndef ANGRYGUNS_IBLOCK_H
#define ANGRYGUNS_IBLOCK_H


#include "Block.h"

class IBlock : public Block {
public:
    void draw(const std::shared_ptr<sf::RenderWindow> &window) override;

protected:
    void addFixtures() override {
        addSquareBoxFixture(0, 40);
        addSquareBoxFixture(0, 0);
        addSquareBoxFixture(0, -40);
    }

public:
    std::vector<sf::Vector2f> getHoleDimensions() override;

public:
    bool isInHole() override;
};


#endif //ANGRYGUNS_SBLOCK_H
