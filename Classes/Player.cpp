#include "stdafx.h"
#include "Player.h"
#include "SimpleAudioEngine.h"
#include "Bar.h"

Player::Player() : m_direction(WEST), m_sprite(nullptr), m_speed(DEFAULT_SPEED),
m_isRequesting(false), m_state(OUT_BABE)
{
	m_guage[ENTER_BABE] = 0;
	m_guage[EXIT_BABE] = 0;
}

bool Player::init()
{
	if (Node::init() == false)
		return false;

	m_sprite = Sprite::create("player.png");
	m_sprite->setScale(0.3f);
	addChild(m_sprite);

	return true;
}

void Player::update(float dt)
{
	if (m_guage[ENTER_BABE] > 3.0f)
	{
		m_guage[ENTER_BABE] = 0;
 		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("enter_babe.wav");

		m_bar->SetEffect(-0.4f);
   		m_state = ENTER_BABE;
	}

	if (m_guage[EXIT_BABE] > 3.0f)
	{
		m_guage[EXIT_BABE] = 0;
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("exit_babe.wav");
		m_state = EXIT_BABE;
		ExitEvent();
	}

	if (m_state == IN_BABE &&
		m_keyState[UP] && m_keyState[SPACE])
	{
		m_guage[EXIT_BABE] += dt;
		return;
	}
	else
	{
		m_guage[EXIT_BABE] = 0;
	}

	if (m_state == OUT_BABE && 
		m_keyState[DOWN] && m_keyState[SPACE])
	{
		m_guage[ENTER_BABE] += dt;
     	return;
	}
	else
	{
		m_guage[ENTER_BABE] = 0;
	}

	if (m_currentKeyCode == EventKeyboard::KeyCode::KEY_SPACE)
		m_isRequesting = true;

	switch (m_state)
	{
	case IN_BABE:
		if (m_keyState[UP])
			setPosition(getPosition() + Vec2(0, +m_speed));

		if (m_keyState[DOWN])
			setPosition(getPosition() + Vec2(0, -m_speed));

		if (m_keyState[RIGHT])
		{
			setPosition(getPosition() + Vec2(m_speed, 0));
			m_direction = WEST;
		}

		if (m_keyState[LEFT])
		{
			setPosition(getPosition() + Vec2(-m_speed, 0));
			m_direction = EAST;
		}
		break;
	case OUT_BABE:
		if (m_keyState[UP])
			setPosition(getPosition() + Vec2(0, +m_speed));

		if (m_keyState[DOWN])
			setPosition(getPosition() + Vec2(0, -m_speed));

		if (m_keyState[RIGHT])
		{
			setPosition(getPosition() + Vec2(m_speed, 0));
			m_direction = WEST;
		}

		if (m_keyState[LEFT])
		{
			setPosition(getPosition() + Vec2(-m_speed, 0));
			m_direction = EAST;
		}
		break;
	}
}

Rect Player::GetBoundingBox()
{
	Vec2 curPos = getPosition();
	Rect sprBox = m_sprite->getBoundingBox();
	curPos.x -= sprBox.size.width / 2;
	curPos.y -= sprBox.size.height / 2;
	sprBox.origin = curPos;
	return sprBox;
}

void Player::EnterEvent(Vec2 babePos)
{
	runAction(Sequence::create(
		EaseIn::create(
		MoveTo::create(1.0f, babePos), 0.5f),
		CallFunc::create([&](){ m_state = IN_BABE; }),
		nullptr
		));
}

void Player::ExitEvent()
{
	runAction(Sequence::create(
		CallFunc::create([&](){ m_state = OUT_BABE; }),
		EaseElasticOut::create(
		MoveTo::create(1.0f, Vec2(100, 100)), 1.0f),
		nullptr
		));
}
