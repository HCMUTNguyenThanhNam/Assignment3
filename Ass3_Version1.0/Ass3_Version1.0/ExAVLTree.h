#pragma once
#include"AVLTree.h"
#include"InputReader.h"
#include"ExGraph.h"
class ExAVLTree:public AVLTree
{
public:
	ExAVLTree();
	~ExAVLTree();

	
	/*
	*	E1: Insert to AVL Tree
	*/
	void InsertAVLTree_E1();

	/*
	*	E2: Delete node of AVL Tree
	*/
	void DelNodeAVL_E2();

	/*
	*	E3: Dem so chan/le/so nguyen to co trong cay AVL
	*/
	bool Prime(int);
	void Approval_AVL(Node *, int&, int&, int&);
	void Count_EvenOddPrime_E3();

	/*
	*  E7: Tinh trong so cua cay AVL theo chieu cao
	*/

	// Ham tra ve chieu cao cua 1 node tinh tu node goc (node goc co chieu cao la 0)
	// Doi so truyen vao la root & data cua node can tim
	int Height_of_Node(int,Node*);

	// Ham tra ve chieu cao cua cay
	// Doi so truyen vao la root
	int Height_of_Tree(Node*);

	void E7(int*&, Node*);

	void print_result_E7();

	/*
	* E9: Chuyen mot cay AVL sang Graph
	*/
	void ConvertAVLtoGraph(Node*, ExGraph*&);
	ExGraph* AVLtoGraph();
	void AVLtoGraph_E9();

	/*
	*  E12: Chuyen AVLTree ve mot ma tran lien ke 
	*/
	void AVLtoMatrix_E12();
};

