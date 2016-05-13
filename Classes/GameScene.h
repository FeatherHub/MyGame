#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

class GameManager;

class GameScene : public Layer
{
public:
    static Scene* createScene();

	CREATE_FUNC(GameScene);

	virtual bool init();

	void update(float dt);

private:
	GameManager* m_gameManager;
};

#endif
