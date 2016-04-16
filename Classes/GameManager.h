#pragma once

class Player;
class GameObject;

class GameManager
{
public:
	GameManager();
	~GameManager();
	//���� update �κп��� �Ʒ� �Լ��� ȣ�����־�� �մϴ�.
	void MakeInteraction();
	void SynchronizeKeyInput(EventKeyboard::KeyCode keyCode);
	//GameManager�� ������ �����ϰ� �Ʒ� �Լ��� ȣ�����־�� �մϴ�
	void AddToLayer(Layer* layer);
	void InitKeyInput(bool* keyState);

private:
	void Init();
	bool IsInteractionAvailable();
	Vector<GameObject*> m_gameObjects;
	Player* m_player;
	bool m_isGameMode;
};