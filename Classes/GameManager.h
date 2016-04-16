#pragma once

#include "GameManagerConfig.h"

class Player;
class GameObject;

class GameManager
{
public:
	GameManager();
	~GameManager();

	//GameManager�� ������ �����ϰ� �Ʒ� �Լ��� ȣ�����־�� �մϴ�
	void AddToLayer(Layer* layer);
	void InitKeyInput(bool* keyState);
	
	//���� update �κп��� �Ʒ� �Լ��� ȣ�����־�� �մϴ�.
	void MakeInteraction();
	void SynchronizeKeyInput(EventKeyboard::KeyCode keyCode);
	
	//Mode��ȯ�� �Ʒ� �Լ��� ȣ�����ݴϴ�
	void ChangeToPlayerMode();
	void ChangeToGameMode();
	void ChangeToSelectMode();

private:
	void Init();
	bool IsInteractionAvailable();
	Vector<GameObject*> m_gameObjects;
	Player* m_player;
	MODE m_mode;
};