#include "stdafx.h"
#include "SnakeGameScene.h"
#include "InputManager.h"
#include "MapLoader.h"

Scene* SnakeGameScene::createScene()
{
    auto scene = Scene::create();

	auto layer = SnakeGameScene::create();

    scene->addChild(layer);

    return scene;
}

bool SnakeGameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	m_bar = Bar::create();
	m_bar->SetSprite("player_bar_current.png", "player_bar_capacity.png", "player_bar_icon.png");
	m_bar->setPosition(Vec2(200, 30));

	m_inputManager = InputManager::create();
	addChild(m_inputManager);

	m_finger = Sprite::create("finger.png");
	addChild(m_finger);

	m_dir = NORTH;

	scheduleUpdate();

    return true;
}

void SnakeGameScene::update(float delta)
{
		
	
	
	m_currentKeyCode = m_inputManager->GetCurrentKeyCode();

	switch (m_currentKeyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_finger->setRotation(-90);
		m_finger->setPosition(m_finger->getPosition() + Vec2(-SNAKE_SPEED, 0));
		m_keyState[LEFT] = true;
		m_keyState[RIGHT] = m_keyState[UP] = m_keyState[DOWN] = false;
		return;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_finger->setRotation(90);
		m_finger->setPosition(m_finger->getPosition() + Vec2(+SNAKE_SPEED, 0));
		m_keyState[RIGHT] = true;
		m_keyState[LEFT] = m_keyState[UP] = m_keyState[DOWN] = false;
		return;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		m_finger->setRotation(0);
		m_finger->setPosition(m_finger->getPosition() + Vec2(0, +SNAKE_SPEED));
		m_keyState[UP] = true;
		m_keyState[RIGHT] = m_keyState[LEFT] = m_keyState[DOWN] = false;
		return;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		m_finger->setRotation(180);
		m_finger->setPosition(m_finger->getPosition() + Vec2(0, -SNAKE_SPEED));
		m_keyState[DOWN] = true;
		m_keyState[RIGHT] = m_keyState[UP] = m_keyState[LEFT] = false;
		return;
	}

	if (m_keyState[UP])
		m_finger->setPosition(m_finger->getPosition() + Vec2(0, +SNAKE_SPEED));
	if (m_keyState[DOWN])
		m_finger->setPosition(m_finger->getPosition() + Vec2(0, -SNAKE_SPEED));
	if (m_keyState[LEFT])
		m_finger->setPosition(m_finger->getPosition() + Vec2(-SNAKE_SPEED, 0));
	if (m_keyState[RIGHT])
		m_finger->setPosition(m_finger->getPosition() + Vec2(+SNAKE_SPEED, 0));
}

