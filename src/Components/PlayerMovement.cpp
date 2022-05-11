//
// Created by rdher on 11/05/2022.
//

#include "PlayerMovement.h"
#include "../Utils/Input/Input.h"
#include "../Utils/Input/KeyCode.h"
#include "../Engine/Time.h"
#include "../Objects/GameObject.h"

void PlayerMovement::Start() {
    transform = gameObject->getComponent<Transform>();
    if (transform != nullptr) {
        std::cerr << "PlayerMovement n'a pas trouvé de transform";
    }
}

void PlayerMovement::Update() {
    if (Input::GetKeyDown(KeyCode::Z)) {
        transform->pos += (Position::up * Time::DeltaTime());
    }
    if (Input::GetKeyDown(KeyCode::Q)) {
        transform->pos += Position::left * Time::DeltaTime();
    }
    if (Input::GetKeyDown(KeyCode::S)) {
        transform->pos += Position::down * Time::DeltaTime();
    }
    if (Input::GetKeyDown(KeyCode::D)) {
        transform->pos += Position::right * Time::DeltaTime();
    }
}

void PlayerMovement::LateUpdate() {

}

void PlayerMovement::FixedUpdate() {

}
