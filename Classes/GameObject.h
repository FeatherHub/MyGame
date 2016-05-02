#pragma once

//GameObject���� Scene Number Ȥ�� ���ǿ� ����
//���� �ٸ� ������ �Ѵ�
//ex) �������� �������� �︰ �Ŀ� ���ͷ��� �� �� �ִ�
//ex) �޴����� �μ��� �� ���ͷ��� �� �� ���� �ȴ�
//ex) �� �ӿ��� �ſ��� ��Ÿ�ϸ� ���� ȭ��Ʈ�ƿ��ȴ�

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