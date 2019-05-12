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
    long long frame;
    Drawable() {frame = 0;}
    virtual void draw(const std::shared_ptr<sf::RenderWindow> &window){
        frame += 1;
    }
    ~ Drawable() {
        std::cout << "Destroy drawable" << std::endl;
    }

};


#endif //ANGRYGUNS_DRAWABLE_H
