//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_FACTORY_H
#define CMD_ENGINE_FACTORY_H

#include <map>
#include "Objects/GameObject.h"

static class Factory {
    typedef GameObject* (*Creator)(Position pos, char c);
    static std::map<std::string, Creator> m_Factory;

    static GameObject* createObject(std::string type);
    static void Register(std::string type, Creator creator);
};


#endif //CMD_ENGINE_FACTORY_H
