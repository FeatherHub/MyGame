#include "stdafx.h"
#include "Babe.h"

Babe::Babe() : m_state(IDOL)
{

}

bool Babe::init()
{
	if (Node::init() == false)
		return false;

	m_sprite = Sprite::create("babe.png");
	addChild(m_sprite);

	scheduleUpdate();

	return true;
}

void Babe::update(float delta)
{
	switch (m_state)
	{
	case CONTROLED:
		break;
	case IDOL:
		break;
	case WALKAROUND:
		m_state = RUNNING;
		runAction(Sequence::create(
			MoveTo::create(2.5f, BABE_INIT_POS),
			CallFunc::create([&](){m_state = GOTOBED; }),
			nullptr));
		break;
	case GOTOBED:
		break;
	}
}
