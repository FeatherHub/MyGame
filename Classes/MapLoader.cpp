#include "stdafx.h"
#include "MapLoader.h"

void MapLoader::PrintMap()
{
	auto map = TMXTiledMap::create("map.tmx");
	m_targetLayer->addChild(map, 0);
}
