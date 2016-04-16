#pragma once

class Player;
class GameObject;

class GameManager
{
public:
	GameManager();
	~GameManager();
	//씬의 update 부분에서 아래 함수를 호출해주어야 합니다.
	void MakeInteraction();
	void SynchronizeKeyInput(EventKeyboard::KeyCode keyCode);
	//GameManager를 씬에서 생성하고 아래 함수를 호출해주어야 합니다
	void AddToLayer(Layer* layer);
	void InitKeyInput(bool* keyState);

private:
	void Init();
	bool IsInteractionAvailable();
	Vector<GameObject*> m_gameObjects;
	Player* m_player;
	bool m_isGameMode;
};