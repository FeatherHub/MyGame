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
	//지금은 수동으로 설정
	////Player, GameObject의 위치정보는 파일에서 파싱한다
	//파일은 Scene별(1~14)로 각 객체들의 위치 정보를 저장하고 있다. 
	
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
		m_player->TurnOffRequesting(); //인터랙션 요청을 종료하고
		return; //함수를 종료한다
	}

	//EventObject가 필요없게 된다면 아래 방법들 및 CheckCollision의 주석 부분은 기각될듯
	//현재 EventObject가 필요한 객체는 망가진 휴대폰 한 개뿐임
	//switch (CheckCollision()) //충돌검사를 진행하여 
	//{						//충돌한 객체가 INTERACTIVE성인지, EVENT성인지에 따라 로직을 수행한다
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

bool GameManager::CheckCollision() const //현재 충돌한 객체가 있다면 그 객체가 무엇인지 지정해준다.
{

	//방법 1 : 모든 객체와 플레이어의 위치가 2차원 배열에 저장되어 있다
	//따라서 '플레이어의 좌표 + 플레이어의 방향'를 인덱스로 위치배열에 접근해서
	//그곳에 객체가 있는지만 확인한다
	//공간 복잡도를 늘리고 시간 복잡도를 1로 할 수 있다.
	//어차피 타일맵 구조를 사용할 거니까 2차원 배열 정보는 한 번은 다루게 될 건데
	//여기에 플레이어 위치 갱신만 추가해주면 된다.
	//대신 플레이어 이동 애니메이션은 타일 한 칸 단위로 움직이게 구현한다.
	//이동 애니메이션이 끝나면 플레이어의 좌표를 갱신한다.

	/*
	Point playerPosition = m_player->getPositionInMap();
	Point targetPosition = playerPosition + m_player->GetDirection();
	
	if(m_mapInfo[targetPosition.x][targetPosition.y].GetType == Object)
		return true;
	else
		return false;
	*/


	////기각될 듯 - EventObject는 휴대폰 하나밖에 없어서 그냥 하드 코딩으로 짜기로 했다.////
	//방법 2

	//INTERACTIVE Object의 충돌체크는 자기 방향 한 칸 앞에 있을 때 true 

	//EVENT Object의 충돌체크는 자기를 감싸는 두 칸 큰 사각형 안에 있을 때 true
	
	//각 경우의 false는 NONE을 반환

	/* 이런 느낌이 아닐까 싶다
	for (GameObject* object : m_gameObjects)
	{
		if (object->GetObjectType() == INTERACTIVE)
		{
			//충돌 로직 OK -> return INTERACTIVE;
		}
		else
		{
			//충돌 로직 OK -> return EVENT;
		}
	}

	//return NONE;
	*/

	return false;
}

bool GameManager::IsInteractionAvailable() const
{
	//현재 진행중인 인터랙션이 없으면
	//return true;
	//있으면
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
