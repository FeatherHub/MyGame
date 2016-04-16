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
//	OBJECT_TYPE CheckCollision() const; //<--�Ⱒ�� ���� ���� ������ .cpp���� ����
	bool CheckCollision() const;

	bool IsInteractionAvailable() const;
	Vector<GameObject*> m_gameObjects;
	Player* m_player;
	MODE m_mode;
};