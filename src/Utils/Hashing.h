//
// Created by cleme on 10/05/2022.
//

#ifndef CMD_ENGINE_HASHING_H
#define CMD_ENGINE_HASHING_H

#include <stdint.h>


class Hashing {
public:
    static int murmur3_32(const char *key, int len, int seed);
private:
    Hashing(){}
};


#endif //CMD_ENGINE_HASHING_H
