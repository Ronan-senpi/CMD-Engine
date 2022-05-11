//
// Created by cleme on 10/05/2022.
//

#include "Factory.h"

Factory *Factory::getInstance() {
    if (!instance)
        instance = new Factory;
    return instance;
}

GameObject *Factory::createObject(int type, Position pos, char c) {
    return m_Factory[type](pos, c);
}

void Factory::Register(int type, Factory::Creator creator) {
    m_Factory.insert(std::pair<int, Creator>(type, creator));
}


Factory *Factory::instance = 0;
