//
// Created by rdher on 11/05/2022.
//
#include "Input.h"

bool Input::GetKeyDown(KeyCode keyCode) {
    if (_kbhit()) {
        int ch = _getch();
        if (ch == keyCode)
            return true;
    }
    return false;
}