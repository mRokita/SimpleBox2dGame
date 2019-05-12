//
// Created by mrokita on 12.05.19.
//

#include "../include/GroundFactory.h"

void GroundFactory::processChunks(){
    if(this->chunks.empty()){
        addGround(960.f, 120.f);
    } else {
        float x = chunks.back()->getX();
        if(x <= chunks.back()->width/2.0+943.f+AngryBlocks::getInstance().getOffset()){
            addGround(960.f, 120.f);
            addHole();
        }
    }
    while(this->chunks.size() > 15){
        chunks.pop_front();
    }
}

void GroundFactory::addHole() {
    for(auto d : BlockFactory::getInstance().getCurrentBlock()->getHoleDimensions()){
        addGround(d.x, d.y);
    }
}

void GroundFactory::addGround(float width, float height) {
    auto g = new Ground(width+1.5f, height);

    float x = this->chunks.empty() ? 0.f : this->chunks.back()->getX();
    float previousWidth = chunks.empty() ? 0.f : chunks.back()->width;
    g->addToGame(x+previousWidth/2.f+width/2.f, 540.f-(height/2.f));

    this->chunks.emplace_back(g);
}
