//
// Created by mrokita on 12.05.19.
//

#include "../include/LBlock.h"

void LBlock::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    Block::draw(window);
    window->draw(getSquareBox(0.f, -20.f));
    window->draw(getSquareBox(40.f, 20.f));
    window->draw(getSquareBox(40.f, -20.f));
    window->draw(getSquareBox(-40.f, -20.f));
}

std::vector<sf::Vector2f> LBlock::getHoleDimensions() {
    std::vector<sf::Vector2f> ret;
    ret.emplace_back(sf::Vector2f(45.f, 115.f));
    ret.emplace_back(sf::Vector2f(45.f, 115.f));
    ret.emplace_back(sf::Vector2f(60.f, 75.f));
    return ret;
}

bool LBlock::isInHole() {
    float y = m_body->GetPosition().y * AngryBlocks::SCALE;
    int angleDegrees = ((int)(180*m_body->GetAngle()/(b2_pi)))%360;
    std::cout << "Y: " << y << "Angle: " << angleDegrees << std::endl;
    return (y >= 540.f-125.f && angleDegrees <= 1 && angleDegrees >= -1);
}
