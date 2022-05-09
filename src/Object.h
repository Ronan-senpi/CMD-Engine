//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_OBJECT_H
#define CMD_ENGINE_OBJECT_H


class Object {
public:
    Object();

    virtual ~Object();

    virtual void Destroy() {
        delete this;
    }

    virtual void Start();

    virtual void Update();

    virtual void FixedUpdate();

    virtual void LateUpdate();
};


#endif //CMD_ENGINE_OBJECT_H
