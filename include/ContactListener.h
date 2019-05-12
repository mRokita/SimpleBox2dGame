//
// Created by mrokita on 06.05.19.
//

#ifndef ANGRYGUNS_CONTACTLISTENER_H
#define ANGRYGUNS_CONTACTLISTENER_H


#include <Box2D/Dynamics/Contacts/b2Contact.h>
#include "Sprite.h"

class ContactListener : public b2ContactListener {
    void BeginContact(b2Contact *contact) override {
        auto SpriteA = static_cast<Sprite *>(contact->GetFixtureA()->GetBody()->GetUserData());
        auto SpriteB = static_cast<Sprite *>(contact->GetFixtureB()->GetBody()->GetUserData());
        if (SpriteA && SpriteB && SpriteA->isAlive() && SpriteB->isAlive()) {
            SpriteA->startContact(SpriteB);
            SpriteB->startContact(SpriteA);
        }
    }

    void EndContact(b2Contact *contact) override {

        auto SpriteA = static_cast<Sprite *>(contact->GetFixtureA()->GetBody()->GetUserData());
        auto SpriteB = static_cast<Sprite *>(contact->GetFixtureB()->GetBody()->GetUserData());
        if (SpriteA && SpriteB && SpriteA->isAlive() && SpriteB->isAlive()) {
            SpriteA->endContact(SpriteB);
            SpriteB->endContact(SpriteA);
        }

    }
};


#endif //ANGRYGUNS_CONTACTLISTENER_H
