//
// Created by mrokita on 05.05.19.
//

#include "../include/Ground.h"

void Ground::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    sf::RectangleShape rs(sf::Vector2f(960.f, 50.f));
    rs.setFillColor(sf::Color::Green);
    rs.setOutlineThickness(1.f);
    rs.setOutlineColor(sf::Color::Cyan);
    rs.setOrigin(480.f, 25.f);
    applyBox2dPosition(rs);
    window->draw(rs);
}

b2BodyType Ground::getBodyType() const {
    return b2_staticBody;
}

b2BodyDef Ground::getBodyDef(float x, float y) {
    b2BodyDef def = Sprite::getBodyDef(x, y);
    return def;
}

void Ground::addFixtures() {
    b2PolygonShape shape;
    shape.SetAsBox(960.f/2.f/AngryGuns::SCALE, 50.f/2.f/AngryGuns::SCALE);
    b2FixtureDef def;
    def.shape = &shape;
    def.density = 1;
    def.restitution = 0;
    m_body->CreateFixture(&def);
}