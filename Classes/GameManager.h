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

	//GameManager�� ������ �����ϰ� �Ʒ� �Լ��� ȣ�����־�� �մϴ�
	void AddToLayer(Layer* layer) const;
	void InitKeyInput(bool* keyState) const;
	
	//���� update �κп��� �Ʒ� �Լ��� ȣ�����־�� �մϴ�.
	void Play();
	void SynchronizeKeyInput(EventKeyboard::KeyCode keyCode) const;

	//Mode��ȯ�� �Ʒ� �Լ��� ȣ�����ݴϴ�
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