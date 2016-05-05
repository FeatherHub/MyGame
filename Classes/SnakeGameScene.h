#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

class InputManager;

class SnakeGameScene : public Layer
{
public:
    static Scene* createScene(int* guage_bar);

    virtual bool init();
    
    CREATE_FUNC(SnakeGameScene);
	
private:
	bool* m_keyState;
	InputManager* m_inputManager;
};

#endif // __GAME_SCENE_H__
