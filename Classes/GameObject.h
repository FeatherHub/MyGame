#pragma once

//GameObject���� Scene Number Ȥ�� ���ǿ� ����
//���� �ٸ� ������ �Ѵ�
//ex) �������� �������� �︰ �Ŀ� ���ͷ��� �� �� �ִ�
//ex) �޴����� �μ��� �� ���ͷ��� �� �� ���� �ȴ�
//ex) �� �ӿ��� �ſ��� ��Ÿ�ϸ� ���� ȭ��Ʈ�ƿ��ȴ�

#include "GameObjectConfig.h"

class Player;
class Babe;

class GameObject : public Node
{
public:
	virtual ~GameObject() = default;
	virtual bool init();
	virtual void Play() = 0;
	virtual void SetEffect(Player* player, Babe* babe) = 0;
	OBJECT_TYPE GetObjectType() { return m_objectType; }
	Rect GetBoundingBox();

protected:
	Sprite* m_sprite;
	OBJECT_TYPE m_objectType;
	bool m_available;
};