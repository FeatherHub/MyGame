#pragma once

#include "PlayerConfig.h"
#include "KeyConfig.h"

class Player : public Node
{
public:
	CREATE_FUNC(Player);
	Player();
	~Player();
	virtual bool init() override;
	DIRECTION GetDirection() { return m_direction; };
	void InitKeyState(KeyPressed* keyState) { m_keyState = keyState; }
	void SetCurrentKey(EventKeyboard::KeyCode keyCode) { m_currentKeyCode = keyCode; }
	void StartUpdate();
	void StopUpdate();

private:
	void update(float dt);

	DIRECTION m_direction = SOUTH;
	KeyPressed* m_keyState = nullptr;
	EventKeyboard::KeyCode m_currentKeyCode = EventKeyboard::KeyCode::KEY_NONE;
	Sprite* m_sprite = nullptr;
	float m_speed;
};