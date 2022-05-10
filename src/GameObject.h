//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_GAMEOBJECT_H
#define CMD_ENGINE_GAMEOBJECT_H

#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include <utility>
#include <vector>

class GameObject : Object {
protected:
	std::vector<std::unique_ptr<Component>> components;
public:
	GameObject(std::vector<std::unique_ptr<Component>> nc);
    //GameObject(std::unique_ptr<Transform> nt);


    ~GameObject();

    void Start() override;

    void Update() override;

    void FixedUpdate() override;

    void LateUpdate() override;
};


#endif //CMD_ENGINE_GAMEOBJECT_H