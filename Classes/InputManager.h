#pragma once

#include "KeyConfig.h"

class InputManager : public Node
{
public:
	CREATE_FUNC(InputManager);
	InputManager();
	~InputManager() = default;
	virtual bool init() override;
	bool* GetKeyState() { return m_keyState; }
	EventKeyboard::KeyCode GetCurrentKeyCode() { return m_currentkeyCode; }

private:
	void OnKeyPressed(EventKeyboard::KeyCode keyCode);
	void OnKeyReleased(EventKeyboard::KeyCode keyCode);
	bool m_keyState[KEYCODE_NUMBER];
	EventKeyboard::KeyCode m_currentkeyCode;
};