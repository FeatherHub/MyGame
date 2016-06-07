#include "stdafx.h"
#include "GameObject.h"

bool GameObject::init()
{
	if (Node::init() == false)
	{
		return false;
	}

	m_available = true;

	return true;
}

Rect GameObject::GetBoundingBox()
{
	Vec2 curPos = getPosition();
	Rect sprBox = m_sprite->getBoundingBox();
	auto anchorPoint = m_sprite->getAnchorPoint();
	curPos.x -= sprBox.size.width * anchorPoint.x;
	curPos.y -= sprBox.size.height * anchorPoint.y;
	sprBox.origin = curPos;
	return sprBox;
}
