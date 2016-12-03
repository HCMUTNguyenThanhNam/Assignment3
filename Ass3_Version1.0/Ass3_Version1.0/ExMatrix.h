#pragma once
#include"InputReader.h"
#include"Graph.h"
#include"Node.h"
#include<vector>
class NodeTree
{
public:
	int data;
	NodeTree* pLeft;
	NodeTree* pRight;
	NodeTree();
	NodeTree(int _data);
};

class Tree
{
public:
	NodeTree* root;
	Tree();
	Tree(NodeTree* _root);
	//void AddNode(NodeTree* Subroot, NodeTree* newNode);
};

class ExMatrix
{
public:
	ExMatrix();
	~ExMatrix();

	/*
	*	E15: chuyen tu ma tran lien ke sang graph
	*/
	Graph* MatrixToGraph(int** Matrix, int size);
	void MatrixToGraph_E15();
};

/*
*	E17: Kiem tra xem mot ma tran lien ke co phai la mot cay AVL hay khong
*/
class E17 :public Graph {
public:
	Node* root;
	Vertex*vroot;
	int countEdge();
	bool findroot();
	void buildConnected(Vertex*vroot);
	int checkConnected();
	Node* buildAVL(Node *root, Vertex*vroot);
	int checkheight(Node*root);
	bool CheckBST(Node*root);
	//void E17_MatrixIsAVL();
};

void E17_MatrixIsAVL();