#include "stdafx.h"
#include "TestScene.h"
#include "TextWriter.h"

Scene* TestScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = TestScene::create();

    scene->addChild(layer);

    return scene;
}

bool TestScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	return true;
}

void TestScene::update(float delta)
{
	
}
