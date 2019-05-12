//
// Created by mrokita on 12.05.19.
//

#ifndef ANGRYGUNS_BLOCKFACTORY_H
#define ANGRYGUNS_BLOCKFACTORY_H


#include "Singleton.h"
#include "Block.h"

class BlockFactory : public Singleton<BlockFactory> {
private:
    std::deque<std::shared_ptr<Block>> blocks;
    void addBlock(Block* b);
public:
    void addTBlock();
    void addCBlock();
    void addSBlock();
    void addIBlock();
    void addLBlock();
    std::shared_ptr<Block> getCurrentBlock() {
        return blocks.front();
    }
};


#endif //ANGRYGUNS_BLOCKFACTORY_H
