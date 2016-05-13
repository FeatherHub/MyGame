#include "stdafx.h"
#include "Finger.h"

Finger::Finger() : ACTION_TIME(0.f)
{
	m_direction = NORTH;
}

bool Finger::init()
{
	if (PlayableObject::init() == false)
		return false;

	m_sprite = Sprite::create("finger.png");
	m_sprite->setAnchorPoint(Vec2(0.5f, 1.f));
	addChild(m_sprite);

	m_sprSize = m_sprite->getContentSize();
	setPosition(Vec2(m_sprSize.width / 2, m_sprSize.height));

	scheduleUpdate();

	return true;
}

void Finger::update(float delta)
{
	switch (m_pressedKey)
	{
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		switch (m_direction)
		{
		case WEST:
			m_direction = SOUTH;
			turn(-90, Vec2(0, -m_sprSize.width));
			break;
		case EAST:
			m_direction = SOUTH;
			turn(90, Vec2(0, -m_sprSize.width));
			break;
		}
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		switch (m_direction)
		{
		case WEST:
			m_direction = NORTH;
			turn(90, Vec2(0, m_sprSize.width));
			break;
		case EAST:
			m_direction = NORTH;
			turn(-90, Vec2(0, m_sprSize.width));
			break;
		}
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		switch (m_direction)
		{
		case SOUTH:
			m_direction = WEST;
			turn(90, Vec2(-m_sprSize.width, 0));
			break;
		case NORTH:
			m_direction = WEST;
			turn(-90, Vec2(-m_sprSize.width, 0));
			break;
		}
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		switch (m_direction)
		{
		case SOUTH:
			m_direction = EAST;
			turn(-90, Vec2(m_sprSize.width, 0));
			break;
		case NORTH:
			m_direction = EAST;
			turn(90, Vec2(m_sprSize.width, 0));
			break;
		}
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		//crash open the locker
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		//test code
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

void Finger::turn(const float angleDelta, const Vec2& moveDelta)
{
	runAction(Spawn::create(
		RotateBy::create(ACTION_TIME, angleDelta),
		MoveBy::create(ACTION_TIME, moveDelta),
		nullptr));
}

Rect Finger::GetBoundingBox()
{
	Vec2 curPos = getPosition();
	Rect sprBox = m_sprite->getBoundingBox();
	curPos.x -= sprBox.size.width / 2;
	sprBox.origin = curPos;
	return sprBox;
}

