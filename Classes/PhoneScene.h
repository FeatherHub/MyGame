#pragma once

class PhoneScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(PhoneScene);

private:

};