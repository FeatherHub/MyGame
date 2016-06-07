#pragma once

class Mirror : public GameObject
{
public:
	CREATE_FUNC(Mirror);
	virtual bool init() override;
	virtual void Play(Player* player, Babe* babe) override;
};