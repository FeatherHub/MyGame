#pragma once

#include "PlayableObject.h"

class Bar;

class Player : public PlayableObject
{
public:
	CREATE_FUNC(Player);
	Player();
	~Player() = default;
	virtual bool init() override;
	void TurnOffRequesting() { m_isRequesting = false; }
	bool IsRequesting() { return m_isRequesting; }
	STATE GetState() { return m_state; }
	void EnterEvent(Vec2 babePos);
	void ExitEvent();
	void SetBar(Bar* bar) { m_bar = bar; }
private:
	void update(float dt);
	bool m_isRequesting;
	STATE m_state;
	float m_guage[2];
	Bar* m_bar;
};