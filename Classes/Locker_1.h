#pragma once

#include "GameObject.h"
class Player;
class Babe;

class Locker_1 : public GameObject
{
public:
	CREATE_FUNC(Locker_1);
	virtual bool init() override;
	virtual void Play() override;
	virtual void SetEffect(Player* player, Babe* babe) override;
};