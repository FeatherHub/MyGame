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
	m_textWriter->SetText(this, L"도레미파 솔라시도 레미파솔 라시도레?", Vec2(270, 250), 24.f, 10);
	m_textWriter->PrintText();
	addChild(m_textWriter);

	return true;
}

void TestScene::update(float delta)
{
	
}
