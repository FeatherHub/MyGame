#include "GameObject.h"
#include "Player.h"

class Wall : public GameObject
{
public:
	CREATE_FUNC(Wall);
	bool init();
	void Play();
	void SetEffect(Player* player);

private:
	DIRECTION m_dir;
};