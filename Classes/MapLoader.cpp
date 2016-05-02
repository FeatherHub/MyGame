#include "stdafx.h"
#include "MapLoader.h"

void MapLoader::PrintMap()
{
	m_map = TMXTiledMap::create("map.tmx");
	m_targetLayer->addChild(m_map, 0);
}
