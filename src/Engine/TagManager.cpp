//
// Created by cleme on 11/05/2022.
//

#include "TagManager.h"
#include "../Utils/Hashing.h"

TagManager *TagManager::getInstance() {
    if (!instance)
        instance = new TagManager;
    return instance;
}

int TagManager::createTag(std::string tag) {
    int hashed = Hashing::murmur3_32(tag.c_str(), 10, 9843713);
    m_TagManager.insert(std::pair<std::string, int>(tag, hashed));
    return hashed;
}


TagManager *TagManager::instance = 0;
