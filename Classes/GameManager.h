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

	//GameManager�� ������ �����ϰ� �Ʒ� �Լ��� ȣ�����־�� �մϴ�
	void AddToLayer(Layer* layer) const;

	//���� update �κп��� �Ʒ� �Լ��� ȣ�����־�� �մϴ�.
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