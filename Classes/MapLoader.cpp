#include "stdafx.h"
#include "MapLoader.h"

void MapLoader::PrintMap(const string& fileDir)
{
	m_map = TMXTiledMap::create(fileDir);
	m_targetLayer->addChild(m_map, 0);
}
