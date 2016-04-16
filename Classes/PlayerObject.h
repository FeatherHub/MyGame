#pragma once

class PlayerObject : public Node
{
public:
	PlayerObject();
	~PlayerObject();
	virtual bool init() override;
	void InitKeyState(bool* keyState) { m_keyState = keyState; }
	void SetCurrentKey(EventKeyboard::KeyCode keyCode) { m_currentKeyCode = keyCode; }
	void StartUpdate() { scheduleUpdate(); }
	void StopUpdate() { unscheduleUpdate(); }

protected:
	bool* m_keyState = nullptr;
	EventKeyboard::KeyCode m_currentKeyCode = EventKeyboard::KeyCode::KEY_NONE;
};