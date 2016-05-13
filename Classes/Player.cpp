#include "stdafx.h"
#include "Player.h"
#include "Bar.h"

Player::Player() : 
m_state(OUT_BABE),
m_isRequesting(false),
m_stopControl(false)
{
	m_guage[ENTER_BABE] = 0;
	m_guage[EXIT_BABE] = 0;
}

bool Player::init()
{
	if (PlayableObject::init() == false)
		return false;

	m_sprite = Sprite::create("player.png");
	m_sprite->setScale(0.3f);
	addChild(m_sprite);

	scheduleUpdate();

	return true;
}

void Player::update(float dt)
{
	if (m_guage[ENTER_BABE] > 3.0f)
	{
		m_guage[ENTER_BABE] = 0.f;
   		m_state = ENTER_BABE;
	}

	if (m_guage[EXIT_BABE] > 3.0f)
	{
		m_guage[EXIT_BABE] = 0.f;
		m_state = EXIT_BABE;
		ExitEvent();
	}

	if (m_stopControl)
		return;

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

	if (m_pressedKey == EventKeyboard::KeyCode::KEY_SPACE)
	{
		m_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
		m_isRequesting = true;
	}
	else
		m_isRequesting = false;

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
}

void Player::EnterEvent(Vec2 babePos)
{
	m_audioPlayer->playEffect("enter_babe.wav");
	m_bar->SetEffect(-0.1f);
	m_stopControl = true;
	m_state = WAIT;

	runAction(Sequence::create(
		MoveTo::create(1.0f, babePos),
		CallFunc::create([&](){ m_state = IN_BABE; ResetKeyState(); m_stopControl = false; }),
		nullptr
		));
}

void Player::ExitEvent()
{
	m_audioPlayer->playEffect("exit_babe.wav");
	m_stopControl = true;
	m_state = OUT_BABE;

	runAction(Sequence::create(
		MoveTo::create(1.0f, Vec2(100.f, 100.f)),
		CallFunc::create([&](){ ResetKeyState(); m_stopControl = false; }),
		nullptr
		));
}