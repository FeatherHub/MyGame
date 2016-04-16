#include "stdafx.h"
#include "GameManager.h"
#include "Player.h"
#include "InteractiveObject.h"

GameManager::GameManager() : m_mode(PLAYER_MODE)
{
	Init();
}

GameManager::~GameManager()
{

}

void GameManager::Init()
{
	//������ �������� ����
	////Player, GameObject�� ��ġ������ ���Ͽ��� �Ľ��Ѵ�
	//������ Scene��(1~14)�� �� ��ü���� ��ġ ������ �����ϰ� �ִ�. 
	
	m_player = Player::create();
	m_player->setPosition(300, 300);
}

void GameManager::AddToLayer(Layer* layer) const
{
	if (!layer)
		return;

	layer->addChild(m_player);
}

void GameManager::MakeInteraction()
{
	if (!m_player->IsRequesting())
		return;

	if (!CheckCollision() || !IsInteractionAvailable())
	{
		m_player->TurnOffRequesting();
		return;
	}

	//Logics
}

bool GameManager::CheckCollision() const
{
	return true;
}

bool GameManager::IsInteractionAvailable() const
{
	return true;
	//�����ϸ�
	//return true;

	//���ͷ��� �� �� �ִ� ��ü�� direction���⿡ ������
	//return false;
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
