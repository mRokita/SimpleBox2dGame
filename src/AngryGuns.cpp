#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <memory>
#include "../include/AngryGuns.h"
#include "../include/Sprite.h"
#include "../include/Box.h"
#include "../include/Ground.h"
#include "../include/Hero.h"
#include "../include/ContactListener.h"


void AngryGuns::start() {

    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(960, 540), "AngryGuns");
    sf::View view(sf::Vector2f(480.f, 270.f), sf::Vector2f(960.f, 540.f));
    window->setView(view);
    window->setFramerateLimit(120);


    std::unique_ptr<Box> box  = std::make_unique<Box>();
    box->addToGame(300.f, 10.f);

    std::unique_ptr<Box> box2  = std::make_unique<Box>();
    box2->addToGame(350.f, 10.f);
    std::shared_ptr<Hero> hero = Hero::getInstance();
    hero->addToGame(210.f, 540.f-90.f);
    std::unique_ptr<Ground> ground  = std::make_unique<Ground>(960.f, 50.f);
    float offset = 0;
    ground->addToGame(960.f/2.f, 540.f-25.f);
    std::unique_ptr<Ground> ground2  = std::make_unique<Ground>(400.f, 200.f);
    ground2->addToGame(500.f, 390.f);
    m_world->SetContactListener(static_cast<b2ContactListener*>(new ContactListener()));
    sf::Texture texture;
    texture.loadFromFile("/home/mrokita/CLionProjects/AngryGuns/res/glass.jpg");
    texture.setRepeated(true);
    sf::Sprite background(texture);
    background.setScale(0.1f,0.1f);
    background.setPosition(100, 100);
    while (window->isOpen() && m_alive) {
        window->clear(sf::Color::White);
        window->draw(background);
        m_world->Step(1/120.f, 8, 6);
        if((hero->getX()-offset) > 600.f){
            float new_offset = hero->getX() - 600.f;
            sf::View v = window->getView();
            v.move(new_offset - offset, 0.f);
            offset = new_offset;
            window->setView(v);
        }
        if((hero->getX()-offset) < 210.f){
            float new_offset = hero->getX() - 210.f;
            sf::View v = window->getView();
            v.move(new_offset - offset, 0.f);
            offset = new_offset;
            window->setView(v);
        }
        sf::Event event{};
        while (window->pollEvent(event)) {
            // SFML EVENTS
            if (event.type == sf::Event::Closed){
                window->close();
                this->stop();
            }
        }

        hero->onKeyPressed(event);
        for (b2Body *b = m_world->GetBodyList(); b != nullptr; b = b->GetNext()) {
            auto sprite = static_cast<Sprite*>(b->GetUserData());
            sprite->draw(window);
        }

        window->display();
    }
}

void AngryGuns::stop() {
    /* Kill the main loop */
    m_alive = false;
}