#include "stdafx.h"
#include "GameManager.h"
#include "PlayerConfig.h"
#include "Player.h"
#include "Babe.h"
#include "GameObject.h"
#include "MapLoader.h"
#include "Bar.h"
#include "Mirror.h"

GameManager::GameManager() : m_mode(PLAYER_MODE)
{
	Init();
}

GameManager::~GameManager()
{
	
}

void GameManager::Init()
{
	//SceneInformation은 Scene 단위로 객체들의 위치 정보가 저장된 File을 읽는다. 

	m_mapLoader = new MapLoader;

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
}

void GameManager::AddToLayer(Layer* layer) const
{
	if (!layer)
		return;

	m_mapLoader->SetLayer(layer);
	m_mapLoader->PrintMap();

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

void GameManager::InitKeyInput(bool* keyState) const
{
	switch (m_mode)
	{
	case PLAYER_MODE:
		m_player->InitKeyState(keyState);
		m_player->StartUpdate();
		break;
	case GAME_MODE:
		break;
	case SELECT_MODE:
		break;
	}
}

void GameManager::SynchronizeKeyInput(EventKeyboard::KeyCode keyCode) const
{
	switch (m_mode)
	{
	case PLAYER_MODE:
		m_player->SetCurrentKey(keyCode);
		break;
	case GAME_MODE:
		break;
	case SELECT_MODE:
		break;
	}		
}

void GameManager::ChangeToPlayerMode()
{
	m_player->StartUpdate();
	m_mode = PLAYER_MODE;
}

void GameManager::ChangeToGameMode()
{
	m_player->StopUpdate();
	m_mode = GAME_MODE;
}

void GameManager::ChangeToSelectMode()
{
	m_player->StartUpdate();
	m_mode = SELECT_MODE;
}