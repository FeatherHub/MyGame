#pragma once

#include "GameManagerConfig.h"
#include "GameObjectConfig.h"

class Player;
class Babe;
class GameObject;
class Bar;

class GameManager
{
public:
	GameManager();
	~GameManager();

	void AddToLayer(Layer* layer) const;

	void Play();

private:
	void Init();
	void MakeInteraction();
	
	OBJECT_TYPE CheckCollisionWithObject() const;
	bool IsAvailable() const;

	Sprite* m_inBabeBg;
	TMXTiledMap* m_map;
	Vector<GameObject*> m_gameObjects;
	Player* m_player;
	Bar* m_playerBar;
	Bar* m_missionBar;
	Babe* m_babe;
	MODE m_mode;
	Layer* m_runningScene;
};