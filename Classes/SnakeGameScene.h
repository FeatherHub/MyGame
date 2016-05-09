#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "Bar.h"
#include "PlayerConfig.h"
class InputManager;
class MapLoader;

class SnakeGameScene : public Layer
{
public:
    static Scene* createScene();
 
	virtual bool init();
    
    CREATE_FUNC(SnakeGameScene);

	void SetPointHandle(float point) { m_bar->SetPoint(point); }
private:
	void update(float delta);
	bool m_keyState[4];
	InputManager* m_inputManager;
	MapLoader* m_mapLoader;
	Bar* m_bar;
	EventKeyboard::KeyCode m_currentKeyCode;
	Sprite* m_finger;
	DIRECTION m_dir;
};

#endif // __GAME_SCENE_H__
