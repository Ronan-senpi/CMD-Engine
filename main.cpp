#include <iostream>
#include "src/Engine/MapLoader.h"
#include "src/Engine/System.h"
#include "src/Engine/Scene.h"
#include <vector>

constexpr float updateRate = 1.f/100.f;
constexpr float fixedUpdateRate = 1.f/100.f;

int main() {
    std::cout << "Hello, World!" << std::endl;
	MapLoader loader;
	std::string mapFile = "map1.txt";
	loader.LoadMap(mapFile);
    
    std::vector<Scene *> Scenes = {
            new Scene(),
            new Scene(),
    };
    System app(Scenes);
    app.Run();
}