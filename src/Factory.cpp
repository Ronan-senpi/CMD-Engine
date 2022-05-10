//
// Created by cleme on 10/05/2022.
//

#include "Factory.h"

GameObject* Factory::createObject(std::string type) {
    Creator creator = m_Factory[type];
}

void Factory::Register(std::string type, Factory::Creator creator) {
    m_Factory.insert(std::pair<std::string, Creator>(type, creator));
}
