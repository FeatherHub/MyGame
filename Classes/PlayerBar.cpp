#include "stdafx.h"
#include "Bar.h"

bool Bar::init()
{

	if (Node::init() == false)
		return false;

	m_max = 100;
	m_point = 100;
	m_capacity = Sprite::create("player_bar_capacity.png");
	m_current = Sprite::create("player_bar_current.png");
	m_icon = Sprite::create("player_bar_icon.png");
	
	m_capacity->setAnchorPoint(Vec2(0.f, 0.f));
	m_current->setAnchorPoint(Vec2(0.f, 0.f));
	m_icon->setAnchorPoint(Vec2(0.f, 0.f));

	m_icon->setPosition(Vec2(-50, 0));

	addChild(m_capacity);
	addChild(m_current);
	addChild(m_icon);

	return true;
}

void Bar::SetEffect(int point)
{
	m_point += point;
	m_current->setScaleX(m_point);
}