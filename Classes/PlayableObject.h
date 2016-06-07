#pragma once

#include "SimpleAudioEngine.h"
#include "PlayerConfig.h"
#include "KeyConfig.h"
#include <list>

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
	EventListenerKeyboard* m_keyboardListener;
	EventKeyboard::KeyCode m_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	EventKeyboard::KeyCode m_releasedKey = EventKeyboard::KeyCode::KEY_NONE;
	list<EventKeyboard::KeyCode> m_keyList;
	bool m_keyState[KEYCODE_NUMBER];
	CocosDenshion::SimpleAudioEngine* m_audioPlayer;
	Sprite* m_sprite = nullptr;
	DIRECTION m_direction = WEST;
	bool m_isCollided = false;
	float m_speed = DEFAULT_SPEED;
};