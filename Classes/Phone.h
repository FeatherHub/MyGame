#pragma once

class TextWriter;

class Phone : public GameObject
{
public:
	static Phone* create(Node* parent);
	bool init(Node* parent);
	void Play(Player* player, Babe* babe) override;

private:
	void OnKeyPressed(EventKeyboard::KeyCode keyCode);
	void ProcessOK();
	void ChangeInitToMessage();
	void ChangeMessageToRead();
	void ChangeMessageToInit();
	void ChangeReadToMessage();
	void ChangeReadToSelect();
	void ChangeSelectToRead();
	void ClosePhone();
	void RemoveTextAndIcon();
	void CheckScriptOver(float delta);

	enum UI
	{
		BODY, CLOSE, OK,
		SEND, BACK, UI_SELECTED,
		RECEIVE, TV_AD_HEAD, TV_AD_FULL,
		BLACK, DET_SELECTED,
		UI_NUM
	};

	enum MONITOR_STATE
	{
		INIT,
		MESSAGE,
		READ,
		SELECT,
		NONE
	};

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

	EventListenerKeyboard* m_keyboardListener;
	MONITOR_STATE m_monitor = INIT;
	Sprite* m_uis[UI_NUM];
	UI m_cursor = BODY;
	Node* m_parent;
};