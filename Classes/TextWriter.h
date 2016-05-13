#pragma once

class TextWriter : public Node
{
public:
	CREATE_FUNC(TextWriter);
	TextWriter() : PROMTING_SPEED(0.2f), DEFAULT_SPEED(0.2f), LETTER_FRAME(0.3f) {}
	~TextWriter() = default;
	bool init() override;
	void SetText(Layer* layer, wchar_t* wStr, Vec2 pos, float fontSize);
	void PrintText();
private:
	void OnKeyPressed(EventKeyboard::KeyCode keyCode);
	void OnKeyReleased(EventKeyboard::KeyCode keyCode);
	void update(float delta);
	char m_string[255];
	Label* m_label;
	bool m_extraDelta;
	EventListenerKeyboard* m_keyboardListener;
	int m_length;
	const float PROMTING_SPEED;
	const float DEFAULT_SPEED;
	const float LETTER_FRAME; // 이후: 문자열 길이에 따라서 시간 조절
};