#pragma once

class MapLoader
{
public:
	void SetLayer(Layer* layer) { m_targetLayer = layer; }
	void PrintMap(const string& fileDir);
	TMXTiledMap* GetMap() { return m_map; }
private:
	Layer* m_targetLayer;
	TMXTiledMap* m_map;
};