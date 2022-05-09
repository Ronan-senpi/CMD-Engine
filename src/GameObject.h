//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_GAMEOBJECT_H
#define CMD_ENGINE_GAMEOBJECT_H

#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include <vector>

class GameObject : Object {
protected:
    std::vector<Component*> components;
public:
    GameObject(Transform* nt);

    GameObject(const std::vector<Component*>& nc): components(nc){}

    ~GameObject();

    void Start() override;

    void Update() override;

    void FixedUpdate() override;

    void LateUpdate() override;
};


#endif //CMD_ENGINE_GAMEOBJECT_H
