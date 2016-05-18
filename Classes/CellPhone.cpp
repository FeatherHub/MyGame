#include "stdafx.h"
#include "CellPhone.h"
#include "Player.h"
#include "TextWriter.h"
#include "Bar.h"

bool CellPhone::init()
{
	if (GameObject::init() == false)
		return false;

	m_keyboardListener = EventListenerKeyboard::create();
	m_keyboardListener->onKeyPressed = CC_CALLBACK_1(CellPhone::OnKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_keyboardListener, this);
	m_keyboardListener->setEnabled(false);

	m_monitor = INIT;

	m_sprite = Sprite::create("cellphone.png");
	addChild(m_sprite);

	return true;
}

void CellPhone::Play()
{
	m_keyboardListener->setEnabled(true);

	auto parent = getParent();
	
	m_phoneUI[UI::BODY] = Sprite::create("phone_ui_body.png");
	m_phoneUI[UI::BODY]->setPosition(345, 200);
	m_phoneUI[UI::BODY]->setScale(1.3f);
	parent->addChild(m_phoneUI[UI::BODY], 6);

	m_phoneUI[UI::OK] = Sprite::create("phone_ui_ok.png");
	m_phoneUI[UI::OK]->setPosition(UI_LEFT);

	m_phoneUI[UI::SEND] = Sprite::create("phone_ui_send.png");
	m_phoneUI[UI::SEND]->setPosition(UI_LEFT);

	m_phoneUI[UI::CLOSE] = Sprite::create("phone_ui_close.png");
	m_phoneUI[UI::CLOSE]->setPosition(UI_RIGHT);

	m_phoneUI[UI::BACK] = Sprite::create("phone_ui_back.png");
	m_phoneUI[UI::BACK]->setPosition(UI_RIGHT);

	m_phoneUI[UI::UI_SELECTED] = Sprite::create("phone_ui_selected.png");

	m_phoneUI[UI::RECEIVE] = Sprite::create("phone_receive.png");
	m_phoneUI[UI::RECEIVE]->setPosition(CONTENT_HEAD);

	m_phoneUI[UI::TV_AD_HEAD] = Sprite::create("phone_tv_ad_head.png");
	m_phoneUI[UI::TV_AD_HEAD]->setPosition(CONTENT_HEAD);

	m_phoneUI[UI::TV_AD_FULL] = Sprite::create("phone_tv_ad_full.png");
	m_phoneUI[UI::TV_AD_FULL]->setPosition(CONTENT_FULL);

	for (int i = 1; i < UI::UI_NUM; i++)
	{
		m_phoneUI[i]->setOpacity(0);
		m_phoneUI[i]->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		m_phoneUI[UI::BODY]->addChild(m_phoneUI[i], 2);
	}

	m_phoneUI[UI::OK]->setOpacity(255);
	m_phoneUI[UI::CLOSE]->setOpacity(255);
	m_phoneUI[UI::UI_SELECTED]->setOpacity(255);
	m_phoneUI[UI::RECEIVE]->setOpacity(255);
	m_phoneUI[UI::UI_SELECTED]->setPosition(UI_LEFT - UI_DELTA);
	m_cursor = UI::OK;
	m_monitor = MONITOR_STATE::INIT;
}

void CellPhone::SetEffect(Player* player, Babe* babe)
{
	m_player = player;
	m_player->unscheduleUpdate();

	auto parent = getParent();
	m_black = Sprite::create("black.png");
	m_black->setOpacity(0);
	m_black->setScale(10.0f);
	parent->addChild(m_black, 5);
	m_black->runAction(FadeTo::create(0.6f, 190));

	auto playerBar = Bar::create();
	playerBar->SetSprite("player_bar_current.png", "player_bar_capacity.png", "player_bar_icon.png");
	playerBar->setPosition(Vec2(200, -50));
	parent->addChild(playerBar, 6);
}

