#include "GameObject.h"

class Player;
class Babe;

class Wall : public GameObject
{
public:
	CREATE_FUNC(Wall);
	bool init();
	void Play();
	void SetEffect(Player* player, Babe* babe);

private:
	DIRECTION m_dir;
};