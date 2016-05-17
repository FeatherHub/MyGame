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
	void update(float delta);
	void ClosePhone();

	enum UI
	{
		BODY, CLOSE, OK,
		SEND, BACK, SELECTED, 
		RECEIVE, TV_AD_HEAD, TV_AD_FULL,
		UI_NUM
	};

	enum MONITOR
	{
		INIT,
		MESSAGE,
		READ_MESSAGE
	};

	EventListenerKeyboard* m_keyboardListener;
	Sprite* m_black;
	Sprite* m_phoneUI[UI_NUM];
	MONITOR m_monitor = INIT;
	UI m_cursor = BODY;

	const Vec2 UI_LEFT {23, 115};
	const Vec2 UI_RIGHT {60, 115};
	const Vec2 UI_DELTA {1.6f, 0.6f};
	const Vec2 CONTENT_HEAD {18, 175};
	const Vec2 CONTENT_FULL {18, 130};
};