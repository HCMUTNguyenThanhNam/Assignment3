#pragma once
#include"InputReader.h"
#include"Heap.h"
#include"Graph.h"
#include"iomanip"
class ExHeap:public Heap
{
public:
	ExHeap();
	~ExHeap();

	/*
	*  E4: Thao tac co ban voi Heap (Insert)
	*/
	void InsertHeap_E4();

	/*
	*  E8: Tinh trong so cua cay theo chieu cao
	*/
	void WeightedHeap_E8();

	/*
	*	E10: Chuyen mot Heap sang Graph
	*/
	void HeapToGraph_E10();

	/*
	*	E13: Chuyen mot Heap sang mot matran lien ke
	*/
	void HeapToMatrix_E13();
};
