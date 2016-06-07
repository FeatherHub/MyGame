#pragma once

class GameManager;

class GameScene_01 : public Layer
{
public:
    static Scene* createScene();

	CREATE_FUNC(GameScene_01);

	virtual bool init();

	void update(float dt);

private:
	GameManager* m_gm;
};