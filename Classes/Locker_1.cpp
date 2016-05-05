#include "stdafx.h"
#include "Locker_1.h"
#include "SnakeGameScene.h"

bool Locker_1::init()
{
	if (GameObject::init() == false)
		return false;

	m_objectType = LOKCER_1;
	m_available = true;

	m_sprite = Sprite::create("locker_1.png");
	addChild(m_sprite);
}

void Locker_1::Play()
{
	
}

void Locker_1::SetEffect(Player* player, Babe* babe)
{
	return;
}
