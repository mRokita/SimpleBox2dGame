cmake_minimum_required(VERSION 3.13)
project(AngryGuns)

set(CMAKE_CXX_STANDARD 14)

add_executable(AngryGuns main.cpp src/AngryGuns.cpp include/AngryGuns.h include/Sprite.h src/Drawable.cpp include/Drawable.h src/Box.cpp include/Box.h src/Ground.cpp include/Ground.h src/Hero.cpp include/Hero.h src/Singleton.cpp include/Singleton.h include/ContactListener.cpp include/ContactListener.h)
target_link_libraries(AngryGuns Box2D sfml-audio sfml-window sfml-graphics sfml-system)
