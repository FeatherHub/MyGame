#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager() : m_currentkeyCode(EventKeyboard::KeyCode::KEY_NONE)
{
	for (bool& key : m_keyState)
	{
		key = false;
	}
}

bool InputManager::init()
{
	if (!Node::init())
	{
		return false;
	}

	EventListenerKeyboard* keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_1(InputManager::OnKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_1(InputManager::OnKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	return true;
}

void InputManager::OnKeyPressed(EventKeyboard::KeyCode keyCode)
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

void InputManager::OnKeyReleased(EventKeyboard::KeyCode keyCode)
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
