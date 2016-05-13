#include "stdafx.h"
#include "TextWriter.h"

bool TextWriter::init()
{
	if (Node::init() == false)
		return false;

	m_extraDelta = 0.f;

	m_keyboardListener = EventListenerKeyboard::create();
	m_keyboardListener->onKeyPressed = CC_CALLBACK_1(TextWriter::OnKeyPressed, this);
	m_keyboardListener->onKeyReleased = CC_CALLBACK_1(TextWriter::OnKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_keyboardListener, this);
	
	return true;
}

void TextWriter::SetText(Layer* targetLayer, wchar_t* wStr, Vec2 pos, float fontSize, int width)
{
	WideCharToMultiByte(CP_UTF8, 0, wStr, -1, m_string, 255, NULL, NULL);
	m_label = Label::createWithTTF(m_string, "fonts/NanumGothic.ttf", fontSize);
	m_label->setPosition(pos);
	m_label->setOpacity(0);
	targetLayer->addChild(m_label);
	
	m_pos = pos;
	m_width = width;
	m_fontSize = fontSize;
	m_length = m_label->getStringLength();
}

void TextWriter::PrintText()
{
	scheduleUpdate();
}

void TextWriter::update(float delta)
{
	static float elapsed = 0;
	static int currentIdx = 0;
//	static float previousWidth = 0;
//	static float previousColPos = 0;
	elapsed += delta + m_extraDelta;

	if (elapsed > LETTER_FRAME)
	{
		elapsed = 0;
		if (currentIdx < m_length)
		{
			auto letter = m_label->getLetter(currentIdx);

/*
			int row = currentIdx / m_width;
			
			if (row > 0)
			{
				float rowPos = -((letter->getContentSize().height) * row);
				
				if (previousColPos >= ((m_width-1) * m_fontSize))
					previousColPos = previousWidth;

				float colPos = previousColPos + previousWidth + m_fontSize/10;
				letter->setPosition(colPos, rowPos);
				previousColPos = colPos;
			}
			previousWidth = letter->getContentSize().width;
*/
			letter->setOpacity(255);
			currentIdx++;
		}
		else
		{
			m_keyboardListener->setEnabled(false);
			unscheduleUpdate();
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