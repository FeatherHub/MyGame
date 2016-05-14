#include "stdafx.h"
#include "Finger.h"
#include "GameScene.h"

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
	while (m_keyList.empty() == false)
	{
		auto curKey = m_keyList.front();
		m_keyList.pop_front();

		switch (curKey)
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
			break;
		case EventKeyboard::KeyCode::KEY_ESCAPE:
			Director::getInstance()->replaceScene(GameScene::createScene());
			break;
		}


		//가가가각 -> HP 0 Game Over Again
		//가각 -> Turn!

		/*
			if (m_keyState[UP])
			setPosition(getPosition() + Vec2(0, +m_speed));
			if (m_keyState[DOWN])
			setPosition(getPosition() + Vec2(0, -m_speed));
			if (m_keyState[LEFT])
			setPosition(getPosition() + Vec2(-m_speed, 0));
			if (m_keyState[RIGHT])
			setPosition(getPosition() + Vec2(m_speed, 0));

			return;
			*/
	}
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
	setPosition(getPosition() + moveDelta);
	setRotation(getRotation() + angleDelta); 
}

Rect Finger::GetBoundingBox()
{
	Rect sprBox = m_sprite->getBoundingBox();
	Vec2 nodePos = getPosition();
	auto sz = sprBox.size;
	auto or = sprBox.origin;

	switch (m_direction)
	{
	case SOUTH:
		nodePos.x -= sz.width / 2;
		break;
	case NORTH:
		nodePos.x -= sz.width / 2;
		nodePos.y -= sz.height;
		break;
	case WEST:
		nodePos.y -= sz.width / 2;
		break;
	case EAST:
		nodePos.x -= sz.height;
		nodePos.y -= sz.width / 2;
		break;
	}

	switch (m_direction)
	{
	case WEST:
	case EAST:
		sprBox.size.setSize(sz.height, sz.width);
	}

	sprBox.origin = nodePos;

/*
	auto bot_left = sprBox.origin;
	auto sz2 = sprBox.size;

	auto parent = getParent();

	enum {
	TOPLEFT,
	TOPRIGHT,
	BOTLEFT,
	BOTRIGHT
	};

	Sprite* rect[4] 
	{	Sprite::create("dot.png"),
		Sprite::create("dot.png"),
		Sprite::create("dot.png"),
		Sprite::create("dot.png")};
	
	rect[TOPLEFT] ->setPosition(Vec2(bot_left.x, bot_left.y + sz2.height));
	rect[TOPRIGHT]->setPosition(Vec2(bot_left.x + sz2.width, bot_left.y + sz2.height));
	rect[BOTLEFT] ->setPosition(Vec2(bot_left.x, bot_left.y));
	rect[BOTRIGHT]->setPosition(Vec2(bot_left.x + sz2.width, bot_left.y));

	for (auto& dot : rect)
	{
		parent->addChild(dot);
	}
*/

	return sprBox;
}

