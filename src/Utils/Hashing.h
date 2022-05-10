//
// Created by cleme on 10/05/2022.
//

#ifndef CMD_ENGINE_HASHING_H
#define CMD_ENGINE_HASHING_H

#include <stdint.h>


class Hashing {
public:
    static uint32_t murmur3_32(const char *key, uint32_t len, uint32_t seed);
private:
    Hashing(){}
};


#endif //CMD_ENGINE_HASHING_H
