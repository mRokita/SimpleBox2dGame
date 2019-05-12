//
// Created by mrokita on 12.05.19.
//

#include "../include/TBlock.h"

void TBlock::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    Drawable::draw(window);
    window->draw(getSquareBox(0, 20.f));
    window->draw(getSquareBox(-40.f, -20.f));
    window->draw(getSquareBox(40.f, -20.f));
    window->draw(getSquareBox(0, -20.f));
}

std::vector<sf::Vector2f> TBlock::getHoleDimensions() {
    std::vector<sf::Vector2f> ret;
    ret.emplace_back(sf::Vector2f(60.f, 115.f));
    ret.emplace_back(sf::Vector2f(70.f, 75.f));
    ret.emplace_back(sf::Vector2f(60.f, 115.f));
    return ret;
}

bool TBlock::isInHole() {
    float y = m_body->GetPosition().y * AngryBlocks::SCALE;
    int angleDegrees = ((int)(180*m_body->GetAngle()/(b2_pi)))%360;
    return (y >= 540.f-125.f && angleDegrees <= 1 && angleDegrees >= -1);
}
