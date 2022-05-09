//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_OBJECT_H
#define CMD_ENGINE_OBJECT_H

#include <iostream>

class Object {
protected:
    std::string tag;
    int hashed_tag;
public:

    /**
     * Start is called once before the update method.
     */
    virtual void Start() = 0;

    /**
     * Update is called every frame before render.
     */
    virtual void Update() = 0;

    /**
     * Frame-rate independent, FixedUpdate for physics calculations.
     */
    virtual void FixedUpdate() = 0;

    /**
     * LateUpdate is called every frame
     * This method clear & repopulate frames
     */
    virtual void LateUpdate() = 0;
};


#endif //CMD_ENGINE_OBJECT_H
