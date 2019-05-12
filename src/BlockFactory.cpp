//
// Created by mrokita on 12.05.19.
//

#include "../include/BlockFactory.h"
#include "../include/CBlock.h"
#include "../include/TBlock.h"
#include "../include/LBlock.h"
#include "../include/SBlock.h"
#include "../include/IBlock.h"


void BlockFactory::addCBlock() {
    addBlock(new CBlock());
}

void BlockFactory::addTBlock() {
    addBlock(new TBlock());
}

void BlockFactory::addLBlock() {
    addBlock(new LBlock());
}


void BlockFactory::addIBlock() {
    addBlock(new IBlock());
}

void BlockFactory::addBlock(Block *b) {
    if(!blocks.empty()) blocks.pop_front();
    b->addToGame(AngryBlocks::getInstance().getOffset()+350.f, -100.f);
    blocks.emplace_back(b);
}

void BlockFactory::addSBlock() {
    addBlock(new SBlock());
}
