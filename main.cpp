#include <iostream>
#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>
#include "include/AngryGuns.h"


int main() {
    AngryGuns::getInstance()->start();
    return 0;
}