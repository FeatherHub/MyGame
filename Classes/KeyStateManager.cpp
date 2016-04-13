#include "stdafx.h"
#include "KeyStateManager.h"

KeyStateManager::KeyStateManager() : m_currentkeyCode(EventKeyboard::KeyCode::KEY_NONE)
{
	for (KeyPressed& key : m_keyState)
	{
		key = false;
	}
}

KeyStateManager::~KeyStateManager()
{

}

bool KeyStateManager::init()
{
	if (!Node::init())
	{
		return false;
	}

	EventListenerKeyboard* keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_1(KeyStateManager::OnKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_1(KeyStateManager::OnKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	return true;
}

void KeyStateManager::OnKeyPressed(EventKeyboard::KeyCode keyCode)
{
	m_currentkeyCode = keyCode;
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW :
		m_keyState[LEFT] = true;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_keyState[RIGHT] = true;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		m_keyState[UP] = true;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		m_keyState[DOWN] = true;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		m_keyState[SPACE] = true;
		break;
	}
}

void KeyStateManager::OnKeyReleased(EventKeyboard::KeyCode keyCode)
{
	m_currentkeyCode = EventKeyboard::KeyCode::KEY_NONE;
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_keyState[LEFT] = false;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_keyState[RIGHT] = false;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		m_keyState[UP] = false;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		m_keyState[DOWN] = false;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		m_keyState[SPACE] = false;
		break;
	}
}
