#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <memory>
#include "../include/AngryBlocks.h"
#include "../include/Sprite.h"
#include "../include/Box.h"
#include "../include/Ground.h"
#include "../include/Block.h"
#include "../include/ContactListener.h"
#include "../include/GroundFactory.h"
#include "../include/BlockFactory.h"



void AngryBlocks::start() {

    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(960, 540), "AngryBlocks");
    sf::View view(sf::Vector2f(480.f, 270.f), sf::Vector2f(960.f, 540.f));
    window->setView(view);
    window->setFramerateLimit(120);


    BlockFactory::getInstance().addTBlock();
    GroundFactory::getInstance().processChunks();
    m_world->SetContactListener(static_cast<b2ContactListener*>(new ContactListener()));
    while (window->isOpen() && m_alive) {
        window->clear({68, 161, 244, 255});
        GroundFactory::getInstance().processChunks();
        m_world->Step(1/120.f, 8, 6);
        while (!m_bodiesToDestroy.empty()) {
            m_world->DestroyBody(m_bodiesToDestroy.front());
            m_bodiesToDestroy.pop();
        }
        while (!m_bodiesToCreate.empty()) {
            b2Body *body = m_world->CreateBody(&m_bodiesToCreate.front());
            ((Sprite *) body->GetUserData())->onAddedToGame(body);
            m_bodiesToCreate.pop();
        }
        m_currentFrame ++;
        sf::Event event{};
        while (window->pollEvent(event)) {
            // SFML EVENTS
            if (event.type == sf::Event::Closed){
                window->close();
                this->stop();
            }
        }
        if(m_alive) {

            BlockFactory::getInstance().getCurrentBlock()->onKeyPressed(event);
            float  x = BlockFactory::getInstance().getCurrentBlock() != nullptr ? BlockFactory::getInstance().getCurrentBlock()->getX() : m_offset;
            if ((x - m_offset) > 600.f) {
                float new_offset = BlockFactory::getInstance().getCurrentBlock()->getX() - 600.f;
                sf::View v = window->getView();
                v.move(new_offset - m_offset, 0.f);
                m_offset = new_offset;
                window->setView(v);
            }
            if (x - m_offset < 210.f) {
                float new_offset = BlockFactory::getInstance().getCurrentBlock()->getX() - 210.f;
                sf::View v = window->getView();
                v.move(new_offset - m_offset, 0.f);
                m_offset = new_offset;
                window->setView(v);
            }
            for (b2Body *b = m_world->GetBodyList(); b != nullptr; b = b->GetNext()) {
                auto sprite = static_cast<Sprite *>(b->GetUserData());
                sprite->draw(window);
            }
            window->display();

        }
    }
}

void AngryBlocks::stop() {
    /* Kill the main loop */
    m_alive = false;
}

