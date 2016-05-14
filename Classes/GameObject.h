#pragma once

#include "GameObjectConfig.h"

class Player;
class Babe;

class GameObject : public Node
{
public:
	virtual ~GameObject() = default;
	virtual bool init();
	virtual void Play() = 0;
	virtual void SetEffect(Player* player, Babe* babe) = 0;
	OBJECT_TYPE GetObjectType() { return m_objectType; }
	Rect GetBoundingBox();

protected:
	Sprite* m_sprite;
	Player* m_player;
	OBJECT_TYPE m_objectType;
	bool m_available;
};