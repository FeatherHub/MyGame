#pragma once

#include "GameManagerConfig.h"
#include "GameObjectConfig.h"

class Player;
class Babe;
class GameObject;
class MapLoader;
class Bar;

class GameManager
{
public:
	GameManager();
	~GameManager();

	//GameManager를 씬에서 생성하고 아래 함수를 호출해주어야 합니다
	void AddToLayer(Layer* layer) const;

	//씬의 update 부분에서 아래 함수를 호출해주어야 합니다.
	void Play();

private:
	void Init();
	void MakeInteraction();
	
	OBJECT_TYPE CheckCollision() const;
	bool IsInteractionAvailable() const;

	MapLoader* m_mapLoader;
	Vector<GameObject*> m_gameObjects;
	Player* m_player;
	Bar* m_playerBar;
	Bar* m_missionBar;
	Babe* m_babe;
	MODE m_mode;
	Layer* m_runningScene;
};