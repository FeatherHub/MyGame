#include "stdafx.h"
#include "TextWriter.h"

bool TextWriter::init()
{
	if (Node::init() == false)
		return false;
	
	m_elapsed = 0.f;
	m_currentIdx = 0;
	m_extraDelta = 0.f;
	m_removeAfterDone = false;
	m_waitBeforeRemoved = false;
	m_keyboardListener = EventListenerKeyboard::create();
	m_keyboardListener->onKeyPressed = CC_CALLBACK_1(TextWriter::OnKeyPressed, this);
	m_keyboardListener->onKeyReleased = CC_CALLBACK_1(TextWriter::OnKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_keyboardListener, this);
	
	return true;
}

void TextWriter::SetText(wchar_t* wStr, Vec2 pos, float fontSize, bool removeAfterDone, bool writeInstant)
{
	WideCharToMultiByte(CP_UTF8, 0, wStr, -1, m_string, 255, NULL, NULL);
	m_label = Label::createWithTTF(m_string, "fonts/NanumGothic.ttf", fontSize, Size::ZERO,
		TextHAlignment::LEFT);
	m_label->setPosition(pos);
	m_label->setOpacity(0);
	
	addChild(m_label);

	m_removeAfterDone = removeAfterDone;
	m_waitBeforeRemoved = m_removeAfterDone;
	m_writeInstant = writeInstant;
	m_length = m_label->getStringLength();
}

void TextWriter::PrintText()
{
	if (m_writeInstant == true)
	{
		m_label->setOpacity(255);
		if (m_next != nullptr)
			m_next->PrintText();
	}
	else
		scheduleUpdate();
}

void TextWriter::update(float delta)
{
	m_elapsed += delta + m_extraDelta;

	if (m_elapsed > LETTER_FRAME)
	{
		m_elapsed = 0;
		if (m_currentIdx < m_length)
		{
			auto letter = m_label->getLetter(m_currentIdx);
			letter->setOpacity(255);
			m_currentIdx++;
		}
		else
		{
			m_keyboardListener->setEnabled(false);

			if (m_waitBeforeRemoved)
			{
				m_waitBeforeRemoved = false;
				unscheduleUpdate();
				runAction(Sequence::create(
					DelayTime::create(0.85f),
					CallFunc::create([&](){ scheduleUpdate(); }),
					nullptr));
				return;
			}
		
			unscheduleUpdate();

			if (m_next != nullptr)
			{
				m_next->PrintText();
			}

			if (m_removeAfterDone)
			{
				if (m_prev != nullptr)
					m_prev->removeFromParent();
				removeFromParent();
			}
		}
	}
}

void TextWriter::OnKeyPressed(EventKeyboard::KeyCode keyCode)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_SPACE:
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_extraDelta = PROMTING_SPEED;
	}
}

void TextWriter::OnKeyReleased(EventKeyboard::KeyCode keyCode)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_SPACE:
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_extraDelta = 0.f;
	}
}