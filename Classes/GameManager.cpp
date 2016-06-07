#include "stdafx.h"
#include "GameManager.h"
#include "PlayerConfig.h"
#include "GameObject.h"
#include "Player.h"
#include "Babe.h"
#include "Bar.h"

void GameManager::Play()
{
	MakeInteraction();
	
	ProcessState();
}

void GameManager::MakeInteraction()
{
	if (m_player->IsRequesting() == false)
	{
		return;
	}

	CheckCollisionWithObject();

	m_player->TurnOffRequesting();
}

void GameManager::ProcessState()
{
	switch (m_player->GetState())
	{
	case ENTER_BABE: // Enter -> In
	{
		m_babeBg->setOpacity(105);
		m_babe->SetState(CONTROLED);
		m_player->EnterEvent(m_babe->getPosition());
	}
		break;
	case IN_BABE: // In -> Exit
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
	case EXIT_BABE: // Exit -> Out
	{
		m_babeBg->setOpacity(0);
		m_babe->SetState(WALKAROUND);
		m_player->ExitEvent();
	}
	break;
	case OUT_BABE: // Out -> Enter
	{

	}
	}
}

void GameManager::CheckCollisionWithObject()
{		
	const Rect playerBox = m_player->GetBoundingBox();

	for (auto& gameObject : m_gameObjects)
	{
		if (gameObject->GetBoundingBox().intersectsRect(playerBox) == true)
		{
			gameObject->Play(m_player, m_babe);
		}
	}
}

void GameManager::RegisterData(Player* player, Babe* babe, 
	Bar* playerBar, /*Bar* missionBar,*/ 
	TMXTiledMap* room, Sprite* babeBg)
{
	m_player = player;
	m_babe = babe;
	m_playerBar = playerBar;
	/* m_missionBar = missionBar */
	m_room = room;
	m_babeBg = babeBg;
}


