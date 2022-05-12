//
// Created by Marine on 11/05/2022.
//

#include "Enemy.h"
#include "../Engine/Time.h"

void Enemy::Start() {
	transform = gameObject->getComponent<Transform>();
	if (transform == nullptr) {
		std::cerr << "Enemy didn't found Transform" << std::endl;
	}
	positions.push_back(new Position(10,8));
	positions.push_back(new Position(22,12));
	goal = 0;
}

void Enemy::Update() {
	float coeff = speed;
	Position oldPos = transform->pos;
	//std::cout << newPos.x << " " << newPos.y << std::endl;
	Position* destination = positions[goal];
	Position dir = (*destination) - oldPos;
	dir.normalize();
	Position newPos =  transform->pos + Position(dir.x * coeff,dir.y * coeff);

	transform->pos = newPos;
	float magnitude = ((*destination) - transform->pos).magnitude();
	std::cout << "magnitude " << magnitude << std::endl;
	if(magnitude < 0.5){
		goal = (goal + 1)%(positions.size());
	}

}

void Enemy::FixedUpdate() {

}

void Enemy::LateUpdate() {
}