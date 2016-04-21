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

	layer->addChild(m_player, 1);
}


/* MakeInteraction Logic */				
/*
CheckCollision으로 먼저 앞에 뭔가 있는지 확인하고 
없으면 인터랙션 요청끄고 종료한다 
앞에 뭔가 있으면 벽이면 못가게 하고 요청끄고 종료한다. //벽과의 충돌체크는 요청이 없어도 해줘야하는 것이기 때문이다!!!//
벽이 아니고 Interaction요청 있으면 Interaction을 재생허고 요청을 끈다
*/
void GameManager::MakeInteraction() //매 프레임 호출된다
{
	//if (GameObject* gameObject = CheckCollision()) //현재 충돌한 객체가 없다면
	//{												
	//	m_player->TurnOffRequesting(); //인터랙션 요청을 종료하고
	//	return; //함수를 종료한다
	//}

	//if(충돌한 객체->GetObjectTyoe() == 벽)
	//캐릭터는 제자리 걸음!
	//요청끄고 return
	
	//if(!m_player->IsRequesting() && !IsInteractionAvailable())
	//요청끄고 return

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

GameObject* GameManager::CheckCollision() const //현재 충돌한 객체가 있다면 그 객체가 무엇인지 지정해준다.
{													//없으면 NULL
	//로직: 모든 객체와 플레이어의 위치가 2차원 배열에 저장되어 있다
	//따라서 '플레이어의 좌표 + 플레이어의 방향'를 인덱스로 위치배열에 접근해서
	//그곳에 객체가 있는지만 확인한다
	//공간 복잡도를 늘리고 시간 복잡도를 1로 할 수 있다.
	//어차피 타일맵 구조를 사용할 거니까 2차원 배열 정보를 한 번은 다루게 될 건데
	//그 정보를 저장한 뒤 플레이어 위치 갱신 로직만 추가해주면 된다.
	//이를 위해 플레이어 이동 애니메이션은 타일 한 칸 단위로 움직이도록 구현한다. <- Player 로직에 구현한다
	//좌표 갱신되는 시점은 이동 애니메이션이 끝나는 시점이다. <- MapInfoManager가 관리한다

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
