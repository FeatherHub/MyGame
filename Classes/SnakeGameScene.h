#pragma once;

class SnakeGameScene : public Layer
{
public:
    static Scene* createScene();
 
	virtual bool init();
    
    CREATE_FUNC(SnakeGameScene);

private:
	void update(float delta);

};

