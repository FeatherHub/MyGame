#pragma once

#include "BabeConfig.h"

class Babe : public Node
{
public:
	Babe();
	bool init() override;
	CREATE_FUNC(Babe);
	void SetState(BabeState state) { m_state = state; }
	
	const Vec2 BABE_INIT_POS{ 200, 170 };

private:
	void update(float delta);
	Sprite* m_sprite;
	BabeState m_state;
};