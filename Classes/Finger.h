#pragma once;

#include "PlayableObject.h"

class Finger : public PlayableObject
{
public:
	CREATE_FUNC(Finger);
	Finger();
	~Finger() = default;
	bool init() override;
	Rect GetBoundingBox();
private:
	void update(float delta);
	void turn(const float angleDelta, const Vec2& moveDelta);
	Size m_sprSize;
	const float ACTION_TIME = 0.0f;
};