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
	void InitKeyState(bool* keyState) { m_keyState = keyState; }
	void SetCurrentKey(EventKeyboard::KeyCode keyCode) { m_currentKeyCode = keyCode; }
	void SetCollided(bool isCollided) { m_isCollided = isCollided; }
	void StartUpdate();
	void StopUpdate();
	DIRECTION GetDirection() { return m_direction; };

private:
	void update(float dt);
	DIRECTION m_direction = SOUTH;
	bool* m_keyState = nullptr;
	EventKeyboard::KeyCode m_currentKeyCode = EventKeyboard::KeyCode::KEY_NONE;
	Sprite* m_sprite = nullptr;
	float m_speed = DEFAULT_SPEED;
	bool m_isCollided = false;
	bool m_isRequesting = false;
};