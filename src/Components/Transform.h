//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_TRANSFORM_H
#define CMD_ENGINE_TRANSFORM_H


#include "../Abstract/Component.h"
#include "../Math/Position.h"

class Transform : public Component {
public:
    Position pos;
    Transform(GameObject* go) :Component(go), pos() {}

    Transform(GameObject* go, float nx, float ny) :Component(go), pos(nx, ny) {}

    Transform(GameObject* go, Position &np) :Component(go), pos(np) {}

    Transform(GameObject* go, Transform &nt) :Component(go), pos(nt.GetPosition()) {}

    ~Transform();

    Position GetPosition();

    void SetPosition(float nx, float ny);

    void SetPosition(Position &np);

    void SetPosition(Transform &nt);

	void Start() override;

	void Update() override;

	void FixedUpdate() override;

	void LateUpdate() override;
	static const int typeHash = 1;
};


#endif //CMD_ENGINE_TRANSFORM_H
