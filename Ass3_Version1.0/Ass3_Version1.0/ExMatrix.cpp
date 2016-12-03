#include "ExMatrix.h"

/*
*	Function of class NodeTree
*/
NodeTree::NodeTree()
{
	data = -1;
	pLeft = pRight = NULL;
}

NodeTree::NodeTree(int _data)
{
	data = _data;
	pLeft = pRight = NULL;
}

/*
*	Function of class Tree
*/
Tree::Tree()
{
	root = NULL;
}

Tree::Tree(NodeTree* _root)
{
	root = _root;
}

//void Tree::AddNode(NodeTree* Subroot, NodeTree* newNode)
//{
//	if (Subroot == NULL)
//		Subroot = newNode;
//	else if (Subroot->data < newNode->data)
//		AddNode(Subroot->pRight, newNode);
//	else if (Subroot->data > newNode->data)
//		AddNode(Subroot->pLeft, newNode);
//}7

/*
*	Function of class ExMatrix
*/

ExMatrix::ExMatrix()
{
}

ExMatrix::~ExMatrix()
{
}

/*
*	E15: chuyen tu ma tran lien ke sang graph
*/
Graph* ExMatrix::MatrixToGraph(int** Matrix, int size)
{
	//Convert Matrix to Graph
	Graph* graph = new Graph();
	//insert vertex
	for (int i = 0; i < size; i++)
		graph->InsertVertex(i + 1);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Matrix[i][j])
			{
				graph->InsertEdge(i + 1, j + 1);
			}
		}
	}
	return graph;
}

void ExMatrix::MatrixToGraph_E15()
{
	//read file
	int** Matrix, size;
	ReadAdjacencyMat("input/E15.txt", Matrix, size);

	//print matrix
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}
	Graph* graph = MatrixToGraph(Matrix, size);
	graph->Print();
}

/*
*	E17: Kiem tra xem mot ma tran lien ke co phai la mot cay AVL hay khong
*/


int E17::checkheight(Node*root) {
	if (root == NULL)return 0;
	int hleft = checkheight(root->left);
	int hright = checkheight(root->right);
	if (hleft > hright) {
		if (hleft - hright > 1)return -2;
		else return hleft + 1;
	}
	else {
		if (hright - hleft > 1)return -2;
		else return hright + 1;
	}
}
bool E17::CheckBST(Node*root) {
	{
		static class Node *prev = NULL;
		// traverse the tree in inorder fashion and keep track of prev node
		if (root)
		{
			if (!CheckBST(root->left))
				return false;

			// Allows only distinct valued nodes 
			if (prev != NULL && root->data <= prev->data)
				return false;

			prev = root;

			return CheckBST(root->right);
		}

		return true;
	}
}
int E17::countEdge() {
	int count = 0;
	Vertex*vtemp = gHead;
	while (vtemp != NULL) {
		Edge *etemp = vtemp->firstEdge;
		while (etemp != NULL) {
			count++;
			etemp = etemp->nextEdge;
		}
		vtemp = vtemp->nextVertex;
	}
	return count;
}
bool E17::findroot() {
	int size = 0;
	int s[50];
	Vertex*vtemp = gHead;
	while (vtemp != NULL) {
		Edge *etemp = vtemp->firstEdge;
		while (etemp != NULL) {
			if (vroot == NULL) vroot = etemp->destination;
			if (etemp->destination == vroot) {
				s[size] = vroot->data;
				size++;
				vroot = vtemp;
				vtemp = gHead;
				int n = 0;
				for (int i = 0; i < size; i++) {
					if (vroot->data == s[i]) n++;
				}
				if (n > 1) return true;
			}
			etemp = etemp->nextEdge;
		}
		vtemp = vtemp->nextVertex;
	}
	if (vroot != NULL) return true;
	else return false;
}
void E17::buildConnected(Vertex*vroot) {
	if (vroot->processed == 1) return;
	if (vroot == NULL)return;
	vroot->processed = 1;
	Edge *etemp = vroot->firstEdge;
	while (etemp != NULL) {
		buildConnected(etemp->destination);
		etemp = etemp->nextEdge;
	}
}
int E17::checkConnected() {
	int n = 0;
	Vertex*vtemp = gHead;
	while (vtemp != NULL) {
		if (vtemp->processed == 1) n++;
		vtemp = vtemp->nextVertex;
	}
	return n;
}
Node* E17::buildAVL(Node*root, Vertex*vroot) {
	if (vroot == NULL)return root;
	Node*newnode = new Node();
	newnode->data = vroot->data;
	if (root == NULL) {
		root = newnode;
	}
	if (vroot->firstEdge != NULL) {
		if (vroot->firstEdge->nextEdge == NULL) {
			if (vroot->firstEdge->destination->data < vroot->data) root->left = buildAVL(root->left, vroot->firstEdge->destination);
			else root->right = buildAVL(root->right, vroot->firstEdge->destination);
		}
		if (vroot->firstEdge->nextEdge != NULL) {
			root->left = buildAVL(root->left, vroot->firstEdge->destination);
			root->right = buildAVL(root->right, vroot->firstEdge->nextEdge->destination);
		}
	}
	return root;
}
//void E17::E17_MatrixIsAVL() {
//	int** Matrix, size;
//	ReadAdjacencyMat("input/E17.txt", Matrix, size);
//
//	//print matrix
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//			cout << Matrix[i][j] << " ";
//		cout << endl;
//	}
//
//	//Convert Matrix to Graph
//	//E17* graph = new E17();
//	//insert vertex
//	for (int i = 0; i < size; i++)
//		InsertVertex(i + 1);
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (Matrix[i][j])
//			{
//				InsertEdge(i + 1, j + 1);
//			}
//		}
//	}
//	if ((findroot() == true)) {// find root of AVL tree
//		buildConnected(vroot);
//		if (checkConnected() == countEdge() + 1) {// check if number edge from root=number edge of graph
//			root = buildAVL(root, vroot);// build graph to AVL tree
//			if ((checkheight(root)>0)// check balance height
//				&& (CheckBST(root) == true)) {// check binary search tree
//				root->PrintNode();
//			}
//			else cout << "khong phai cay AVL";
//		}
//		else cout << "khong phai cay AVL";
//	}
//	else cout << "khong phai cay AVL";
//}

void E17_MatrixIsAVL() {
	int** Matrix, size;
	ReadAdjacencyMat("input/E17.txt", Matrix, size);

	//print matrix
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}

	//Convert Matrix to Graph
	E17* graph = new E17();
	//insert vertex
	for (int i = 0; i < size; i++)
		graph->InsertVertex(i + 1);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Matrix[i][j])
			{
				graph->InsertEdge(i + 1, j + 1);
			}
		}
	}
	if ((graph->findroot() == true)) {// find root of AVL tree
		graph->buildConnected(graph->vroot);
		if (graph->checkConnected() == graph->countEdge() + 1) {// check if number edge from root=number edge of graph
			graph->root = graph->buildAVL(graph->root, graph->vroot);// build graph to AVL tree
			if ((graph->checkheight(graph->root)>0)// check balance height
				&& (graph->CheckBST(graph->root) == true)) {// check binary search tree
				graph->root->PrintNode();
			}
			else cout << "khong phai cay AVL";
		}
		else cout << "khong phai cay AVL";
	}
	else cout << "khong phai cay AVL";
}