#include "stdafx.h"
#include "MainScene.h"
#include "GameScene_01.h"
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
	
	Director* dir = Director::getInstance();
	Size size = dir->getVisibleSize();

	Sprite* background;
	Sprite* title;
	Sprite* text;

	switch (mainState)
	{
	case NORMAL:
		background = Sprite::create("main/bg_normal.png");
		title = Sprite::create("main/title_normal.png");
		text = Sprite::create("main/text_normal.png");
				
		m_cursorState = START;
		m_cursorPos[START] = Vec2(size.width / 2.75f, 197);
		m_cursorPos[LOAD] = Vec2(size.width / 2.75f, 155);
		m_cursorPos[EXIT] = Vec2(size.width / 2.75f, 115);
	
		m_cursor = Sprite::create("main/cursor.png");
		m_cursor->setAnchorPoint(Vec2(0, 1));
		m_cursor->setPosition(m_cursorPos[m_cursorState]);
		addChild(m_cursor, 2);

		text->setAnchorPoint(Vec2(0, 1));
		text->setPosition(Vec2(size.width / 2.25f, 195));
		addChild(text, 1);

		m_inputManager = InputManager::create();
		addChild(m_inputManager);

		m_keyState = m_inputManager->GetKeyState();

		scheduleUpdate();

		break;
	case SAD_END:
		background = Sprite::create("main/bg_sad.png");
		title = Sprite::create("main/title_sad.png");

		break;
	case HAPPY_END:
		background = Sprite::create("main/bg_happy.png");
		title = Sprite::create("main/title_happy.png");

		break;
	}

	background->setAnchorPoint(Vec2(0, 0));
	title->setPosition(Vec2(size.width / 2, 400));

	addChild(background);
	addChild(title);

    return true;
}

void MainScene::update(float delta)
{
	if (m_keyState[SPACE])
	{
		switch (m_cursorState)
		{
		case START:
			Director::getInstance()->replaceScene(GameScene_01::createScene());
			break;
		case LOAD:
			//to-do
			break;
		case EXIT:
			Director::getInstance()->end();
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
