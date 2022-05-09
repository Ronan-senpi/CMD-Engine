//
// Created by rdher on 09/05/2022.
//

#include "Scene.h"

void Scene::Start() {
    for (GameObject *go: GameObjects) {
        go->Start();
    }
}

void Scene::Update() {
    for (GameObject *go: GameObjects) {
        go->Update();
    }
}

void Scene::FixedUpdate() {
    for (GameObject *go: GameObjects) {
        go->FixedUpdate();
    }
}

void Scene::LateUpdate() {
    for (GameObject *go: GameObjects) {
        go->LateUpdate();
    }
}

Scene::~Scene() {
    for (GameObject *go: GameObjects) {
        delete go;
    }
}
