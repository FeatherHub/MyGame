#pragma once

#include "GameManagerConfig.h"
#include "GameObjectConfig.h"

class Player;
class Babe;
class GameObject;
class MapLoader;

class GameManager
{
public:
	GameManager();
	~GameManager();

	//GameManager를 씬에서 생성하고 아래 함수를 호출해주어야 합니다
	void AddToLayer(Layer* layer) const;
	void InitKeyInput(bool* keyState) const;
	
	//씬의 update 부분에서 아래 함수를 호출해주어야 합니다.
	void Play();
	void SynchronizeKeyInput(EventKeyboard::KeyCode keyCode) const;

	//Mode전환시 아래 함수를 호출해줍니다
	void ChangeToPlayerMode();
	void ChangeToGameMode();
	void ChangeToSelectMode();

private:
	void Init();
	void MakeInteraction();
	
	OBJECT_TYPE CheckCollision() const;
	bool IsInteractionAvailable() const;

	MapLoader* m_mapLoader;
	Vector<GameObject*> m_gameObjects;
	Player* m_player;
	Babe* m_babe;
	MODE m_mode;
	Layer* m_runningScene;
};