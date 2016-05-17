#include "stdafx.h"
#include "CellPhone.h"
#include "Player.h"
#include "TextWriter.h"

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

	m_phoneUI[UI::SELECTED] = Sprite::create("phone_ui_selected.png");

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
	m_phoneUI[UI::SELECTED]->setOpacity(255);
	m_phoneUI[UI::RECEIVE]->setOpacity(255);
	m_phoneUI[UI::SELECTED]->setPosition(UI_LEFT - UI_DELTA);
	m_cursor = UI::OK;
	m_monitor = MONITOR::INIT;

	scheduleUpdate();
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
}

void CellPhone::OnKeyPressed(EventKeyboard::KeyCode keyCode)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_cursor = OK;
		m_phoneUI[UI::SELECTED]->setPosition(UI_LEFT - UI_DELTA);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_cursor = BACK;
		m_phoneUI[UI::SELECTED]->setPosition(UI_RIGHT - UI_DELTA);
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		switch (m_monitor)
		{
		case CellPhone::INIT:
			switch (m_cursor)
			{
			case CellPhone::OK:
				m_monitor = MESSAGE;
				m_phoneUI[UI::CLOSE]->setOpacity(0);
				m_phoneUI[UI::BACK]->setOpacity(255);
				m_phoneUI[UI::RECEIVE]->setOpacity(0);
				m_phoneUI[UI::TV_AD_HEAD]->setOpacity(255);
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
				m_monitor = READ_MESSAGE;
				m_phoneUI[UI::OK]->setOpacity(0);
				m_phoneUI[UI::SEND]->setOpacity(255);
				m_phoneUI[UI::TV_AD_HEAD]->setOpacity(0);
				m_phoneUI[UI::TV_AD_FULL]->setOpacity(255);
				break;
			case CellPhone::BACK:
				m_phoneUI[UI::CLOSE]->setOpacity(255);
				m_phoneUI[UI::BACK]->setOpacity(0);
				m_phoneUI[UI::RECEIVE]->setOpacity(255);
				m_phoneUI[UI::TV_AD_HEAD]->setOpacity(0);
				m_monitor = INIT;
				break;
			}
			break;
		case CellPhone::READ_MESSAGE:
			switch (m_cursor)
			{
			case CellPhone::OK:
			{
				//TYPE_WRITER -> GAME_MODE_GO
				m_keyboardListener->setEnabled(false);

				auto parent = getParent();

				auto tw1 = TextWriter::create();
				auto tw2 = TextWriter::create();
				auto tw3 = TextWriter::create();
				auto tw4 = TextWriter::create();

				parent->addChild(tw1, 8);
				parent->addChild(tw2, 8);
				parent->addChild(tw3, 8);
				parent->addChild(tw4, 8);

				tw1->SetRelation(nullptr, tw2);
				tw2->SetRelation(tw1, tw3);
				tw3->SetRelation(tw2, tw4);
				tw4->SetRelation(tw3, nullptr);

				Vec2 textPos{300, 50};
				Vec2 textPos2{ 300, 30 };
				tw1->SetText(L"이렇게 까지 무기력한 아이일 줄은 몰랐어요.", textPos, 16, false);
				tw2->SetText(L"여느때보다 버거운 일이 될 것 같네요. 히휴", textPos2, 16, true);
				tw3->SetText(L"잘 알고 계시겠지만, 지금 하시려는 일", textPos, 16, false);
				tw4->SetText(L"그러니까 구체적인 결정을 대신하는 것은 당신의 수명을 대가로 한다는 것을 잊진 않으셨죠?", textPos2, 16, false);

				tw1->PrintText();
			}
				break;
			case CellPhone::BACK:
				m_phoneUI[UI::OK]->setOpacity(255);
				m_phoneUI[UI::SEND]->setOpacity(0);
				m_phoneUI[UI::TV_AD_HEAD]->setOpacity(255);
				m_phoneUI[UI::TV_AD_FULL]->setOpacity(0);
				m_monitor = MESSAGE;
			}
			break;
		}
		break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		ClosePhone();
		break;
	}
}

void CellPhone::update(float delta)
{

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
