#include "stdafx.h"
#include "GameScene.h"
#include "GameManager.h"

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameScene::create();

    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{
    if ( !Layer::init() )
        return false;
   
	m_gameManager = new GameManager();

	m_gameManager->AddToLayer(this);

	scheduleUpdate();
	
    return true;
}

void GameScene::update(float dt)
{
	m_gameManager->Play();
}
