#pragma once

class MapLoader
{
public:
	void SetLayer(Layer* layer) { m_targetLayer = layer; }
	void PrintMap();

private:
	Layer* m_targetLayer;
};