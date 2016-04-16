#pragma once

#include "InteractiveObject.h"

class Mirror : public InteractiveObject
{
public:
	Mirror();
	~Mirror();
	virtual bool init() override;
	CREATE_FUNC(Mirror);
	virtual void Play() override;
	virtual void SetEffect(Player* player) override;
};