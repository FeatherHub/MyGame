#pragma once;

class Finger;

class SnakeScene : public Layer
{
public:
    static Scene* createScene();
 
	virtual bool init();
    
    CREATE_FUNC(SnakeScene);

private:
	void update(float delta);
	TMXTiledMap* m_map;
	TMXLayer* m_layer;
	Finger* m_finger;
};

