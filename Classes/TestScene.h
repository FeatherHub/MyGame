#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

class TextWriter;

class TestScene : public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TestScene);

private:
	void update(float delta);
	TextWriter* m_textWriter;
};

#endif
