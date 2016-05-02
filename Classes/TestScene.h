#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

class Player;
class InputManager;
class GameManager;

class TestScene : public Layer
{
public:
    static cocos2d::Scene* createScene();

	CREATE_FUNC(TestScene);

	virtual bool init();

	void update(float dt);

private:
	GameManager* m_gameManager;
	InputManager* m_inputManager;
};

#endif
