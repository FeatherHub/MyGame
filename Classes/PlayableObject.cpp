#include "stdafx.h"
#include "PlayableObject.h"

PlayableObject::PlayableObject() : m_keyState(nullptr), m_currentKeyCode(EventKeyboard::KeyCode::KEY_NONE)
{
}

PlayableObject::~PlayableObject()
{
}

bool PlayableObject::init()
{
	if (!Node::init())
		return false;

	return true;
}
