#pragma once

#include "KeyConfig.h"

class InputManager : public Node
{
public:
	CREATE_FUNC(InputManager);
	InputManager();
	~InputManager();
	virtual bool init() override;
	KeyPressed* GetKeyState() { return m_keyState; }
	EventKeyboard::KeyCode GetCurrentKeyCode() { return m_currentkeyCode; }

private:
	void OnKeyPressed(EventKeyboard::KeyCode keyCode);
	void OnKeyReleased(EventKeyboard::KeyCode keyCode);
	KeyPressed m_keyState[KEYCODE_NUMBER];
	EventKeyboard::KeyCode m_currentkeyCode;
};