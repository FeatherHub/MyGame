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
	EventKeyboard::KeyCode m_currentKeyCode;
	CocosDenshion::SimpleAudioEngine* m_audioPlayer;
	bool m_isCollided;
	Sprite* m_sprite;
	float m_speed;
	DIRECTION m_direction;
};