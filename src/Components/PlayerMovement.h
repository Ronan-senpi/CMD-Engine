//
// Created by rdher on 11/05/2022.
//

#ifndef CMD_ENGINE_PLAYERMOVEMENT_H
#define CMD_ENGINE_PLAYERMOVEMENT_H

#include "../Abstract/Component.h"
#include "Transform.h"

class PlayerMovement : public Component {
protected:
    Transform* transform;
public:
    void Start() override;

    void Update() override;

    void LateUpdate() override;

    void FixedUpdate() override;
};


#endif //CMD_ENGINE_PLAYERMOVEMENT_H
