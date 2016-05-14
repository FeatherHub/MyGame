#include "stdafx.h"
#include "PlayableObject.h"

PlayableObject::PlayableObject() : 
m_pressedKey(EventKeyboard::KeyCode::KEY_NONE),
m_releasedKey(EventKeyboard::KeyCode::KEY_NONE),
m_direction(WEST), 
m_speed(DEFAULT_SPEED),
m_sprite(nullptr),
m_isCollided(false)
{
	m_audioPlayer = CocosDenshion::SimpleAudioEngine::getInstance();
	for (bool& keyState : m_keyState)
	{
		keyState = false;
	}
}

bool PlayableObject::init()
{
	if (Node::init() == false)
		return false;

	m_keyboardListener = EventListenerKeyboard::create();
	m_keyboardListener->onKeyPressed = CC_CALLBACK_1(PlayableObject::OnKeyPressed, this);
	m_keyboardListener->onKeyReleased = CC_CALLBACK_1(PlayableObject::OnKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_keyboardListener, this);
	return true;
}

void PlayableObject::OnKeyPressed(EventKeyboard::KeyCode keyCode)
{
//	log("Key with keycode %d pressed", keyCode);
	m_pressedKey = keyCode;
	m_keyList.push_back(keyCode);

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
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
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		m_keyState[EXIT] = true;
		break;
	}
}

void PlayableObject::OnKeyReleased(EventKeyboard::KeyCode keyCode)
{
//	log("Key with keycode %d Released", keyCode);
	m_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	m_releasedKey = EventKeyboard::KeyCode::KEY_NONE;
	m_keyList.remove(keyCode);
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_keyState[LEFT] = false;
		m_releasedKey = EventKeyboard::KeyCode::KEY_LEFT_ARROW;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_keyState[RIGHT] = false;
		m_releasedKey = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		m_keyState[UP] = false;
		m_releasedKey = EventKeyboard::KeyCode::KEY_UP_ARROW;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		m_keyState[DOWN] = false;
		m_releasedKey = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		m_keyState[SPACE] = false;
		m_releasedKey = EventKeyboard::KeyCode::KEY_SPACE;
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		m_keyState[EXIT] = false;
		m_releasedKey = EventKeyboard::KeyCode::KEY_ESCAPE;
		break;
	}
}

void PlayableObject::ResetKeyState()
{
	m_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	m_releasedKey = EventKeyboard::KeyCode::KEY_NONE;
	for (int i = 0; i < KEYCODE_NUMBER; i++)
	{
		m_keyState[i] = false;
	}
}

Rect PlayableObject::GetBoundingBox()
{
	Vec2 nodePos = getPosition();
	Rect sprBox = m_sprite->getBoundingBox();
	nodePos.x -= sprBox.size.width / 2;
	nodePos.y -= sprBox.size.height / 2;
	sprBox.origin = nodePos;
	return sprBox;
}