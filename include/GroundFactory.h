//
// Created by mrokita on 12.05.19.
//

#ifndef ANGRYGUNS_GROUNDFACTORY_H
#define ANGRYGUNS_GROUNDFACTORY_H


#include <list>
#include "Ground.h"
#include "Block.h"
#include "BlockFactory.h"

class GroundFactory : public Singleton<GroundFactory> {
public:
    void processChunks();
    void addHole();
    GroundFactory() = default;
private:
    std::list<std::shared_ptr<Ground>> chunks;
    void addGround(float width, float height);

};


#endif //ANGRYGUNS_GROUNDFACTORY_H
