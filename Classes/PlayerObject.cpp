#include "stdafx.h"
#include "PlayerObject.h"

PlayerObject::PlayerObject() : m_keyState(nullptr), m_currentKeyCode(EventKeyboard::KeyCode::KEY_NONE)
{

}

PlayerObject::~PlayerObject()
{
}

bool PlayerObject::init()
{
	if (!Node::init())
		return false;

	return true;
}
