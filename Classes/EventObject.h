#pragma once

#include "GameObject.h"

class Player;

class EventObject : public GameObject
{
public:
	OBJECT_TYPE GetObjectType() { return OBJECT_TYPE::EVENT; }
};