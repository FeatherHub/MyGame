#pragma once

class Bar : public Node
{
public:
	CREATE_FUNC(Bar);
	bool init() override;
	void SetSprite(string current, string capacity, string icon);
	void SetEffect(float point);
	float GetPoint() { return m_point; }
	void SetPoint(float point) { m_point = point; }
private:
	Sprite* m_current;
	Sprite* m_capacity;
	Sprite* m_icon;
	float m_max;
	float m_point;
};