void CellPhone::OnKeyPressed(EventKeyboard::KeyCode keyCode)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_cursor = OK;
		if (m_monitor == SELECT)
			m_detSeleceted->setPosition(YES_POS);
		else
			m_phoneUI[UI::UI_SELECTED]->setPosition(UI_LEFT - UI_DELTA);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_cursor = BACK;
		if (m_monitor == SELECT)
			m_detSeleceted->setPosition(NO_POS);
		else
			m_phoneUI[UI::UI_SELECTED]->setPosition(UI_RIGHT - UI_DELTA);
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		switch (m_monitor)
		{
		case CellPhone::INIT:
			switch (m_cursor)
			{
			case CellPhone::OK:
				ChangeInitToMessage();
				break;
			case CellPhone::BACK:
				ClosePhone();
				break;;
			}
			break;
		case CellPhone::MESSAGE:
			switch (m_cursor)
			{
			case CellPhone::OK:
				ChangeMessageToRead();
				break;
			case CellPhone::BACK:
				ChangeMessageToInit();
				break;
			}
			break;
		case CellPhone::READ:
			switch (m_cursor)
			{
			case CellPhone::OK:
				ChangeReadToSelect();
				break;
			case CellPhone::BACK:
				ChangeReadToMessage();
				break;
			}
			break;
		case SELECT:
			switch (m_cursor)
			{
			case CellPhone::OK:
				//Let's go Game Scene
				break;
			case CellPhone::BACK:
				m_monitor = READ;
				RemoveTextAndIcon();
				break;
			}
			break;
		}
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		ClosePhone();
		break;
	}
}

void CellPhone::ClosePhone()
{
	unscheduleUpdate();
	m_keyboardListener->setEnabled(false);
	m_phoneUI[BODY]->removeFromParent();
	m_black->removeFromParent();
	m_player->ResetKeyState();
	m_player->scheduleUpdate();
}

void CellPhone::RemoveTextAndIcon()
{
	m_tw3->removeFromParent();
	m_tw4->removeFromParent();
	m_yes->removeFromParent();
	m_no->removeFromParent();
	m_detSeleceted->removeFromParent();
}

void CellPhone::ChangeInitToMessage()
{
	m_phoneUI[UI::CLOSE]->setOpacity(0);
	m_phoneUI[UI::BACK]->setOpacity(255);
	m_phoneUI[UI::RECEIVE]->setOpacity(0);
	m_phoneUI[UI::TV_AD_HEAD]->setOpacity(255);
	m_monitor = MESSAGE;
}

void CellPhone::ChangeMessageToRead()
{
	m_monitor = READ;
	m_phoneUI[UI::OK]->setOpacity(0);
	m_phoneUI[UI::SEND]->setOpacity(255);
	m_phoneUI[UI::TV_AD_HEAD]->setOpacity(0);
	m_phoneUI[UI::TV_AD_FULL]->setOpacity(255);
}

void CellPhone::ChangeMessageToInit()
{
	m_monitor = INIT;
	m_phoneUI[UI::CLOSE]->setOpacity(255);
	m_phoneUI[UI::BACK]->setOpacity(0);
	m_phoneUI[UI::RECEIVE]->setOpacity(255);
	m_phoneUI[UI::TV_AD_HEAD]->setOpacity(0);
}

void CellPhone::ChangeReadToMessage()
{
	m_monitor = MESSAGE;
	m_phoneUI[UI::OK]->setOpacity(255);
	m_phoneUI[UI::SEND]->setOpacity(0);
	m_phoneUI[UI::TV_AD_HEAD]->setOpacity(255);
	m_phoneUI[UI::TV_AD_FULL]->setOpacity(0);
}

void CellPhone::ChangeReadToSelect()
{
	m_monitor = NONE;
	runAction(Sequence::create(
		DelayTime::create(1.5f),
		CallFunc::create([&](){ m_monitor = SELECT; }),
		nullptr));

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
	m_tw2->SetText(L"여느때보다 버거운 일이 될 것 같네요. 히휴", textPos2, 16, true, false);
	m_tw3->SetText(L"잘 알고 계시겠지만, 지금 하시려는 일", textPos, 16, false, false);
	m_tw4->SetText(L"그러니까 구체적인 결정을 대신하는 것은 당신의 수명을 대가로 한다는 것을 잊진 않으셨죠?", textPos2, 16, false, false);
	m_yes->SetText(L"응, 알고 있어", Vec2(220, -20), 14, false, true);
	m_no->SetText(L"잠깐만, 깜빡하고 있었어", Vec2(370, -20), 14, false, true);

	m_tw1->PrintText();

	m_detSeleceted = Sprite::create("player.png");
	m_detSeleceted->setScale(0.1f);
	m_detSeleceted->setPosition(Vec2(285, -20));
	parent->addChild(m_detSeleceted, 8);
	m_cursor = BACK;
}