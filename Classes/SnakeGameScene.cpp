#include "stdafx.h"
#include "SnakeGameScene.h"
#include "Finger.h"
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

	m_finger = Finger::create();
	addChild(m_finger, 2);

	m_mapLoader = new MapLoader();
	m_mapLoader->SetLayer(this);
	m_mapLoader->PrintMap("snake.tmx");

	scheduleUpdate();

    return true;
}

void SnakeGameScene::update(float delta)
{

}

