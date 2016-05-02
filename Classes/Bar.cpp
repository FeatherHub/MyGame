#include "stdafx.h"
#include "Bar.h"

bool Bar::init()
{
	if (Node::init() == false)
		return false;

	m_max = 1.f;
	m_point = 1.f;

	return true;
}

void Bar::SetSprite(string current, string capacity, string icon)
{
	m_current = Sprite::create(current);
	m_capacity = Sprite::create(capacity);
	m_icon = Sprite::create(icon);

	m_capacity->setAnchorPoint(Vec2(0.f, 0.f));
	m_current->setAnchorPoint(Vec2(0.f, 0.f));
	m_icon->setAnchorPoint(Vec2(0.f, 0.f));

	m_icon->setPosition(Vec2(-100, 0));

	addChild(m_capacity, 1);
	addChild(m_current, 2);
	addChild(m_icon, 1);
}

void Bar::SetEffect(float point)
{
	m_point += point;
	
	if (m_point <= 0)
		m_point = 0;
	if (m_point >= 1)
		m_point = 1;

	m_current->setScaleX(m_point);
}