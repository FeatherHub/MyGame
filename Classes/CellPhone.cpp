#include "stdafx.h"
#include "CellPhone.h"
#include "Player.h"

bool CellPhone::init()
{
	if (GameObject::init() == false)
		return false;

	m_keyboardListener = EventListenerKeyboard::create();
	m_keyboardListener->onKeyPressed = CC_CALLBACK_1(CellPhone::OnKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_keyboardListener, this);
	m_keyboardListener->setEnabled(false);

	m_sprite = Sprite::create("cellphone.png");
	addChild(m_sprite);

	return true;
}

void CellPhone::Play()
{
	m_keyboardListener->setEnabled(true);


}

void CellPhone::SetEffect(Player* player, Babe* babe)
{
	m_player = player;
	m_player->unscheduleUpdate();

	auto parent = player->getParent();
	m_black = Sprite::create("black.png");
	m_black->setAnchorPoint(Vec2(0, 0));
	m_black->setOpacity(0);
	m_black->setScale(1.2f);
	parent->addChild(m_black, 5);
	m_black->runAction(FadeTo::create(0.6f, 100));
}

void CellPhone::OnKeyPressed(EventKeyboard::KeyCode keyCode)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		m_black->removeFromParent();
		m_player->ResetKeyState();
		m_player->scheduleUpdate();
		break;
	}
}
