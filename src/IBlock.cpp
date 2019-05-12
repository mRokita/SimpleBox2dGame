//
// Created by mrokita on 12.05.19.
//

#include "../include/IBlock.h"

void IBlock::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    Block::draw(window);
    window->draw(getSquareBox(0, 40.f));
    window->draw(getSquareBox(0, 0.f));
    window->draw(getSquareBox(0, -40.f));
}

std::vector<sf::Vector2f> IBlock::getHoleDimensions() {
    std::vector<sf::Vector2f> ret;
    ret.emplace_back(sf::Vector2f(70.f, 40.f));
    return ret;
}

bool IBlock::isInHole() {
    float y = m_body->GetPosition().y * AngryBlocks::SCALE;
    int angleDegrees = ((int)(180*m_body->GetAngle()/(b2_pi)))%180;
    std::cout << "Y: " << y << "Angle: " << angleDegrees << std::endl;
    return (y >= 540.f-108.f && angleDegrees <= 1 && angleDegrees >= -1);
}
