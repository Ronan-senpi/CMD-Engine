//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_COMPONENT_H
#define CMD_ENGINE_COMPONENT_H
#include "Object.h"
class GameObject;
class Component : public Object{
public:
    GameObject* gameObject;
	static const int typeHash = 0;

};


#endif //CMD_ENGINE_COMPONENT_H
