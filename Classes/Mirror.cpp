#include "stdafx.h"
#include "Mirror.h"
#include "SimpleAudioEngine.h"
#include "Player.h"
#include "Babe.h"

bool Mirror::init()
{
	if (GameObject::init() == false)
		return false;

	m_sprite = Sprite::create("mirror.png");
	m_sprite->setScale(0.4f);
	addChild(m_sprite);

	m_objectType = MIRROR;

	return true;
}

void Mirror::Play()
{
	if (m_available == false)
		return;

	runAction(Sequence::create(
		CallFunc::create([&](){ m_available = false; }),
		DelayTime::create(0.01f),
		CallFunc::create([](){CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("hate.wav"); }),
		DelayTime::create(1.00f),
		CallFunc::create([&](){ m_available = true; }),
		nullptr));
}

void Mirror::SetEffect(Player* player, Babe* babe)
{
	player->ExitEvent();
}
