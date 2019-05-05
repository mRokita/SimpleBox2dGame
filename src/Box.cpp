//
// Created by mrokita on 05.05.19.
//

#include "../include/Box.h"

b2BodyType Box::getBodyType() const {
    return b2_dynamicBody;
}

void Box::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    sf::RectangleShape rs(sf::Vector2f(40.f, 40.f));
    this->applyBox2dPosition(rs);
    rs.setOrigin(20.f, 20.f);
    rs.setOutlineColor(sf::Color::Red);
    rs.setOutlineThickness(1.f);
    window->draw(rs);
}

void Box::addFixtures() {
    b2PolygonShape boxShape;
    boxShape.SetAsBox(40.f/2.f/AngryGuns::SCALE, 40.f/2.f/AngryGuns::SCALE);
    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 50;
    boxFixtureDef.restitution = .1f;
    m_body->CreateFixture(&boxFixtureDef);
}

b2BodyDef Box::getBodyDef(float x, float y) {
    b2BodyDef def = Sprite::getBodyDef(x, y);
    def.angle = 180-(145/b2_pi);
    return def;
}
