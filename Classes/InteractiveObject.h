#pragma once

//InteractiveObject���� Scene Number Ȥ�� ���ǿ� ����
//���� �ٸ� ������ �Ѵ�
//ex) �������� �������� �︰ �Ŀ� ���ͷ��� �� �� �ִ�
//ex) �޴����� �μ��� �� ���ͷ��� �� �� ���� �ȴ�
//ex) �� �ӿ��� �ſ��� ��Ÿ�ϸ� ���� ȭ��Ʈ�ƿ��ȴ�

class Player;

class InteractiveObject : public Node
{
public:
	virtual bool init() = 0;
	virtual void Play() = 0;
	virtual void SetEffect(Player* player) = 0;
protected:
	Sprite* m_sprite;
};