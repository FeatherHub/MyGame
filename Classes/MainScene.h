#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

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

	void update(float delta);
	InputManager* m_inputManager;
	Sprite* m_cursor;
	bool* m_keyState;
	CURSOR_STATE m_cursorState;
	Vec2 m_cursorPos[3];
};

#endif
