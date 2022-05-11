
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_POSITION_H
#define CMD_ENGINE_POSITION_H


struct Position {
    static Position zero;
    static Position one;
    static Position up;
    static Position down;
    static Position left;
    static Position right;
    float x;
    float y;

    Position() : x(0), y(0) {}

    Position(float nx, float ny) : x(nx), y(ny) {}

    Position(const Position &np) : x(np.x), y(np.y) {}

    void operator*=(const Position &b);

    void operator*=(const float &b);

    void operator+=(const Position &b);

    void operator+=(const float &b);

};

Position operator*(const Position &a, const Position &b);

Position operator*(const float &a, const Position &b);

Position operator*(const Position &a, const float &b);

Position operator+(const Position &a, const Position &b);

Position operator+(const float &a, const Position &b);

Position operator+(const Position &a, const float &b);

#endif //CMD_ENGINE_POSITION_H
