//
// Created by rdher on 09/05/2022.
//

#include "Scene.h"

void Scene::Start() {
    for (GameObject* go: gameObjects) {
        go->Start();
    }
}

void Scene::Update() {
    for (GameObject* go: gameObjects) {
        go->Update();
    }
}

void Scene::FixedUpdate() {
    for (GameObject* go: gameObjects) {
        go->FixedUpdate();
    }
}

void Scene::LateUpdate() {
    for (GameObject* go: gameObjects) {
        go->LateUpdate();
    }
}

Scene::~Scene() {
    for (GameObject* go: gameObjects) {
		
    }
}

void Scene::SetSceneDimensions(int width, int height) {
	this->width = width;
	this->height = height;
}

void Scene::Instantiate(GameObject* go) {
	gameObjects.push_back(go);
}

int Scene::getWidth() const {
	return width;
}

int Scene::getHeight() const {
	return height;
}

std::vector<GameObject*> &Scene::getGameObjects() {
	return gameObjects;
}
