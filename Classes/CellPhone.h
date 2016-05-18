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
	void RemoveTextAndIcon();
	void Select();
	enum UI
	{
		BODY, CLOSE, OK,
		SEND, BACK, UI_SELECTED,
		RECEIVE, TV_AD_HEAD, TV_AD_FULL,
		UI_NUM
	};

	enum MONITOR
	{
		INIT,
		MESSAGE,
		READ_MESSAGE,
		SELECT,
		NONE
	};

	EventListenerKeyboard* m_keyboardListener;
	Sprite* m_black;
	Sprite* m_phoneUI[UI_NUM];
	Sprite* m_detSeleceted;
	MONITOR m_monitor = INIT;
	UI m_cursor = BODY;

	TextWriter* m_tw1;
	TextWriter* m_tw2;
	TextWriter* m_tw3;
	TextWriter* m_tw4;
	TextWriter* m_yes;
	TextWriter* m_no;


	const Vec2 UI_LEFT {23, 115};
	const Vec2 UI_RIGHT {60, 115};
	const Vec2 UI_DELTA {1.6f, 0.6f};
	const Vec2 CONTENT_HEAD {18, 175};
	const Vec2 CONTENT_FULL {18, 130};
	const Vec2 NO_POS{285, -20};
	const Vec2 YES_POS{160, -20};
};