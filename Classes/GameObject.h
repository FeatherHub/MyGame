#pragma once

//GameObject���� Scene Number Ȥ�� ���ǿ� ����
//���� �ٸ� ������ �Ѵ�
//ex) �������� �������� �︰ �Ŀ� ���ͷ��� �� �� �ִ�
//ex) �޴����� �μ��� �� ���ͷ��� �� �� ���� �ȴ�
//ex) �� �ӿ��� �ſ��� ��Ÿ�ϸ� ���� ȭ��Ʈ�ƿ��ȴ�


class Player;

class GameObject : public Node
{
public:
	virtual void Play() = 0;
	virtual void SetEffect(Player* player) = 0;
};