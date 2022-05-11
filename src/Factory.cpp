//
// Created by cleme on 10/05/2022.
//

#include "Factory.h"

Factory *Factory::getInstance() {
    if (!instance)
        instance = new Factory;
    return instance;
}

GameObject *Factory::createObject(uint32_t type, Position pos, char c) {
    return m_Factory[type](pos, c);
}

void Factory::Register(uint32_t type, Factory::Creator creator) {
    m_Factory.insert(std::pair<uint32_t, Creator>(type, creator));
}


Factory *Factory::instance = 0;
