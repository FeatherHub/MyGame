#pragma once

#include "GameObject.h"

class Mirror : public GameObject
{
public:
	Mirror();
	~Mirror();
	virtual bool init() override;
	CREATE_FUNC(Mirror);
	virtual void Play() override;
	virtual void SetEffect(Player* player) override;
};