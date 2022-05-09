//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_POSITION_H
#define CMD_ENGINE_POSITION_H


struct Position {
    float x;
    float y;

    Position(): x(0), y(0){}
    Position(float nx, float ny) : x(nx), y(ny){}
    Position(Position& np):x(np.x), y(np.y){}
};


#endif //CMD_ENGINE_POSITION_H
