#include "stdafx.h"
#include "GameObject.h"

bool GameObject::init()
{
	if (Node::init() == false)
		return false;

	m_available = true;

	return true;
}

Rect GameObject::GetBoundingBox()
{
	Vec2 curPos = getPosition();
	Rect sprBox = m_sprite->getBoundingBox();
	curPos.x -= sprBox.size.width / 2;
	curPos.y -= sprBox.size.height / 2;
	sprBox.origin = curPos;
	return sprBox;
}
