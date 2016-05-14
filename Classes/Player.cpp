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
	
	for (int i = 0; i < 4; i++)
		m_directionAvailable[i] = true;
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

	auto curPos = getPosition();
	log("%f %f", curPos.x, curPos.y);

	auto size = m_layer->getLayerSize();

	for (int x = 0; x < size.width; x++)
	{
		for (int y = 0; y < size.height; y++)
		{
			auto tile = m_layer->tileAt(Vec2(x, y));
			if (tile)
			{
				auto tileBox = tile->getBoundingBox();
			
				if (tileBox.containsPoint(curPos + Vec2(DEFAULT_SPEED, 0)))
					m_directionAvailable[EAST] = false;
				if (tileBox.containsPoint(curPos + Vec2(-DEFAULT_SPEED, 0)))
					m_directionAvailable[WEST] = false;
				if (tileBox.containsPoint(curPos + Vec2(0, DEFAULT_SPEED)))
					m_directionAvailable[NORTH] = false;
				if (tileBox.containsPoint(curPos + Vec2(0, -DEFAULT_SPEED)))
					m_directionAvailable[SOUTH] = false;
			}
		}
	}

	if (m_keyState[UP] && m_directionAvailable[NORTH])
	{
		setPosition(getPosition() + Vec2(0, +m_speed));
	}
	if (m_keyState[DOWN] && m_directionAvailable[SOUTH])
	{
		setPosition(getPosition() + Vec2(0, -m_speed));
	}
	if (m_keyState[RIGHT] && m_directionAvailable[EAST])
	{
		setPosition(getPosition() + Vec2(m_speed, 0));
	}
	if (m_keyState[LEFT] && m_directionAvailable[WEST])
	{
		setPosition(getPosition() + Vec2(-m_speed, 0));
	}

	for (int i = 0; i < 4; i++)
		m_directionAvailable[i] = true;
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