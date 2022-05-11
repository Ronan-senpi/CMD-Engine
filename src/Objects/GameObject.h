//
// Created by cleme on 09/05/2022.
//

#ifndef CMD_ENGINE_GAMEOBJECT_H
#define CMD_ENGINE_GAMEOBJECT_H

#include "../Abstract/Object.h"
#include "../Abstract/Component.h"
#include "../Components/Transform.h"
#include <utility>
#include <vector>
#include <cassert>
class GameObject : public Object {
protected:
	std::vector<Component*> components;
public:
    int instanceTag;
    static int tag;

    GameObject();
	GameObject(std::vector<Component*> nc);
    //GameObject(std::unique_ptr<Transform> nt);

    GameObject(GameObject& go);

    ~GameObject();

    void Start() override;

    void Update() override;

    void FixedUpdate() override;

    void LateUpdate() override;

	template<class T>
	T* getComponent() {
		static_assert(std::is_base_of<Component, T>::value, "type parameter of this class must derive from Component");
		for(Component* c : components){
			//std::unique_ptr<T>& t = std::make(static_cast<T>(c));
			T* casted = dynamic_cast<T*>(c);
			if(casted != nullptr){
				assert(T::typeHash == casted->typeHash);
				return casted;
			}
		}
		return nullptr;
	}

	void AddComponent(Component* comp);
};


#endif //CMD_ENGINE_GAMEOBJECT_H
