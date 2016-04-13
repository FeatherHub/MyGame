#include "stdafx.h"
#include "TestScene.h"
#include "KeyStateManager.h"
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
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_keyStateManager = KeyStateManager::create();
	m_player = Player::create();

	m_player->InitKeyState(m_keyStateManager->GetKeyState());
	m_player->StartUpdate();

	addChild(m_keyStateManager);
	addChild(m_player);

	scheduleUpdate();

    return true;
}

void TestScene::update(float dt)
{
	m_player->SetCurrentKey(m_keyStateManager->GetCurrentKeyCode());
}
