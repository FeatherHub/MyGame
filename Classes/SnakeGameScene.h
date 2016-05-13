#pragma once;

class Finger;

class SnakeGameScene : public Layer
{
public:
    static Scene* createScene();
 
	virtual bool init();
    
    CREATE_FUNC(SnakeGameScene);

private:
	void update(float delta);
	TMXTiledMap* m_map;
	TMXLayer* m_layer;
	Finger* m_finger;
};

