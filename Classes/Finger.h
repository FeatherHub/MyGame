#pragma once;

#include "PlayableObject.h"

class Finger : public PlayableObject
{
public:
	CREATE_FUNC(Finger);
	Finger();
	~Finger() = default;
	bool init() override;
private:
	void update(float delta);
};