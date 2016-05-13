#include "stdafx.h"
#include "Locker_1.h"
#include "SnakeGameScene.h"
#include "Player.h"
#include "Babe.h"

bool Locker_1::init()
{
	if (GameObject::init() == false)
		return false;

	m_objectType = LOKCER_1;
	m_available = true;

	m_sprite = Sprite::create("locker_1.png");
	m_sprite->setScale(0.3f);
	addChild(m_sprite);

	return true;
}

void Locker_1::Play()
{
	runAction(CallFunc::create([](){
		Director::getInstance()->replaceScene(
			SnakeGameScene::createScene());
	}));
}

void Locker_1::SetEffect(Player* player, Babe* babe)
{
	player->ResetKeyState();
}
