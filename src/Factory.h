//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_FACTORY_H
#define CMD_ENGINE_FACTORY_H

#include <map>
#include "Abstract/Object.h"
#include "Creator.h"

enum ObjectType{
    Player,
    Enemy,
    Wall,
    Loot
};

class Factory {
    std::map<ObjectType, Creator*> m_Factory;
    Object* createObject(ObjectType type);



};


#endif //CMD_ENGINE_FACTORY_H
