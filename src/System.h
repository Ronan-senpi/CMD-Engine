//
// Created by rdher on 09/05/2022.
//

#ifndef CMD_ENGINE_SYSTEM_H
#define CMD_ENGINE_SYSTEM_H

#include <utility>
#include <vector>

class Scene;

struct System {
private:
    std::vector<Scene*> Scenes;
    int selectedScene = 0;
    int frameCounter = 0;

public:
    inline System(std::vector<Scene*> s): Scenes(std::move(s)){}

    /**
     * call destroy of all objects
     */
    virtual ~System();

    /**
     * Start is called once before the update method.
     */
    void Start();
    /**
     * Update is called every frame is the first method called.
     */
    void Update();
    /**
     * Frame-rate independent, FixedUpdate for physics calculations.
     */
    void FixedUpdate();
    /**
     * LateUpdate is called every frame
     * This method clear & repopulate frames
     */
    void LateUpdate();


};


#endif //CMD_ENGINE_SYSTEM_H
