#pragma once

#include "SimpleAudioEngine.h"
#include "PlayerConfig.h"
#include "KeyConfig.h"

class PlayableObject : public Node
{
public:
	PlayableObject();
	virtual ~PlayableObject() = default;
	virtual bool init() override;
	void ResetKeyState();
	Rect GetBoundingBox();
	DIRECTION GetDirection() { return m_direction; };
	float GetSpeed() { return m_speed; }
protected:
	void OnKeyPressed(EventKeyboard::KeyCode keyCode);
	void OnKeyReleased(EventKeyboard::KeyCode keyCode);
	bool m_keyState[KEYCODE_NUMBER];
	EventKeyboard::KeyCode m_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	EventKeyboard::KeyCode m_releasedKey = EventKeyboard::KeyCode::KEY_NONE;
	EventListenerKeyboard* m_keyboardListener;
	CocosDenshion::SimpleAudioEngine* m_audioPlayer;
	bool m_isCollided = false;
	Sprite* m_sprite = nullptr;
	float m_speed = DEFAULT_SPEED;
	DIRECTION m_direction = WEST;
};