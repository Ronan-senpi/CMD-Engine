//
// Created by Marine on 11/05/2022.
//

#pragma once


#include "../Abstract/Component.h"
#include "Transform.h"
#include "../Objects/GameObject.h"

class Enemy : public Component  {
private:
	std::vector<Position*> positions;
	int goal;
	float speed = 0.05;
protected :
	Transform* transform;
public:
	static const int typeHash = 3;
	Enemy(GameObject* go) : Component(go){}

	void Start() override;

	void Update() override;

	void FixedUpdate() override;

	void LateUpdate() override;
};