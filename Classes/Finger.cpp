#include "stdafx.h"
#include "Finger.h"

Finger::Finger()
{
	m_direction = NORTH;
}

bool Finger::init()
{
	if (PlayableObject::init() == false)
		return false;

	m_sprite = Sprite::create("finger.png");
	m_sprite->setAnchorPoint(Vec2(0.5f, 1.f));
	auto cSize = m_sprite->getContentSize();
	setPosition(Vec2(cSize.width/2, cSize.height));
	addChild(m_sprite);

	scheduleUpdate();

	return true;
}

void Finger::update(float delta)
{
	switch (m_pressedKey)
	{
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		m_direction = SOUTH;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		m_direction = NORTH;
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_direction = WEST;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_direction = EAST;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		//crash open the locker
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		Director::getInstance()->popScene();
		break;
	}

	//가가가각 -> HP 0 Game Over Again
	//가각 -> Turn!
	
	switch (m_direction)
	{
	case NORTH:
		setPosition(getPosition() + Vec2(0, +m_speed));

		break;
	case SOUTH:
		setPosition(getPosition() + Vec2(0, -m_speed));

		break;
	case WEST:
		setPosition(getPosition() + Vec2(-m_speed, 0));

		break;
	case EAST:
		setPosition(getPosition() + Vec2(m_speed, 0));

		break;
	}
}

