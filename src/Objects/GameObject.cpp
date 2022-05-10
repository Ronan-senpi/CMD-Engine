//
// Created by cleme on 09/05/2022.
//

#include "GameObject.h"

/*GameObject::GameObject(std::unique_ptr<Transform> nt) {
    components.push_back(std::move(nt));
}*/

GameObject::~GameObject() {
    for (std::unique_ptr<Component>& c: components) {
        //delete c;
    }
}

void GameObject::Start() {
    for (std::unique_ptr<Component>& c: components) {
        c->Start();
    }
}

void GameObject::Update() {
    for (std::unique_ptr<Component>& c: components) {
        c->Update();
    }
}

void GameObject::FixedUpdate() {
    for (std::unique_ptr<Component>& c: components) {
        c->FixedUpdate();
    }
}

void GameObject::LateUpdate() {
    for (std::unique_ptr<Component>& c: components) {
        c->LateUpdate();
    }
}

GameObject::GameObject(std::vector<std::unique_ptr<Component>> nc) {
	components = std::move(nc);
}
