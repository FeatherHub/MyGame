#pragma once

class TextWriter : public Node
{
public:
	CREATE_FUNC(TextWriter);
	TextWriter() : PROMTING_SPEED(0.2f), DEFAULT_SPEED(0.2f), LETTER_FRAME(0.3f) {}
	~TextWriter() = default;
	bool init() override;
	void SetText(wchar_t* wStr, Vec2 pos, float fontSize, bool removeAfterDone, bool writeInstant);
	void PrintText();
	void SetRelation(TextWriter* prev, TextWriter* next) { m_prev = prev; m_next = next; }
	bool IsDone() { return m_isDone; }
protected:
	void OnKeyPressed(EventKeyboard::KeyCode keyCode);
	void OnKeyReleased(EventKeyboard::KeyCode keyCode);
	void update(float delta);
	void Remove();
	EventListenerKeyboard* m_keyboardListener;
	TextWriter* m_prev;
	TextWriter* m_next;	
	Label* m_label;
	float m_extraDelta;
	char m_string[255];	
	int m_length;
	int m_currentIdx;
	float m_elapsed;
	bool m_removeAfterDone;
	bool m_writeInstant;
	bool m_isDone;
	const float PROMTING_SPEED;
	const float DEFAULT_SPEED;
	const float LETTER_FRAME;
};