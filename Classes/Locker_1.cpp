#include "stdafx.h"
#include "GameObject.h"
#include "Locker_1.h"
#include "SnakeScene.h"

bool Locker_1::init()
{
	if (GameObject::init() == false)
	{
		return false;
	}

	m_sprite = Sprite::create("locker_1.png");
	addChild(m_sprite);

	return true;
}

void Locker_1::Play(Player* player, Babe* babe)
{
	if (m_available == false)
	{
		return;
	}

	player->ResetKeyState();

	runAction(CallFunc::create([](){
		Director::getInstance()->replaceScene(
			SnakeScene::createScene()); })
			);
}
