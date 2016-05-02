#pragma once

#include "BabeConfig.h"

class Babe : public Node
{
public:
	Babe();
	~Babe() = default;
	bool init() override;
	CREATE_FUNC(Babe);
	void SetState(BabeState state) { m_state = state; }

private:
	Sprite* m_sprite;
	BabeState m_state;
};