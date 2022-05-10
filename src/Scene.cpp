//
// Created by rdher on 09/05/2022.
//

#include "Scene.h"

void Scene::Start() {
    for (std::unique_ptr<GameObject>& go: gameObjects) {
        go->Start();
    }
}

void Scene::Update() {
    for (std::unique_ptr<GameObject>& go: gameObjects) {
        go->Update();
    }
}

void Scene::FixedUpdate() {
    for (std::unique_ptr<GameObject>& go: gameObjects) {
        go->FixedUpdate();
    }
}

void Scene::LateUpdate() {
    for (std::unique_ptr<GameObject>& go: gameObjects) {
        go->LateUpdate();
    }
}

Scene::~Scene() {
    for (std::unique_ptr<GameObject>& go: gameObjects) {
		
    }
}

void Scene::SetSceneDimensions(int width, int height) {
	this->width = width;
	this->height = height;
}

void Scene::Instantiate(std::unique_ptr<GameObject> go) {
	gameObjects.push_back(std::move(go));
}
