//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_GAMEOBJECT_H
#define CMD_ENGINE_GAMEOBJECT_H

#include "../Abstract/Object.h"
#include "../Abstract/Component.h"
#include "../Components/Transform.h"
#include <utility>
#include <vector>

class GameObject : Object {
protected:
    std::vector<Component *> components;
public:
    GameObject(Transform *nt);

    GameObject(const std::vector<Component *> nc) : components(std::move(nc)) {}

    ~GameObject();

    void Start() override;

    void Update() override;

    void FixedUpdate() override;

    void LateUpdate() override;
};


#endif //CMD_ENGINE_GAMEOBJECT_H
