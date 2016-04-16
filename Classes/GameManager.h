#pragma once

#include "GameManagerConfig.h"

class Player;
class InteractiveObject;

class GameManager
{
public:
	GameManager();
	~GameManager();

	//GameManager�� ������ �����ϰ� �Ʒ� �Լ��� ȣ�����־�� �մϴ�
	void AddToLayer(Layer* layer) const;
	void InitKeyInput(bool* keyState) const;
	
	//���� update �κп��� �Ʒ� �Լ��� ȣ�����־�� �մϴ�.
	void MakeInteraction();
	void SynchronizeKeyInput(EventKeyboard::KeyCode keyCode) const;
	
	//Mode��ȯ�� �Ʒ� �Լ��� ȣ�����ݴϴ�
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