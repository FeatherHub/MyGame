#include "stdafx.h"
#include "GameManager.h"
#include "Player.h"
#include "GameObject.h"

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

	if (!IsInteractionAvailable() && !CheckCollision())
	{
		m_player->TurnOffRequesting(); //���ͷ��� ��û�� �����ϰ�
		return; //�Լ��� �����Ѵ�
	}

	//EventObject�� �ʿ���� �ȴٸ� �Ʒ� ����� �� CheckCollision�� �ּ� �κ��� �Ⱒ�ɵ�
	//���� EventObject�� �ʿ��� ��ü�� ������ �޴��� �� ������
	//switch (CheckCollision()) //�浹�˻縦 �����Ͽ� 
	//{						//�浹�� ��ü�� INTERACTIVE������, EVENT�������� ���� ������ �����Ѵ�
	//case INTERACTIVE:
	//	////////
	//	/*Logic*/

	//	////////
	//	break;
	//case EVENT:
	//	////////
	//	/*Logic*/

	//	////////
	//	break;
	//}

	//	////////
	//	/*Logic*/
	 





	//	////////
	
	m_player->TurnOffRequesting();
}

bool GameManager::CheckCollision() const //���� �浹�� ��ü�� �ִٸ� �� ��ü�� �������� �������ش�.
{

	//��� 1 : ��� ��ü�� �÷��̾��� ��ġ�� 2���� �迭�� ����Ǿ� �ִ�
	//���� '�÷��̾��� ��ǥ + �÷��̾��� ����'�� �ε����� ��ġ�迭�� �����ؼ�
	//�װ��� ��ü�� �ִ����� Ȯ���Ѵ�
	//���� ���⵵�� �ø��� �ð� ���⵵�� 1�� �� �� �ִ�.
	//������ Ÿ�ϸ� ������ ����� �Ŵϱ� 2���� �迭 ������ �� ���� �ٷ�� �� �ǵ�
	//���⿡ �÷��̾� ��ġ ���Ÿ� �߰����ָ� �ȴ�.
	//��� �÷��̾� �̵� �ִϸ��̼��� Ÿ�� �� ĭ ������ �����̰� �����Ѵ�.
	//�̵� �ִϸ��̼��� ������ �÷��̾��� ��ǥ�� �����Ѵ�.

	/*
	Point playerPosition = m_player->getPositionInMap();
	Point targetPosition = playerPosition + m_player->GetDirection();
	
	if(m_mapInfo[targetPosition.x][targetPosition.y].GetType == Object)
		return true;
	else
		return false;
	*/


	////�Ⱒ�� �� - EventObject�� �޴��� �ϳ��ۿ� ��� �׳� �ϵ� �ڵ����� ¥��� �ߴ�.////
	//��� 2

	//INTERACTIVE Object�� �浹üũ�� �ڱ� ���� �� ĭ �տ� ���� �� true 

	//EVENT Object�� �浹üũ�� �ڱ⸦ ���δ� �� ĭ ū �簢�� �ȿ� ���� �� true
	
	//�� ����� false�� NONE�� ��ȯ

	/* �̷� ������ �ƴұ� �ʹ�
	for (GameObject* object : m_gameObjects)
	{
		if (object->GetObjectType() == INTERACTIVE)
		{
			//�浹 ���� OK -> return INTERACTIVE;
		}
		else
		{
			//�浹 ���� OK -> return EVENT;
		}
	}

	//return NONE;
	*/

	return false;
}

bool GameManager::IsInteractionAvailable() const
{
	//���� �������� ���ͷ����� ������
	//return true;
	//������
	//return false;

	return false;
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
