//
// Created by rdher on 09/05/2022.
//

#ifndef CMD_ENGINE_SYSTEM_H
#define CMD_ENGINE_SYSTEM_H

#include <utility>
#include <vector>
#include "Object.h"
#include "Scene.h"

struct System : public Object{
private:
    std::vector<Scene*> Scenes;
    int selectedScene = 0;
    int frameCounter = 0;

public:
    inline System(const std::vector<Scene*>& s): Scenes(s){}

    void MainLoop();

    /**
     * call destroy of all objects
     */
    virtual ~System();

    /**
     * Start is called once before the update method.
     */
    void Start() override;
    /**
     * Update is called every frame is the first method called.
     */
    void Update() override;
    /**
     * Frame-rate independent, FixedUpdate for physics calculations.
     */
    void FixedUpdate() override;
    /**
     * LateUpdate is called every frame
     * This method clear & repopulate frames
     */
    void LateUpdate() override;


};


#endif //CMD_ENGINE_SYSTEM_H
