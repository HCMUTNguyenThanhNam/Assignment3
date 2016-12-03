#pragma once
#include"Graph.h"
#include"InputReader.h"
#include<vector>

class ExGraph:public Graph
{
public:
	ExGraph();
	~ExGraph();

	/*
	* Exercise E5. print Graph
	*/
	void PrintGraph_E5();

	/*
	*	E6: Deltete vertex
	*/
	void DeleteVertex_E6();

	/*
	*	E11: Graph to Matrix
	*/
	void GraphToMatrix_E11();
	int** GraphToMatrix();
	void PrintMatrix(int**);

	/*
	*	E14: Total cycle in the graph
	*/
	void FindCycleFromVertex(Vertex* tmpVertex, int& numCycle, const int StartData);

	void Cycle_E14();

	/*
	E16: Check graph have strongly connected
	*/
	bool AllVetexProcessed();

	void DFS(Vertex* SourceVertex);

	void CheckStronglyConnected_E16();

	/*
		E20: Determine 2 graph have isomorphic
	*/
	bool Isomorphic(int** matrix1, int** matrix2, int* arrPermutation, int size);

	void checkIsomorphic_E20();
};

