#pragma once

#include "GameManagerConfig.h"
#include "GameObjectConfig.h"

class Player;
class GameObject;

class GameManager
{
public:
	GameManager();
	~GameManager();

	//GameManager를 씬에서 생성하고 아래 함수를 호출해주어야 합니다
	void AddToLayer(Layer* layer) const;
	void InitKeyInput(bool* keyState) const;
	
	//씬의 update 부분에서 아래 함수를 호출해주어야 합니다.
	void MakeInteraction();
	void SynchronizeKeyInput(EventKeyboard::KeyCode keyCode) const;
	
	//Mode전환시 아래 함수를 호출해줍니다
	void ChangeToPlayerMode();
	void ChangeToGameMode();
	void ChangeToSelectMode();

private:
	void Init();
//	OBJECT_TYPE CheckCollision() const; //<--기각될 수도 있음 이유는 .cpp파일 참고
	bool CheckCollision() const;

	bool IsInteractionAvailable() const;
	Vector<GameObject*> m_gameObjects;
	Player* m_player;
	MODE m_mode;
};