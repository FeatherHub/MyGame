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
	m_sprite->setScale(0.3f);
	addChild(m_sprite);

	return true;
}