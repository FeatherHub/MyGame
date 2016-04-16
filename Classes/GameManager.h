#pragma once

#include "GameManagerConfig.h"

class Player;
class InteractiveObject;

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
	bool CheckCollision() const;
	bool IsInteractionAvailable() const;
	Vector<InteractiveObject*> m_gameObjects;
	Player* m_player;
	MODE m_mode;
};