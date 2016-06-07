#include "stdafx.h"
#include "GameObject.h"
#include "Phone.h"
#include "TextWriter.h"
#include "Bar.h"

Phone* Phone::create(Node* parent)
{
	Phone *pRet = new(std::nothrow) Phone();
	if (pRet && pRet->init(parent))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool Phone::init(Node* parent)
{
	if (GameObject::init() == false)
	{
		return false;
	}

	m_sprite = Sprite::create("cellphone.png");
	addChild(m_sprite);

	m_keyboardListener = EventListenerKeyboard::create();
	m_keyboardListener->onKeyPressed = CC_CALLBACK_1(Phone::OnKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_keyboardListener, this);
	m_keyboardListener->setEnabled(false);

	m_uis[UI::BLACK] = Sprite::create("black.png");
	m_uis[UI::BLACK]->setOpacity(0);
	m_uis[UI::BLACK]->setScale(10.0f);
	parent->addChild(m_uis[UI::BLACK], 4);

	m_uis[UI::DET_SELECTED] = Sprite::create("player.png");
	m_uis[UI::DET_SELECTED]->setOpacity(0);
	m_uis[UI::DET_SELECTED]->setPosition(Vec2(285, -20));
	parent->addChild(m_uis[UI::DET_SELECTED], 5);

	m_uis[UI::BODY] = Sprite::create("phone_ui_body.png");
	m_uis[UI::BODY]->setOpacity(0);
	m_uis[UI::BODY]->setPosition(345, 200);
	parent->addChild(m_uis[UI::BODY], 6);

	m_uis[UI::OK] = Sprite::create("phone_ui_ok.png");
	m_uis[UI::OK]->setPosition(UI_LEFT);

	m_uis[UI::SEND] = Sprite::create("phone_ui_send.png");
	m_uis[UI::SEND]->setPosition(UI_LEFT);

	m_uis[UI::CLOSE] = Sprite::create("phone_ui_close.png");
	m_uis[UI::CLOSE]->setPosition(UI_RIGHT);

	m_uis[UI::BACK] = Sprite::create("phone_ui_back.png");
	m_uis[UI::BACK]->setPosition(UI_RIGHT);

	m_uis[UI::UI_SELECTED] = Sprite::create("phone_ui_selected.png");
	m_uis[UI::UI_SELECTED]->setPosition(UI_LEFT - UI_DELTA);

	m_uis[UI::RECEIVE] = Sprite::create("phone_receive.png");
	m_uis[UI::RECEIVE]->setPosition(CONTENT_HEAD);

	m_uis[UI::TV_AD_HEAD] = Sprite::create("phone_tv_ad_head.png");
	m_uis[UI::TV_AD_HEAD]->setPosition(CONTENT_HEAD);

	m_uis[UI::TV_AD_FULL] = Sprite::create("phone_tv_ad_full.png");
	m_uis[UI::TV_AD_FULL]->setPosition(CONTENT_FULL);

	for (int i = UI::CLOSE; i <= UI::TV_AD_FULL; i++)
	{
		m_uis[i]->setOpacity(0);
		m_uis[i]->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		m_uis[UI::BODY]->addChild(m_uis[i], 2);
	}

	m_cursor = UI::OK;
	m_monitor = MONITOR_STATE::INIT;

	return true;
}

void Phone::Play(Player* player, Babe* babe)
{
	m_player = player;
	m_player->unscheduleUpdate();

	m_uis[UI::BLACK]->runAction(FadeTo::create(0.6f, 190));

	m_keyboardListener->setEnabled(true);

	m_uis[UI::BODY]->setOpacity(255);
	m_uis[UI::OK]->setOpacity(255);
	m_uis[UI::CLOSE]->setOpacity(255);
	m_uis[UI::RECEIVE]->setOpacity(255);
	m_uis[UI::UI_SELECTED]->setOpacity(255);
}

void Phone::OnKeyPressed(EventKeyboard::KeyCode keyCode)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_cursor = OK;
		if (m_monitor == SELECT)
			m_uis[UI::DET_SELECTED]->setPosition(YES_POS);
		else
			m_uis[UI::UI_SELECTED]->setPosition(UI_LEFT - UI_DELTA);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_cursor = BACK;
		if (m_monitor == SELECT)
			m_uis[UI::DET_SELECTED]->setPosition(NO_POS);
		else
			m_uis[UI::UI_SELECTED]->setPosition(UI_RIGHT - UI_DELTA);
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		ProcessOK();
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		RemoveTextAndIcon();
		ClosePhone();
		break;
	}
}

