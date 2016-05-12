#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

class Player;
class GameManager;

class GameScene : public Layer
{
public:
    static cocos2d::Scene* createScene();

	CREATE_FUNC(GameScene);

	virtual bool init();

	void update(float dt);

private:
	GameManager* m_gameManager;
};

#endif
