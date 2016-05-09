#pragma once

#include "PlayableObject.h"
#include "PlayerConfig.h"
#include "KeyConfig.h"

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
	DIRECTION GetDirection() { return m_direction; };
	float GetSpeed() { return m_speed; }
	STATE GetState() { return m_state; }
	Rect GetBoundingBox();
	void EnterEvent(Vec2 babePos);
	void ExitEvent();
	void SetBar(Bar* bar) { m_bar = bar; }
private:
	void update(float dt);
	DIRECTION m_direction = SOUTH;
	Sprite* m_sprite = nullptr;
	float m_speed = DEFAULT_SPEED;
	bool m_isRequesting = false;
	bool m_isCollided = false;
	STATE m_state = OUT_BABE;
	float m_guage[2];
	Bar* m_bar;
};