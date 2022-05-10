//
// Created by rdher on 10/05/2022.
//

#ifndef CMD_ENGINE_INPUT_H
#define CMD_ENGINE_INPUT_H

#include "KeyCode.h"
#include <conio.h>

namespace Input {



    bool GetKeyDown(KeyCode keyCode) {
        if (_kbhit()) {
            int ch = _getch();
            if (ch == keyCode)
                return true;
        }
        return false;
    }

};


#endif //CMD_ENGINE_INPUT_H
