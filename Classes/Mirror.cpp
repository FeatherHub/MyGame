#include "stdafx.h"
#include "GameObject.h"
#include "Mirror.h"

bool Mirror::init()
{
	if (GameObject::init() == false)
	{
		return false;
	}

	m_sprite = Sprite::create("mirror.png");
	addChild(m_sprite);

	return true;
}

void Mirror::Play(Player* player, Babe* babe)
{
	if (m_available == false)
	{
		return;
	}

	player->SetState(EXIT_BABE);

	m_available = false;
	runAction(Sequence::create(
		CallFunc::create([](){CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("hate.wav"); }),
		DelayTime::create(1.0f),
		CallFunc::create([&](){ m_available = true; }),
		nullptr));
}
