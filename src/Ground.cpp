//
// Created by mrokita on 05.05.19.
//

#include "../include/Ground.h"

void Ground::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    sf::RectangleShape rs(sf::Vector2f(this->width, this->height));
    rs.setFillColor({234, 217, 157, 255});
    applyBox2dPosition(rs);
    rs.setOrigin(this->width/2.f, this->height/2.f);
    std::srand(m_frameAdded+1+this->height);
    int numClouds = this->width >= 960.f ? 3+rand()%5 : rand()%2;
    for(int i=0; i<numClouds; ++i){
        sf::Sprite s;
        sf::Texture cloud;
        s.setScale(2.f, 2.f);
        cloud.loadFromFile("/home/mrokita/CLionProjects/AngryGuns/res/cloud.png");
        s.setTexture(cloud);
        s.setPosition(rs.getPosition().x-this->width/2+(rand()%this->width), rand()%350);
        window->draw(s);
    }


    window->draw(rs);
}

b2BodyType Ground::getBodyType() const {
    return b2_kinematicBody;
}

b2BodyDef Ground::getBodyDef(float x, float y) {
    b2BodyDef def = Sprite::getBodyDef(x, y);
    return def;
}

void Ground::addFixtures() {
    b2PolygonShape shape;
    shape.SetAsBox(this->width/2.f/AngryBlocks::SCALE, this->height/2.f/AngryBlocks::SCALE);
    b2FixtureDef def;
    def.shape = &shape;
    def.density = 1;
    def.restitution = 0.4f;
    m_body->CreateFixture(&def);
}

void Ground::initialize() {
    m_frameAdded = AngryBlocks::getInstance().getCurrentFrame();
    m_body->SetLinearVelocity(b2Vec2(-3.f, 0.f));
}

