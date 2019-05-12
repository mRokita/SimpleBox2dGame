//
// Created by mrokita on 12.05.19.
//

#include "../include/CBlock.h"

void CBlock::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    Block::draw(window);
    window->draw(getSquareBox(20.f, -20.f));
    window->draw(getSquareBox(-20.f, 20.f));
    window->draw(getSquareBox(-20.f, -20.f));
    window->draw(getSquareBox(20.f, 20.f));
}

std::vector<sf::Vector2f> CBlock::getHoleDimensions() {
    std::vector<sf::Vector2f> ret;
    ret.emplace_back(sf::Vector2f(110.f, 75.f));
    return ret;
}

bool CBlock::isInHole() {
    float y = m_body->GetPosition().y * AngryBlocks::SCALE;
    int angleDegrees = ((int)(180*m_body->GetAngle()/(b2_pi)))%90;
    return (y >= 540.f-125.f && angleDegrees <= 1 && angleDegrees >= -1);
}
