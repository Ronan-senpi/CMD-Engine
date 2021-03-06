#include <iostream>
#include "src/Engine/MapLoader.h"
#include "src/Engine/System.h"
#include "src/Engine/Scene.h"
#include "src/Factory.h"
#include "src/Components/ASCIIRenderer.h"
#include "src/Engine/TagManager.h"
#include "src/Components/PlayerMovement.h"
#include <vector>

constexpr float updateRate = 1.f / 100.f;
constexpr float fixedUpdateRate = 1.f / 100.f;

GameObject *CreateBaseObject(Position pos, char c) {
    GameObject *object = new GameObject();
    Transform *trans = new Transform(object,pos);
    ASCIIRenderer *renderer = new ASCIIRenderer(object,c, 0);

    object->AddComponent(trans);
    object->AddComponent(renderer);
    return object;
}

GameObject *CreatePlayer(Position pos, char c) {
    GameObject *player = CreateBaseObject(pos, c);
    player->tag = TagManager::getInstance()->m_TagManager["Player"];
    //Add specifics player components
    PlayerMovement* pm = new PlayerMovement(player);
    player->AddComponent(pm);
    return player;
}

GameObject *CreateEnemy(Position pos, char c) {
    GameObject *enemy = CreateBaseObject(pos, c);
    enemy->tag = TagManager::getInstance()->m_TagManager["Enemy"];

    //Add specifics player components
    return enemy;
}

GameObject *CreateWall(Position pos, char c) {
    GameObject *wall = CreateBaseObject(pos, c);
    wall->tag = TagManager::getInstance()->m_TagManager["Wall"];

    //Add specifics player components
    return wall;
}


GameObject *CreateGold(Position pos, char c) {
    GameObject *gold = CreateBaseObject(pos, c);
    gold->tag = TagManager::getInstance()->m_TagManager["Gold"];
    //Add specifics player components
    return gold;
}

int main() {
    TagManager *tagManager = TagManager::getInstance();
    int playerHashed = tagManager->createTag("Player");
    int enemyHashed = tagManager->createTag("Enemy");
    int wallHashed = tagManager->createTag("Wall");
    int goldHashed = tagManager->createTag("Gold");
    Factory *fac = Factory::getInstance();
    fac->Register(playerHashed, CreatePlayer);
    fac->Register(enemyHashed, CreateEnemy);
    fac->Register(wallHashed, CreateWall);
    fac->Register(goldHashed, CreateGold);
    
    std::cout << "Hello, World!" << std::endl;
    MapLoader loader;
    std::string mapFile = "map1.txt";

    std::vector<Scene *> Scenes = {
            new Scene()
    };
    loader.LoadMap(fac, Scenes[0], mapFile);
    System app(Scenes);
    app.Run();

    std::string str2;
    std::cin >> str2 ;


}

