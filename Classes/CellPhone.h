#pragma once

#include "GameObject.h"

class Player;
class Babe;

class CellPhone : public GameObject
{
public:
	CREATE_FUNC(CellPhone);
	bool init() override;
	void Play() override;
	void SetEffect(Player* player, Babe* babe) override;

private:
	void OnKeyPressed(EventKeyboard::KeyCode keyCode);
	enum {
		BODY,
		MONITOR,
		LEFT_BUTTON,
		RIGHT_BUTTON,
		UI_NUM
	};
	EventListenerKeyboard* m_keyboardListener;
	Sprite* m_black;
	Sprite* m_phoneUI[UI_NUM];
};