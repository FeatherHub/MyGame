#pragma once;

class Finger;
class MapLoader;

class SnakeGameScene : public Layer
{
public:
    static Scene* createScene();
 
	virtual bool init();
    
    CREATE_FUNC(SnakeGameScene);

private:
	void update(float delta);
	MapLoader* m_mapLoader;
	Finger* m_finger;
};

