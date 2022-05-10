#include <iostream>
#include "src/Engine/MapLoader.h"
#include "src/Engine/System.h"
#include "src/Engine/Scene.h"
#include "src/Factory.h"
#include "src/Components/ASCIIRenderer.h"
#include <vector>

constexpr float updateRate = 1.f / 100.f;
constexpr float fixedUpdateRate = 1.f / 100.f;

Object *CreatePlayer(Position pos, char c) {
    GameObject *player = new GameObject();
    Transform *trans = new Transform(pos);
    ASCIIRenderer *renderer = new ASCIIRenderer(c, 0);

    player->AddComponent(trans);
    player->AddComponent(renderer);

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    MapLoader loader;
    std::string mapFile = "map1.txt";

    std::vector<Scene *> Scenes = {
            new Scene()
    };
    loader.LoadMap(Scenes[0], mapFile);
    System app(Scenes);
    app.Run();
    std::cin;

    Factory *fac = Factory::getInstance();
    fac->Register("Player", (*CreatePlayer));

}

