//
// Created by cleme on 09/05/2022.
//

#include "GameObject.h"

GameObject::GameObject(Transform* nt) {
    components.push_back(nt);
}

GameObject::~GameObject() {
    for (Component *c: components) {
        c->~Component();
    }
}

void GameObject::Start() {
    for (Component *c: components) {
        c->Start();
    }
}

void GameObject::Update() {
    for (Component *c: components) {
        c->Update();
    }
}

void GameObject::FixedUpdate() {
    for (Component *c: components) {
        c->FixedUpdate();
    }
}

void GameObject::LateUpdate() {
    for (Component *c: components) {
        c->LateUpdate();
    }
}
