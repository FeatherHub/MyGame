#include "stdafx.h"
#include "SnakeGameScene.h"
#include "Finger.h"

Scene* SnakeGameScene::createScene()
{
    auto scene = Scene::create();

	auto layer = SnakeGameScene::create();

    scene->addChild(layer);

    return scene;
}

bool SnakeGameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	m_finger = Finger::create();
	m_finger->setPosition(Vec2(40, 0));
	addChild(m_finger, 2);

	m_map = TMXTiledMap::create("snake.tmx");
	addChild(m_map, 1);

	m_layer = m_map->layerNamed("Layer");

	scheduleUpdate();

    return true;
}

void SnakeGameScene::update(float delta)
{
	auto size = m_layer->getLayerSize();

	for (int x = 0; x < size.width; x++)
	{
		for (int y = 0; y < size.height; y++)
		{
			auto tile = m_layer->tileAt(Vec2(x, y));
			if (tile && tile->getBoundingBox().intersectsRect(m_finger->GetBoundingBox()) == true)
			{
				tile->setColor(Color3B::MAGENTA);
			}
		}
	}

}

