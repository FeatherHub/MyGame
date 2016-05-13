#include "stdafx.h"
#include "GameManager.h"
#include "PlayerConfig.h"
#include "Player.h"
#include "Babe.h"
#include "GameObject.h"
#include "Bar.h"
#include "Mirror.h"
#include "Locker_1.h"

GameManager::GameManager() : m_mode(PLAYER_MODE)
{
	Init();
}

GameManager::~GameManager()
{
	
}

void GameManager::Init()
{
	m_map = TMXTiledMap::create("map.tmx");

	m_player = Player::create();
	m_player->setPosition(300, 300);

	m_babe = Babe::create();
	m_babe->setPosition(200, 200);

	m_playerBar = Bar::create();
	m_playerBar->SetSprite("player_bar_current.png", "player_bar_capacity.png", "player_bar_icon.png");
	m_playerBar->setPosition(Vec2(200, 30));

	m_player->SetBar(m_playerBar);

	Mirror* mirror = Mirror::create();
	mirror->setPosition(Vec2(100, 100));
	m_gameObjects.pushBack(mirror);

	Locker_1* locker_1 = Locker_1::create();
	locker_1->setPosition(Vec2(400, 250));
	m_gameObjects.pushBack(locker_1);
}

void GameManager::AddToLayer(Layer* layer) const
{
	if (!layer)
		return;

	layer->addChild(m_map, -1);

	layer->addChild(m_player, 1);
	layer->addChild(m_playerBar, 0);
	layer->addChild(m_babe, 0);
	
	for (auto& gameObject : m_gameObjects)
		layer->addChild(gameObject, -1);
}

void GameManager::Play()
{
	MakeInteraction();

	STATE state = m_player->GetState();
	switch (state)
	{
	case ENTER_BABE:
	{
		m_player->EnterEvent(m_babe->getPosition());
	}
		break;
	case IN_BABE:
	{
		Vec2 playerPos = m_player->getPosition();
		Vec2 babePos = m_babe->getPosition();
		Vec2 deltaPos = (playerPos - babePos) / 20;
		if (babePos.distance(playerPos) > 100)
		{
			m_babe->setPosition(babePos + deltaPos);
		}
	}
		break;
	}
}

void GameManager::MakeInteraction()
{
	if (m_player->IsRequesting() == false ||
		IsInteractionAvailable() == false)
		return;

	OBJECT_TYPE objectType = CheckCollision();

	m_player->TurnOffRequesting();
}

OBJECT_TYPE GameManager::CheckCollision() const
{		
	const Rect playerBox = m_player->GetBoundingBox();

	for (auto& gameObject : m_gameObjects)
	{
		if (gameObject->GetBoundingBox().intersectsRect(playerBox) == true)
		{
			gameObject->SetEffect(m_player, m_babe);
			gameObject->Play();
			return gameObject->GetObjectType();
		}
	}

	return OBJECT_TYPE::NONE;
}

bool GameManager::IsInteractionAvailable() const
{
	return true;
}