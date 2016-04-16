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
	//������ �������� ����
	////Player, GameObject�� ��ġ������ ���Ͽ��� �Ľ��Ѵ�
	//������ Scene��(1~14)�� �� ��ü���� ��ġ ������ �����ϰ� �ִ�. 
	
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

	//�����ϸ�
	return true;

	//���ͷ��� �� �� �ִ� ��ü�� direction�� ������
	return false;
}

void GameManager::InitKeyInput(bool* keyState)
{
	//if(�Ϲݸ���̸�)
	m_player->InitKeyState(keyState);
	m_player->StartUpdate();
	//else if(���ø���̸�)
	//m_selectBar->InitKeyState(keyState);
	//else if(���Ӹ���̸�)
	//m_gameBar->InitKeyState(keyState);


}

void GameManager::SynchronizeKeyInput(EventKeyboard::KeyCode keyCode)
{
	if (m_isGameMode)
		1;
	else
		m_player->SetCurrentKey(keyCode);
}
