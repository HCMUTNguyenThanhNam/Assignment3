#pragma once
#include"Graph.h"
#include"InputReader.h"
#include<vector>

class DistanceNode
{
public:
	Vertex* Prev;
	Vertex* Cur;
	int Distance;
	DistanceNode(Vertex* Cur);
	DistanceNode(Vertex* Pre, Vertex* Cur, int Distance);
};

class EdgeW :public Edge
{
public:
	int distance;
	EdgeW();
	EdgeW(Vertex* _destination, int _distance);
};

class GraphW : public Graph
{
public:
	void Shortest_path_E18();

	void Shortest_path_E19();
};