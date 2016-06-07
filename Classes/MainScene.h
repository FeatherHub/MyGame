#pragma once

class InputManager;

class MainScene : public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainScene);

private:
	enum CURSOR_STATE : short
	{
		START,
		LOAD,
		EXIT
	};

	enum MAIN_STATE : short
	{
		NORMAL = 1,
		SAD_END,
		HAPPY_END
	};

	void update(float delta);
	InputManager* m_inputManager;
	Sprite* m_cursor;
	CURSOR_STATE m_cursorState;
	Vec2 m_cursorPos[3];
	bool* m_keyState;
};
