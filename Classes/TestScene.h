#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

class TestScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(TestScene);
};

#endif // __TEST_SCENE_H__
