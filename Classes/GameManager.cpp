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

	layer->addChild(m_player, 1);
}


/* MakeInteraction Logic */				
/*
CheckCollision���� ���� �տ� ���� �ִ��� Ȯ���ϰ� 
������ ���ͷ��� ��û���� �����Ѵ� 
�տ� ���� ������ ���̸� ������ �ϰ� ��û���� �����Ѵ�. //������ �浹üũ�� ��û�� ��� ������ϴ� ���̱� �����̴�!!!//
���� �ƴϰ� Interaction��û ������ Interaction�� ������ ��û�� ����
*/
void GameManager::MakeInteraction() //�� ������ ȣ��ȴ�
{
	//if (GameObject* gameObject = CheckCollision()) //���� �浹�� ��ü�� ���ٸ�
	//{												
	//	m_player->TurnOffRequesting(); //���ͷ��� ��û�� �����ϰ�
	//	return; //�Լ��� �����Ѵ�
	//}

	//if(�浹�� ��ü->GetObjectTyoe() == ��)
	//ĳ���ʹ� ���ڸ� ����!
	//��û���� return
	
	//if(!m_player->IsRequesting() && !IsInteractionAvailable())
	//��û���� return

	//Interation Logic//
	//				  //	
	//				  //
	//				  //
	//				  //
	//				  //
	//				  //
	////////////////////

	m_player->TurnOffRequesting();
}

GameObject* GameManager::CheckCollision() const //���� �浹�� ��ü�� �ִٸ� �� ��ü�� �������� �������ش�.
{													//������ NULL
	//����: ��� ��ü�� �÷��̾��� ��ġ�� 2���� �迭�� ����Ǿ� �ִ�
	//���� '�÷��̾��� ��ǥ + �÷��̾��� ����'�� �ε����� ��ġ�迭�� �����ؼ�
	//�װ��� ��ü�� �ִ����� Ȯ���Ѵ�
	//���� ���⵵�� �ø��� �ð� ���⵵�� 1�� �� �� �ִ�.
	//������ Ÿ�ϸ� ������ ����� �Ŵϱ� 2���� �迭 ������ �� ���� �ٷ�� �� �ǵ�
	//�� ������ ������ �� �÷��̾� ��ġ ���� ������ �߰����ָ� �ȴ�.
	//�̸� ���� �÷��̾� �̵� �ִϸ��̼��� Ÿ�� �� ĭ ������ �����̵��� �����Ѵ�. <- Player ������ �����Ѵ�
	//��ǥ ���ŵǴ� ������ �̵� �ִϸ��̼��� ������ �����̴�. <- MapInfoManager�� �����Ѵ�

	/*
	Point playerPosition = m_player->getPositionInMapCoordination();
	Point targetPosition = playerPosition + m_player->GetDirectionInToPosition();
	
	if(m_mapInfo[targetPosition.x][targetPosition.y].GetType == Object)
		return m_mapInfo[targetPosition.x][targetPosition.y];
	else
		return (GameObject*)nullptr;
	*/

	return nullptr;
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
