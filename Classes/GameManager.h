#pragma once

class Player;
class Babe;
class GameObject;
class Bar;

class GameManager
{
public:
	GameManager() = default;
	~GameManager() = default;

	void Play();
	void RegisterGameObject(GameObject* gameObject) { m_gameObjects.pushBack(gameObject); }
	void RegisterData(Player* player, Babe* babe, Bar* playerBar, /*Bar* missionBar,*/ TMXTiledMap* room, Sprite* babeBg);

private:
	void MakeInteraction();
	void ProcessState();
	void CheckCollisionWithObject();

	Vector<GameObject*> m_gameObjects;
	//data to register
	Player* m_player;
	Babe* m_babe;
	Bar* m_playerBar;
	//Bar* m_missionBar;
	TMXTiledMap* m_room;
	Sprite* m_babeBg;
};