void Phone::ProcessOK()
{
	switch (m_monitor)
	{
	case Phone::INIT:
		switch (m_cursor)
		{
		case Phone::OK:
			ChangeInitToMessage();
			break;
		case Phone::BACK:
			ClosePhone();
			break;;
		}
		break;
	case Phone::MESSAGE:
		switch (m_cursor)
		{
		case Phone::OK:
			ChangeMessageToRead();
			break;
		case Phone::BACK:
			ChangeMessageToInit();
			break;
		}
		break;
	case Phone::READ:
		switch (m_cursor)
		{
		case Phone::OK:
			ChangeReadToSelect();
			break;
		case Phone::BACK:
			ChangeReadToMessage();
			break;
		}
		break;
	case SELECT:
		switch (m_cursor)
		{
		case Phone::OK:
			//Go to Phone Scene
			break;
		case Phone::BACK:
			ChangeSelectToRead();
			break;
		}
		break;
	}
}

void Phone::ClosePhone()
{
	m_keyboardListener->setEnabled(false);
	m_player->ResetKeyState();
	m_player->scheduleUpdate();

	for (int i = 0; i < UI::UI_NUM; i++)
	{
		m_uis[i]->setOpacity(0);
	}
}

void Phone::RemoveTextAndIcon()
{
	m_tw3->removeFromParentAndCleanup(true);
	m_tw4->removeFromParentAndCleanup(true);
	m_yes->removeFromParentAndCleanup(true);
	m_no->removeFromParentAndCleanup(true);

	m_uis[UI::DET_SELECTED]->setOpacity(0);
}

void Phone::ChangeInitToMessage()
{
	m_monitor = MESSAGE;
	m_uis[UI::CLOSE]->setOpacity(0);
	m_uis[UI::BACK]->setOpacity(255);
	m_uis[UI::RECEIVE]->setOpacity(0);
	m_uis[UI::TV_AD_HEAD]->setOpacity(255);
}

void Phone::ChangeMessageToRead()
{
	m_monitor = READ;
	m_uis[UI::OK]->setOpacity(0);
	m_uis[UI::SEND]->setOpacity(255);
	m_uis[UI::TV_AD_HEAD]->setOpacity(0);
	m_uis[UI::TV_AD_FULL]->setOpacity(255);
}

void Phone::ChangeMessageToInit()
{
	m_monitor = INIT;
	m_uis[UI::CLOSE]->setOpacity(255);
	m_uis[UI::BACK]->setOpacity(0);
	m_uis[UI::RECEIVE]->setOpacity(255);
	m_uis[UI::TV_AD_HEAD]->setOpacity(0);
}

void Phone::ChangeReadToMessage()
{
	m_monitor = MESSAGE;
	m_uis[UI::OK]->setOpacity(255);
	m_uis[UI::SEND]->setOpacity(0);
	m_uis[UI::TV_AD_HEAD]->setOpacity(255);
	m_uis[UI::TV_AD_FULL]->setOpacity(0);
}

void Phone::ChangeReadToSelect()
{
	m_monitor = NONE;
	m_keyboardListener->setEnabled(false);

	auto parent = getParent();

	m_tw1 = TextWriter::create();
	m_tw2 = TextWriter::create();
	m_tw3 = TextWriter::create();
	m_tw4 = TextWriter::create();
	m_yes = TextWriter::create();
	m_no = TextWriter::create();

	parent->addChild(m_tw1, 8);
	parent->addChild(m_tw2, 8);
	parent->addChild(m_tw3, 8);
	parent->addChild(m_tw4, 8);
	parent->addChild(m_yes, 8);
	parent->addChild(m_no, 8);

	m_tw1->SetRelation(nullptr, m_tw2);
	m_tw2->SetRelation(m_tw1, m_tw3);
	m_tw3->SetRelation(m_tw2, m_tw4);
	m_tw4->SetRelation(m_tw3, m_yes);
	m_yes->SetRelation(m_tw4, m_no);
	m_no->SetRelation(m_yes, nullptr);

	Vec2 textPos{ 320, 50 };
	Vec2 textPos2{ 320, 30 };
	m_tw1->SetText(L"이렇게 까지 무기력한 아이일 줄은 몰랐어요.", textPos, 16, false, false);
	m_tw2->SetText(L"여느때보다 힘든 일이 될 것 같네요.", textPos2, 16, true, false);
	m_tw3->SetText(L"알고 계시겠지만, 지금 하시려는 일", textPos, 16, false, false);
	m_tw4->SetText(L"결정을 대신하는 것의 대가를 잊진 않으셨죠?", textPos2, 16, false, false);
	m_yes->SetText(L"응, 알고 있어", Vec2(220, -20), 14, false, true);
	m_no->SetText(L"잠깐만, 뭐였지?", Vec2(370, -20), 14, false, true);

	m_tw1->PrintText();
	schedule(CC_CALLBACK_1(Phone::CheckScriptOver, this), 0.1f, "CheckScriptOver");
	m_cursor = BACK;
}

void Phone::ChangeSelectToRead()
{
	RemoveTextAndIcon();
	m_monitor = READ;
	m_cursor = OK;
}

void Phone::CheckScriptOver(float delta)
{
	if (m_tw4->IsDone())
	{
		m_monitor = SELECT;

		m_keyboardListener->setEnabled(true);

		unschedule("CheckScriptOver");

		m_uis[UI::DET_SELECTED]->setOpacity(255);
	}
}