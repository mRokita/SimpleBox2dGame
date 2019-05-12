//
// Created by mrokita on 12.05.19.
//

#include "../include/BlockFactory.h"
#include "../include/TBlock.h"

void BlockFactory::addTBlock() {
    if(!blocks.empty()) blocks.pop_front();
    auto b = new TBlock();
    b->addToGame(AngryBlocks::getInstance().getOffset()+350.f, -100.f);
    blocks.emplace_back(b);
}
