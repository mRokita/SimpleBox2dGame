//
// Created by mrokita on 05.05.19.
//

#include "../include/Hero.h"


void Hero::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    sf::RectangleShape rs(sf::Vector2f(40.f, 80.f));
    rs.setOrigin(20.f, 40.f);
    rs.setOutlineColor(sf::Color::Magenta);
    rs.setOutlineThickness(1.f);
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/dejavu/DejaVuSans.ttf");
    sf::Text text("HERO", font, 14);
    text.setFillColor(sf::Color::Magenta);
    text.setOrigin(20.f, 10.f);
    applyBox2dPosition(rs);
    applyBox2dPosition(text);
    window->draw(rs);
    window->draw(text);
}

b2BodyType Hero::getBodyType() const {
    return b2_dynamicBody;
}


void Hero::addFixtures() {
    b2PolygonShape shape;
    shape.SetAsBox(40.f/2.f/AngryGuns::SCALE, 80.f/2.f/AngryGuns::SCALE);
    b2FixtureDef def;
    def.shape = &shape;
    def.density = 100.f;
    m_body->CreateFixture(&def);
}

b2BodyDef Hero::getBodyDef(float x, float y) {
    b2BodyDef def = Sprite::getBodyDef(x, y);
    def.fixedRotation = false;
    def.linearDamping = 1.f;

    return def;
}
