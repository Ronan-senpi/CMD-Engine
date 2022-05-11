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
    Transform() : pos() {}

    Transform(float nx, float ny) : pos(nx, ny) {}

    Transform(Position &np) : pos(np) {}

    Transform(Transform &nt) : pos(nt.GetPosition()) {}

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
