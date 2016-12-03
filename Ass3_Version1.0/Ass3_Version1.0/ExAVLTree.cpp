#include "ExAVLTree.h"

ExAVLTree::ExAVLTree()
{
}

ExAVLTree::~ExAVLTree()
{
}

/*
*	E1: Insert AVLTree
*/
void  ExAVLTree::InsertAVLTree_E1() {
	int n;
	cout << "number of array : " << endl;;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "arr[" << i << "]= ";
		cin >> arr[i];
		cout << endl;
	}
	root= ArrayToAVL(arr, n).root;
	PrintAVL();
	delete[] arr;
}

/*
*	E2: Delete node of AVL Tree
*/
void ExAVLTree::DelNodeAVL_E2()
{
	int *Arr;
	int count;
	ReadArrayInput("input/E2.txt", Arr, count);
	root = ArrayToAVL(Arr, count).root;
	PrintAVL();
	delete[] Arr;
	int choose;
	do {
		cout << "Please enter number of node you want delete: ";
		cin >> choose;
		if (choose == -1) break;
		AVLDelete(choose);
		cout << "AVLTree after you delete node number " << choose << " : " << endl;
		PrintAVL();
	} while (choose != -1);
}

/*
*	E3: Dem so nut chan, nut le, so nguyen to co trong cay AVL
*/
bool ExAVLTree::Prime(int number)
{
	if (number < 2)
	{
		return false;
	}
	else if (number > 2)
	{
		if (number % 2 == 0)
		{
			return false;
		}
		for (int i = 3; i < sqrt((float)number); i += 2)
		{
			if (number%i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void ExAVLTree::Approval_AVL(Node *Root, int &EvenNode, int &OddNode, int &PrimeNumber)
{
	if (Root != NULL)
	{
		Approval_AVL(Root->left, EvenNode, OddNode, PrimeNumber);
		if (Root->data % 2 == 0)
			EvenNode++;
		else
			OddNode++;
		if (Prime(Root->data))
			PrimeNumber++;
		Approval_AVL(Root->right, EvenNode, OddNode, PrimeNumber);
	}
}

void ExAVLTree::Count_EvenOddPrime_E3()
{
	int *arr, count = 0, EvenNode = 0, OddNode = 0, PrimeNumber = 0;
	ReadArrayInput("input/E3.txt", arr, count);
	root = ArrayToAVL(arr, count).root;
	Approval_AVL(root, EvenNode, OddNode, PrimeNumber);
	cout << "\neven number of AVL  : " << EvenNode << endl;
	cout << "\nodd number of AVL   : " << OddNode << endl;
	cout << "\nprime number of AVL : " << PrimeNumber << endl;
}

/*
*  E7: Tinh trong so cua cay AVL theo chieu cao
*/
int ExAVLTree::Height_of_Node(int data, Node* subRoot)
{
	if (subRoot->data == data)
		return 0;
	if (subRoot->data > data)
	{
		subRoot = subRoot->left;
		return Height_of_Node(data, subRoot) + 1;
	}
		
	else if (subRoot->data < data)
	{
		subRoot = subRoot->right;
		return Height_of_Node(data, subRoot) + 1;
	}
}

int ExAVLTree::Height_of_Tree(Node* subRoot)
{
	if (subRoot == NULL)
		return 0;
	int left_height = Height_of_Tree(subRoot->left);
	int right_height = Height_of_Tree(subRoot->right);
	return (left_height>right_height)?left_height+1:right_height+1;
}

void ExAVLTree::E7(int*& result,Node* subRoot)
{
	if (subRoot == NULL)
		return;
	result[Height_of_Node(subRoot->data, root)] += subRoot->data;
	E7(result,subRoot->left);
	E7(result,subRoot->right);
}

void ExAVLTree::print_result_E7()
{
	// read file
	int* arr,count;
	ReadArrayInput("input/E7.txt", arr, count);
	root = ArrayToAVL(arr, count).root;
	PrintAVL();

	int height_of_AVLtree = Height_of_Tree(root);
	int* arrResult = new int[height_of_AVLtree];
	for (int i = 0; i < height_of_AVLtree; i++)
		arrResult[i] = 0;
	Node* tmp = root;
	E7(arrResult, tmp);
	for (int i = 0; i < height_of_AVLtree; i++)
		cout << arrResult[i] << endl;
}

/*
* E9: Chuyen mot cay AVL sang Graph
*/
void ExAVLTree::ConvertAVLtoGraph(Node* SubrootAVL, ExGraph*& _Graph)
{
	if (SubrootAVL == NULL)
		return;
	if (!_Graph->VertexExist(SubrootAVL->data))
	{
		_Graph->InsertVertex(SubrootAVL->data);
		if (SubrootAVL->left != NULL)
			_Graph->InsertEdge(SubrootAVL->data, SubrootAVL->left->data);
		if (SubrootAVL->right != NULL)
			_Graph->InsertEdge(SubrootAVL->data, SubrootAVL->right->data);
	}
	else //Can co else vi ham InsertEdge co the them Vertex neu data "to" chua co.
	{
		Vertex* tmpVertex = _Graph->gHead;
		while (tmpVertex != NULL)
		{
			if (tmpVertex->data == SubrootAVL->data)
				break;
			tmpVertex = tmpVertex->nextVertex;
		}
		Edge* tmpEdge = tmpVertex->firstEdge;
		// Check data of node left of subroot
		if (SubrootAVL->left != NULL)
		{
			bool flag = true;
			while (tmpEdge != NULL)
			{
				if (tmpEdge->destination->data == SubrootAVL->left->data)
				{
					flag = false;
					break;
				}
				tmpEdge = tmpEdge->nextEdge;
			}
			if (flag)
				_Graph->InsertEdge(SubrootAVL->data, SubrootAVL->left->data);
		}
		//Check data of node right of subroot
		tmpEdge = tmpVertex->firstEdge;
		if (SubrootAVL->right != NULL)
		{
			bool flag = true;
			while (tmpEdge != NULL)
			{
				if (tmpEdge->destination->data == SubrootAVL->right->data)
				{
					flag = false;
					break;
				}
				tmpEdge = tmpEdge->nextEdge;
			}
			if (flag)
				_Graph->InsertEdge(SubrootAVL->data, SubrootAVL->right->data);
		}
	}
	ConvertAVLtoGraph(SubrootAVL->left, _Graph);
	ConvertAVLtoGraph(SubrootAVL->right, _Graph);
}

ExGraph* ExAVLTree::AVLtoGraph()
{
	PrintAVL();
	ExGraph* _Graph = new ExGraph();
	ConvertAVLtoGraph(root, _Graph);
	return _Graph;
}

void ExAVLTree::AVLtoGraph_E9()
{
	// read file
	int* arr, count;
	ReadArrayInput("input/E9.txt", arr, count);
	root = ArrayToAVL(arr, count).root;
	ExGraph* graph = AVLtoGraph();
	graph->Print();
}


/*
*	E12: Chuyen mot AVL tree sang mot ma tran lien ke
*/
void ExAVLTree::AVLtoMatrix_E12()
{
	// read file
	int* arr, count;
	ReadArrayInput("input/E12.txt", arr, count);
	root = ArrayToAVL(arr, count).root;
	//PrintAVL();
	ExGraph* GraphofAVL = AVLtoGraph();
	int** Matrix = GraphofAVL->GraphToMatrix();
	GraphofAVL->PrintMatrix(Matrix);
}