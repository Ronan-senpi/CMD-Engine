//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_OBJECT_H
#define CMD_ENGINE_OBJECT_H

#include <iostream>

class Object {
protected:
    std::string tag;
    int hashed_tag;
public:
    virtual void Start() = 0;

    virtual void Update() = 0;

    virtual void FixedUpdate() = 0;

    virtual void LateUpdate() = 0;
};


#endif //CMD_ENGINE_OBJECT_H
