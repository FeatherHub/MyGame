#pragma once

class Bar : public Node
{
public:
	CREATE_FUNC(Bar);
	bool init() override;
	void SetEffeect(int point);

private:
	Sprite* m_current;
	Sprite* m_capacity;
	Sprite* m_icon;
	int m_max;
	int m_point;
};