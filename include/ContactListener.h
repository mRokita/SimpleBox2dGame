//
// Created by mrokita on 06.05.19.
//

#ifndef ANGRYGUNS_CONTACTLISTENER_H
#define ANGRYGUNS_CONTACTLISTENER_H


#include <Box2D/Dynamics/Contacts/b2Contact.h>
#include "Sprite.h"

class ContactListener : public b2ContactListener {
    void BeginContact(b2Contact *contact) override {
        //check if fixture A was a ball
        void *bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<Sprite *>( bodyUserData )->startContact(contact->GetFixtureB()->GetBody());

        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();

        if (bodyUserData)
            static_cast<Sprite *>( bodyUserData )->startContact(contact->GetFixtureA()->GetBody());

    }

    void EndContact(b2Contact *contact) override {

        //check if fixture A was a ball
        void *bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<Sprite *>( bodyUserData )->endContact(contact->GetFixtureB()->GetBody());

        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<Sprite *>( bodyUserData )->endContact(contact->GetFixtureA()->GetBody());

    }
};


#endif //ANGRYGUNS_CONTACTLISTENER_H
