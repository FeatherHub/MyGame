#include "stdafx.h"
#include "Player.h"

/*
Set m_keyState before calling StartUpdate();
Set m_isRequesting at the end of the game logic 
*/

//이동방식
/*
타일맵으로 한다면

키 입력 인식 -> **이동 허가** ->
타일맵 오프셋만큼 이동 + 이동 애니메이션 재생 
-> 끝날 때까지 이동 허가x -> 끝나면 이동 허가

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
			인터랙션 요청 -> 매니저가 인식
			방향에 오브젝트 
				있으면
					플래그 꺼주고 매니저가 오브젝트와 인터랙션을 맵핑해줌
				없으면 
					플래그 꺼줌
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
