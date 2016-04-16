#pragma once

class Player;

class EventObject : public Node
{
public:
	virtual bool init() = 0;
	virtual void Play() = 0;
	virtual void SetEffect(Player* player) = 0;
protected:
	Sprite* m_sprite;
};