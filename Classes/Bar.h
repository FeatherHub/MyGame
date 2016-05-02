#pragma once

class Bar : public Node
{
public:
	CREATE_FUNC(Bar);
	bool init() override;
	void SetSprite(string current, string capacity, string icon);
	void SetEffect(float point);
private:
	Sprite* m_current;
	Sprite* m_capacity;
	Sprite* m_icon;
	float m_max;
	float m_point;
};