#include "stdafx.h"
#include "Player.h"

/*
Set m_keyState before calling StartUpdate();
Set m_isRequesting at the end of the game logic 
*/

//�̵����
/*
Ÿ�ϸ����� �Ѵٸ�

Ű �Է� �ν� -> **�̵� �㰡** ->
Ÿ�ϸ� �����¸�ŭ �̵� + �̵� �ִϸ��̼� ��� 
-> ���� ������ �̵� �㰡x -> ������ �̵� �㰡

*/


Player::Player() : m_direction(SOUTH), m_keyState(nullptr), m_sprite(nullptr), m_speed(DEFAULT_SPEED),
m_isCollided(false), m_isRequesting(false), m_currentKeyCode(EventKeyboard::KeyCode::KEY_NONE)
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
	if (!m_isCollided)
		return;

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
		m_isRequesting = true;
		/*
			���ͷ��� ��û -> �Ŵ����� �ν�
			���⿡ ������Ʈ 
				������
					�÷��� ���ְ� �Ŵ����� ������Ʈ�� ���ͷ����� ��������
				������ 
					�÷��� ����
		*/
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
