#pragma once

class Locker_1 : public GameObject
{
public:
	CREATE_FUNC(Locker_1);
	virtual bool init() override;
	virtual void Play(Player* player, Babe* babe) override;
};