//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_FACTORY_H
#define CMD_ENGINE_FACTORY_H

#include <map>
#include "Objects/GameObject.h"

class Factory {

    typedef Object *(*Creator)(Position pos, char c);

    std::map<std::string, Creator> m_Factory;

    Object *createObject(std::string type, Position pos, char c);

    void Register(std::string type, Creator creator);
};


#endif //CMD_ENGINE_FACTORY_H
