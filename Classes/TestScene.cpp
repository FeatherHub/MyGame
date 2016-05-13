#include "stdafx.h"
#include "TestScene.h"
#include "TextWriter.h"

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
	
	m_textWriter = TextWriter::create();
	m_textWriter->SetText(this, L"���� �ǳ��� �̰� ������ �Ƴ�� ���� ���� �ϴ� �ſ���?", Vec2(200, 200), 24.f);
	m_textWriter->PrintText();
	addChild(m_textWriter);

	return true;
}

void TestScene::update(float delta)
{
	
}
