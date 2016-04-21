#include "stdafx.h"
#include "TestScene.h"
#include "InputManager.h"
#include "GameManager.h"
#include "MapLoader.h"
#include "Player.h"

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
        return false;
   
	m_gameManager = new GameManager();
	m_mapLoader = new MapLoader;

	m_mapLoader->SetLayer(this);
	m_mapLoader->PrintMap();

	m_inputManager = InputManager::create();

	m_gameManager->AddToLayer(this);
	m_gameManager->InitKeyInput(m_inputManager->GetKeyState());

	addChild(m_inputManager);

	scheduleUpdate();
	
    return true;
}

void TestScene::update(float dt)
{
	m_gameManager->SynchronizeKeyInput(m_inputManager->GetCurrentKeyCode());
	m_gameManager->MakeInteraction();
}
