#include "stdafx.h"
#include "SnakeGameScene.h"
#include "InputManager.h"
#include "MapLoader.h"

Scene* SnakeGameScene::createScene()
{
    auto scene = Scene::create();

	auto layer = SnakeGameScene::create();

    scene->addChild(layer);

    return scene;
}

bool SnakeGameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	scheduleUpdate();

    return true;
}

void SnakeGameScene::update(float delta)
{

}

