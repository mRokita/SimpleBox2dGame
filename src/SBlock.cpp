//
// Created by mrokita on 12.05.19.
//

#include "../include/SBlock.h"

void SBlock::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    Block::draw(window);
    window->draw(getSquareBox(20.f, 0.f));
    window->draw(getSquareBox(-20.f, 0.f));
    window->draw(getSquareBox(20.f, 40.f));
    window->draw(getSquareBox(-20.f, -40.f));
}

std::vector<sf::Vector2f> SBlock::getHoleDimensions() {
    std::vector<sf::Vector2f> ret;
    ret.emplace_back(sf::Vector2f(45.f, 80.f));
    ret.emplace_back(sf::Vector2f(55.f, 40.f));
    return ret;
}

bool SBlock::isInHole() {
    float y = m_body->GetPosition().y * AngryBlocks::SCALE;
    int angleDegrees = ((int)(180*m_body->GetAngle()/(b2_pi)))%180;
    std::cout << "Y: " << y << "Angle: " << angleDegrees << std::endl;
    return (y >= 540.f-125.f && angleDegrees <= 1 && angleDegrees >= -1);
}
