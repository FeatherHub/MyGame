#pragma once

#include "Player.h"
#include "Babe.h"

class GameObject : public Node
{
public:
	virtual ~GameObject() = default;
	virtual bool init();
	virtual void Play(Player* player, Babe* babe) = 0;
	Rect GetBoundingBox();

protected:
	Sprite* m_sprite;
	Player* m_player;
	Babe* m_babe;
	bool m_available;
};