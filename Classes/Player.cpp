#include "stdafx.h"
#include "Player.h"

/*

Should set m_keyState Before Call StartUpdate();

*/

Player::Player() : m_direction(SOUTH), m_keyState(nullptr), m_sprite(nullptr), m_speed(DEFAULT_SPEED),
m_currentKeyCode(EventKeyboard::KeyCode::KEY_NONE)
{
}

Player::~Player()
{
}

bool Player::init()
{
	if (!Node::init())
	{
		return false;
	}

	m_sprite = Sprite::create("player.png");
	addChild(m_sprite);

	setPosition(0, 500);

	return true;
}

void Player::update(float dt)
{
	switch (m_currentKeyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		if (m_keyState[RIGHT])
			return;

		setPosition(getPosition() + Vec2(-m_speed, 0));
		m_direction = WEST;
		return;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		if (m_keyState[LEFT])
			return;;

		setPosition(getPosition() + Vec2(m_speed, 0));
		m_direction = EAST;
		return;
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		if (m_keyState[DOWN])
			return;

		setPosition(getPosition() + Vec2(0, m_speed));
		m_direction = NORTH;
		return;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		if (m_keyState[UP])
			return;

		setPosition(getPosition() + Vec2(0, -m_speed));
		m_direction = SOUTH;
		return;
	case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
		//인터랙션 요청 -> 매니저가 방향에 오브젝트 있으면 인터랙션 연결해줌 
		//										없으면 플래그 꺼주고 없다는 알림
		return;
	}

	if (m_keyState[UP])
		setPosition(getPosition() + Vec2(0, +m_speed));
	if (m_keyState[DOWN])
		setPosition(getPosition() + Vec2(0, -m_speed));
	if (m_keyState[RIGHT])
		setPosition(getPosition() + Vec2(m_speed, 0));
	if (m_keyState[LEFT])
		setPosition(getPosition() + Vec2(-m_speed, 0));
}

void Player::StartUpdate()
{
	scheduleUpdate();
}

void Player::StopUpdate()
{
	unscheduleUpdate();
}
