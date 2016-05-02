#pragma once

#include "GameObject.h"
class Player;
class Babe;

class Mirror : public GameObject
{
public:
	CREATE_FUNC(Mirror);
	virtual bool init() override;
	virtual void Play() override;
	virtual void SetEffect(Player* player, Babe* babe) override;
};