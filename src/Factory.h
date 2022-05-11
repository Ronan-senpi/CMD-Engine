//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_FACTORY_H
#define CMD_ENGINE_FACTORY_H

#include <map>
#include "Objects/GameObject.h"

class Factory {
private:
    static Factory *instance;

    Factory() { m_Factory = {}; }

public:
    static Factory *getInstance();

    typedef GameObject *(*Creator)(Position pos, char c);

    std::map<int, Creator> m_Factory;

    GameObject *createObject(int type, Position pos, char c);

    void Register(int type, Creator creator);


};


#endif //CMD_ENGINE_FACTORY_H
