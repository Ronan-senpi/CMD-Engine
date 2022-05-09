cmake_minimum_required(VERSION 3.22)
project(CMD_Engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(CMD_Engine
        main.cpp
        src/System.cpp
        src/System.h
        src/Object.cpp
        src/Object.h
        src/GameObject.cpp
        src/GameObject.h
        src/Component.cpp
        src/Component.h
        src/Transform.cpp
        src/Transform.h
        src/Position.cpp
        src/Position.h
        src/Scene.cpp
        src/Scene.h)
