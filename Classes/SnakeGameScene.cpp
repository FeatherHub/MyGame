#include "stdafx.h"
#include "SnakeGameScene.h"
#include "InputManager.h"
#include "Bar.h"

Scene* SnakeGameScene::createScene(int* guage_bar)
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

	m_inputManager = InputManager::create();
	addChild(m_inputManager);

	m_keyState = m_inputManager->GetKeyState();

    return true;
}