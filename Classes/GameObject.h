#pragma once

class Player;

class GameObject : public Node
{
public:
	virtual void Play() = 0;
	virtual void SetEffect(Player* player) = 0;
};