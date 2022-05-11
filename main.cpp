#include <iostream>
#include "src/Engine/MapLoader.h"
#include "src/Engine/System.h"
#include "src/Engine/Scene.h"
#include "src/Factory.h"
#include "src/Components/ASCIIRenderer.h"
#include <vector>

constexpr float updateRate = 1.f / 100.f;
constexpr float fixedUpdateRate = 1.f / 100.f;

GameObject *CreateBaseObject(Position pos, char c) {
    GameObject *object = new GameObject();
    Transform *trans = new Transform(pos);
    ASCIIRenderer *renderer = new ASCIIRenderer(c, 0);

    object->AddComponent(trans);
    object->AddComponent(renderer);
    return object;
}

GameObject *CreatePlayer(Position pos, char c) {
    GameObject *player = CreateBaseObject(pos, c);
    //Add specifics player components
    return player;
}

int main() {
    Factory *fac = Factory::getInstance();
    fac->Register("Player", CreatePlayer);

//    fac->Register("Enemy", (*[](Position pos, char c) {
//        GameObject *player = CreateBaseObject(pos, c);
//        //Add specifics enemy components
//        return player;
//    }));
//    fac->Register("Wall", (*[](Position pos, char c) {
//        GameObject *player = CreateBaseObject(pos, c);
//        //Add specifics wall components
//        return player;
//    }));
//    fac->Register("Gold", (*[](Position pos, char c) {
//        GameObject *player = CreateBaseObject(pos, c);
//        //Add specifics gold components
//        return player;
//    }));

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



}

