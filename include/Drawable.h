//
// Created by mrokita on 04.05.19.
//

#ifndef ANGRYGUNS_DRAWABLE_H
#define ANGRYGUNS_DRAWABLE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include <iostream>

class Drawable {
public:
    Drawable() = default;
    virtual void draw(const std::shared_ptr<sf::RenderWindow> &window){
        sf::RectangleShape rectangleShape(sf::Vector2f(40.f, 40.f));
        rectangleShape.setPosition(480.f, 0.f);
        rectangleShape.setFillColor(sf::Color::Black);
        window->draw(rectangleShape);
    }
    ~ Drawable() {
        std::cout << "Destroy drawable" << std::endl;
    }

};


#endif //ANGRYGUNS_DRAWABLE_H
