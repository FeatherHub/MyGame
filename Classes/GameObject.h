#pragma once

//GameObject들은 Scene Number 혹은 조건에 따라
//각기 다른 반응을 한다
//ex) 현관문은 초인종이 울린 후에 인터랙션 할 수 있다
//ex) 휴대폰은 부서진 뒤 인터랙션 할 수 없게 된다
//ex) 꿈 속에서 거울을 연타하면 씬이 화이트아웃된다

#include "GameObjectConfig.h"

class Player;

class GameObject : public Node
{
public:
	virtual bool init() = 0;
	virtual void Play() = 0;
	virtual void SetEffect(Player* player) = 0;
	OBJECT_TYPE GetObjectType() { return m_objectType; }
protected:
	Sprite* m_sprite;
	OBJECT_TYPE m_objectType;

};