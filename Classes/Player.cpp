#include "stdafx.h"
#include "Player.h"


//�̵����
/*
Ÿ�ϸ����� �Ѵٸ�

Ű �Է� �ν� -> **�̵� �㰡** ->
Ÿ�ϸ� �����¸�ŭ �̵� + �̵� �ִϸ��̼� ��� 
-> ���� ������ �̵� �㰡x -> ������ �̵� �㰡

*/

Player::Player() : m_direction(SOUTH), m_sprite(nullptr), m_speed(DEFAULT_SPEED),
m_isRequesting(false)
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

	return true;
}

void Player::update(float dt)
{
	if (m_currentKeyCode == EventKeyboard::KeyCode::KEY_SPACE)
		m_isRequesting = true;

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
			return;

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
		/*
			default:
			{
			switch (m_direction)
			{
			case NORTH:
			setPosition(getPosition() + Vec2(0, m_speed));
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
			return;
			*/
	}

	if (m_keyState[UP])
	{
		setPosition(getPosition() + Vec2(0, +m_speed));
		return;
	}
	if (m_keyState[DOWN])
	{
		setPosition(getPosition() + Vec2(0, -m_speed));
		return;
	}
	if (m_keyState[RIGHT])
	{
		setPosition(getPosition() + Vec2(m_speed, 0));
		return;
	}
	if (m_keyState[LEFT])
	{
		setPosition(getPosition() + Vec2(-m_speed, 0));
		return;
	}
}