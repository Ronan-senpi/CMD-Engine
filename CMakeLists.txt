cmake_minimum_required(VERSION 3.22)
project(CMD_Engine)

set(CMAKE_CXX_STANDARD 20)
add_executable(CMD_Engine main.cpp
        src/System.cpp
        src/Object.cpp
        src/GameObject.cpp
        src/Component.cpp
        src/Transform.cpp
        src/MapLoader.cpp
        src/Scene.cpp)

add_custom_command(TARGET CMD_Engine PRE_BUILD
        COMMAND robocopy ${PROJECT_SOURCE_DIR}/resources/ ${PROJECT_BINARY_DIR}/resources /E /NS /NC /NFL /NDL /NP /NJH /NJS  || cmd /c "exit /b 0")
