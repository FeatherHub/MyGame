#pragma once

#include "PlayableObject.h"
#include "PlayerConfig.h"
#include "KeyConfig.h"

class Player : public PlayableObject
{
public:
	CREATE_FUNC(Player);
	Player();
	~Player();
	virtual bool init() override;
	//���ͷ����� �������־��ٸ� IsRequesting�� ���ּ���!!
	//���ͷ��� ��� �߿� ���ͷ��� ������?
	void TurnOffRequesting() { m_isRequesting = false; }
	bool IsRequesting() { return m_isRequesting; }
	DIRECTION GetDirection() { return m_direction; };

private:
	void update(float dt);
	DIRECTION m_direction = SOUTH;
	Sprite* m_sprite = nullptr;
	float m_speed = DEFAULT_SPEED;
	bool m_isRequesting = false;
};