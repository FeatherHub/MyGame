#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

class Player;
class KeyStateManager;

class TestScene : public Layer
{
public:
    static cocos2d::Scene* createScene();

	CREATE_FUNC(TestScene);

	virtual bool init();

	void update(float dt);

private:
	////GameManager에 들어갈 내용
	Player* m_player;
	KeyStateManager* m_keyStateManager;
};

#endif
