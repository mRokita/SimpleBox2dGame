//
// Created by mrokita on 05.05.19.
//

#include "../include/Block.h"
#include "../include/BlockFactory.h"
#include "../include/Ground.h"
#include <set>


b2BodyType Block::getBodyType() const {
    return b2_dynamicBody;
}


void Block::addFixtures() {
}

b2BodyDef Block::getBodyDef(float x, float y) {
    b2BodyDef def = Sprite::getBodyDef(x, y);
    def.fixedRotation = false;
    def.linearDamping = 0.2f;
    def.angularDamping = 0.05f;
    return def;
}

void Block::initialize() {
//    m_body->SetLinearVelocity(b2Vec2(.1f, 0.f));
}

void Block::startContact(Sprite *sprite) {
    if(dynamic_cast<Ground*>(sprite) != nullptr){
        if(isInHole()){
            auto c = m_body->GetContactList();
            int i = 0;
            std::set<Ground*> grounds;
            while(c){
                auto s = (Sprite* )c->other->GetUserData();
                Ground* a;
                if((a = dynamic_cast<Ground*>(s)) != nullptr && a->height<120.f){
                    grounds.insert(a);
                }
                c = c->next;

            }
            for(auto g : grounds){
                g->removeFromGame();
            }
            std::cout << "Contacts: " << grounds.size() << std::endl;
            BlockFactory::getInstance().addTBlock();

        }
    }
}

void Block::draw(const std::shared_ptr<sf::RenderWindow> &window) {
    Drawable::draw(window);
}

sf::RectangleShape Block::getSquareBox(int offsetx, int offsety) {
    sf::RectangleShape rs(sf::Vector2f(38.f, 38.f));
    rs.setOrigin(19.f+offsetx, 19.f+offsety);
    sf::Uint8 animation_state = 15*sin(frame/10.f);
    sf::Uint8 transparency = 200 + animation_state;
    rs.setFillColor({244, 66, 66, transparency});
    rs.setOutlineColor({244, 66, 66});
    rs.setOutlineThickness(2.f);
    applyBox2dPosition(rs);
    return rs;
}

void Block::addSquareBoxFixture(int offsetx, int offsety) {
    b2PolygonShape shape;
    shape.SetAsBox(40.f/2.f/AngryBlocks::SCALE, 40.f/2.f/AngryBlocks::SCALE, b2Vec2(offsetx/AngryBlocks::SCALE, offsety/AngryBlocks::SCALE), 0);
    b2FixtureDef def;
    def.shape = &shape;
    def.friction = 0.02f;
    def.restitution = 0.1f;
    def.density = 10.f;
    m_body->CreateFixture(&def);
}

void Block::onKeyPressed(sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (frame - m_lastFrameWhenJumped) > 6){
        const b2Vec2 impulse(0.f, -3.f*m_body->GetMass());
        m_lastFrameWhenJumped = frame;
        m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(), true);
    }
}
