#include "stdafx.h"
#include "MainScene.h"
#include "MainSceneConfig.h"
#include "TestScene.h"
#include "InputManager.h"

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MainScene::create();

    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
   
	MAIN_STATE mainState = MAIN_STATE::NORMAL;
	
	Sprite* background;
	Sprite* title;
	Sprite* text;
	switch (mainState)
	{
	case NORMAL:
	{
		background = Sprite::create("main/bg_normal.png");
		title = Sprite::create("main/title_normal.png");
		text = Sprite::create("main/text_normal.png");
		
		m_cursor = Sprite::create("main/cursor.png");
		m_cursor->setAnchorPoint(Vec2(0, 1));
		m_cursor->setPosition(Vec2(185, 197));
		addChild(m_cursor, 2);
		
		m_inputManager = InputManager::create();
		addChild(m_inputManager);
		
		m_keyState = m_inputManager->GetKeyState();
		
		m_cursorState = START;
		m_cursorPos[START] = Vec2(185, 197);
		m_cursorPos[LOAD] = Vec2(185, 155);
		m_cursorPos[EXIT] = Vec2(185, 115);
	
		scheduleUpdate();
	}
		break;
	case SAD_END:
		background = Sprite::create("main/bg_sad.png");
		title = Sprite::create("main/title_sad.png");
		text = Sprite::create("main/text_sad.png");		
		break;
	case HAPPY_END:
		background = Sprite::create("main/bg_happy.png");
		title = Sprite::create("main/title_happy.png");
		text = Sprite::create("main/text_happy.png");
		break;
	}

	background->setAnchorPoint(Vec2(0, 0));
	text->setAnchorPoint(Vec2(0, 1));

	title->setPosition(Vec2(250, 400));
	text->setPosition(Vec2(213, 195));

	addChild(background);
	addChild(title);
	addChild(text);

    return true;
}

void MainScene::update(float delta)
{
	if (m_keyState[SPACE])
	{
		switch (m_cursorState)
		{
		case START:
			runAction(CallFunc::create([](){
				auto scene = TestScene::createScene();
				Director::getInstance()->replaceScene(scene);
			}));
			break;
		case LOAD:
			break;
		case EXIT:
			runAction(CallFunc::create([](){ 
				Director::getInstance()->end();
			}));
			break;
		}
	}
	else if (m_keyState[UP])
	{
		switch (m_cursorState)
		{
		case LOAD:
			m_cursorState = START;
			m_cursor->setPosition(m_cursorPos[START]);
			m_keyState[UP] = false;
			break;
		case EXIT:
			m_cursorState = LOAD;
			m_cursor->setPosition(m_cursorPos[LOAD]);
			m_keyState[UP] = false;
			break;
		}
	}
	else if (m_keyState[DOWN])
	{
		switch (m_cursorState)
		{
		case START:
			m_cursorState = LOAD;
			m_cursor->setPosition(m_cursorPos[LOAD]);
			m_keyState[DOWN] = false;
			break;
		case LOAD:
			m_cursorState = EXIT;
			m_cursor->setPosition(m_cursorPos[EXIT]);
			m_keyState[DOWN] = false;
			break;
		}
	}
}
