#include "stdafx.h"
#include "GameManager.h"
#include "Player.h"
#include "GameObject.h"

GameManager::GameManager() : m_isGameMode(false)
{
	Init();
}

GameManager::~GameManager()
{

}

void GameManager::Init()
{
	//지금은 수동으로 설정
	////Player, GameObject의 위치정보는 파일에서 파싱한다
	//파일은 Scene별(1~14)로 각 객체들의 위치 정보를 저장하고 있다. 
	
	m_player = Player::create();
	m_player->setPosition(300, 300);
}

void GameManager::AddToLayer(Layer* layer)
{
	if (!layer)
		return;

	layer->addChild(m_player);
}

void GameManager::MakeInteraction()
{
	if (!IsInteractionAvailable())
		return;
}

bool GameManager::IsInteractionAvailable()
{
	if (!m_player)
		return false;

	//가능하면
	return true;

	//인터랙션 할 수 있는 객체가 direction에 없으면
	return false;
}

void GameManager::InitKeyInput(bool* keyState)
{
	//if(일반모드이면)
	m_player->InitKeyState(keyState);
	m_player->StartUpdate();
	//else if(선택모드이면)
	//m_selectBar->InitKeyState(keyState);
	//else if(게임모드이면)
	//m_gameBar->InitKeyState(keyState);


}

void GameManager::SynchronizeKeyInput(EventKeyboard::KeyCode keyCode)
{
	if (m_isGameMode)
		1;
	else
		m_player->SetCurrentKey(keyCode);
}
