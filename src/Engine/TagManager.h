//
// Created by cleme on 11/05/2022.
//

#ifndef CMD_ENGINE_TAGMANAGER_H
#define CMD_ENGINE_TAGMANAGER_H

#include <string>
#include <map>

class TagManager {
private:
    static TagManager *instance;

    TagManager() { m_TagManager = {}; }

public:
    std::map<std::string, int> m_TagManager;

    static TagManager *getInstance();

    int createTag(std::string);
};


#endif //CMD_ENGINE_TAGMANAGER_H
