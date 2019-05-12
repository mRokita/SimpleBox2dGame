cmake_minimum_required(VERSION 3.13)
project(AngryGuns)

set(CMAKE_CXX_STANDARD 14)

add_executable(AngryGuns main.cpp src/AngryBlocks.cpp include/AngryBlocks.h include/Sprite.h src/Drawable.cpp include/Drawable.h src/Box.cpp include/Box.h src/Ground.cpp include/Ground.h src/Block.cpp include/Block.h src/Singleton.cpp include/Singleton.h src/ContactListener.cpp include/ContactListener.h src/GroundFactory.cpp include/GroundFactory.h src/BlockFactory.cpp include/BlockFactory.h src/TBlock.cpp include/TBlock.h)
target_link_libraries(AngryGuns Box2D sfml-audio sfml-window sfml-graphics sfml-system)
