#include "ExGraph.h"

ExGraph::ExGraph()
{
}
ExGraph::~ExGraph()
{
}


/*
* Exercise E5. print Graph
*/
void Graph::Print()
{
	Vertex* tmpVertex = gHead;
	while (tmpVertex != NULL)
	{
		cout << tmpVertex->data;
		Edge* tmpEdge = tmpVertex->firstEdge;
		while (tmpEdge != NULL)
		{
			cout << " -> " << tmpEdge->destination->data;
			tmpEdge = tmpEdge->nextEdge;
		}
		cout << " -> NULL\n|\n";
		tmpVertex = tmpVertex->nextVertex;
	}
	cout << "NULL";
}

void ExGraph::PrintGraph_E5()
{
	int *vertexDataArr, vertexCount, **edgeDataArr, edgeCount;
	ReadArrayInputOfGraph("input/E5.txt", vertexDataArr, vertexCount, edgeDataArr, edgeCount);
	for (int i = 0; i < vertexCount; i++)
		InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++)
		InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	Print();
}

/*
*	E6: Delete vertex
*/
bool Graph::RemoveVertex(int reData) {
	if (VertexExist(reData)) {
		Vertex *reVertex = GetVertex(reData);
		while (reVertex->firstEdge != NULL) {
			RemoveEdge(reVertex, reVertex->firstEdge->destination);
		}
		Vertex *vDelEdge = gHead;
		while (vDelEdge != NULL) {
			RemoveEdge(vDelEdge, reVertex);
			vDelEdge = vDelEdge->nextVertex;
		}
		if (reVertex == gHead) {
			gHead = gHead->nextVertex;
			delete reVertex;
			size--;
			return true;
		}
		else {
			Vertex *vTemp = gHead;
			Vertex*vTail = vTemp;
			while (vTemp != reVertex) {
				vTail = vTemp;
				vTemp = vTemp->nextVertex;
			}
			vTail->nextVertex = vTemp->nextVertex;
			size--;
			delete vTemp;
			return true;
		}
	}
	else return false;
	return true;
}

bool Graph::RemoveEdge(Vertex* from, Vertex* to) {
	if ((from->firstEdge == NULL) || (from->data == to->data)) return false;
	else {
		if (from->firstEdge->destination == to) {
			to->inDegree--;
			from->outDegree--;
			from->firstEdge = from->firstEdge->nextEdge;
			return true;
		}
		else {
			Edge *eTemp = from->firstEdge;
			Edge*eTail = eTemp;
			while (eTemp != NULL) {
				if (eTemp->destination == to) break;
				eTail = eTemp;
				eTemp = eTemp->nextEdge;
			}
			if (eTemp == NULL)
				return false;
			else {
				from->outDegree--;
				to->inDegree--;
				eTail->nextEdge = eTemp->nextEdge;
				return true;
			}
		}
	}
	return true;
}

bool Graph::RemoveEdge(int fromData, int toData) {
	Vertex* from = GetVertex(fromData);
	Vertex* to = GetVertex(toData);
	if ((VertexExist(fromData)) && (VertexExist(toData))) return RemoveEdge(from, to);
	else return false;
}

bool Graph::RemoveEdge(Vertex* from, Edge* from_to) {
	Vertex* to = from_to->destination;
	if (VertexExist(to->data)) return RemoveEdge(from, to);
	else return false;
}

void ExGraph::DeleteVertex_E6() {
	int *vertexDataArr, vertexCount,**edgeDataArr, edgeCount;
	ReadArrayInputOfGraph("input/E6.txt", vertexDataArr, vertexCount, edgeDataArr, edgeCount);
	for (int i = 0; i < vertexCount; i++)
		InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++)
		InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	Print();
	int choose = 0;
	while (choose != -1) {
		cout << "\nEnter vexter want to delete: ";
		cin >> choose;
		if (choose == -1)
			break;
		cout << endl;
		RemoveVertex(choose);
		if (gHead == NULL) {
			cout << "Graph is empty" << endl;
			break;
		}
		Print();
	}
}


/*
*	E11: Graph to Matrix
*/
void ExGraph::PrintMatrix(int** Matrix)
{
	cout << endl;
	//print Matrix
	for (int i = 0; i < size + 1; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			if (i == 0 && j == 0)
				cout << "   ";
			else if (i == 0 || j == 0)
			{
				if (Matrix[i][j] < 10)
					cout << " " << Matrix[i][j] << " ";
				else if (Matrix[i][j] < 100)
					cout << Matrix[i][j] << " ";
				else
					cout << Matrix[i][j];
			}
			else
				cout << " " << Matrix[i][j] << " ";
			cout << "  ";
		}
		cout << endl;
	}
}
int** ExGraph::GraphToMatrix()
{
	//create Matrix
	int** Matrix = new int*[size + 1];
	for (int i = 0; i < size + 1; i++)
		Matrix[i] = new int[size + 1];

	//set value for matrix = 0;
	for (int i = 0; i < size + 1; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			Matrix[i][j] = 0;
		}
	}

	//set value for col & row 1
	Vertex* tmpVertex = gHead;
	for (int i = 1; i < size + 1; i++)
	{
		Matrix[0][i] = Matrix[i][0] = tmpVertex->data;
		tmpVertex = tmpVertex->nextVertex;
	}

	//set value for Matrix
	tmpVertex = gHead;
	for (int i = 0; i < size; i++)
	{
		if (tmpVertex->firstEdge != NULL)
		{
			Edge* tmpEdge = tmpVertex->firstEdge;
			while (tmpEdge != NULL)
			{
				int row = 1, col = 1;
				for (; row < size + 1; row++)
					if (Matrix[row][0] == tmpVertex->data)
						break;
				for (; col < size + 1; col++)
					if (Matrix[0][col] == tmpEdge->destination->data)
						break;
				Matrix[row][col] = 1;
				tmpEdge = tmpEdge->nextEdge;
			}
		}
		tmpVertex = tmpVertex->nextVertex;
	}
	return Matrix;
}
void ExGraph::GraphToMatrix_E11()
{
	//read file
	int *vertexDataArr, vertexCount, **edgeDataArr, edgeCount;
	ReadArrayInputOfGraph("input/E11.txt", vertexDataArr, vertexCount, edgeDataArr, edgeCount);
	for (int i = 0; i < vertexCount; i++)
		InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++)
		InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);
	//print Graph
	Print();
	PrintMatrix(GraphToMatrix());
}

/*
*	E14: Total cycle in the graph
*/
void ExGraph::FindCycleFromVertex(Vertex* tmpVertex, int& numCycle, const int StartData)
{
	Edge* tmpEdge = tmpVertex->firstEdge;
	while (tmpEdge != NULL)
	{
		if (tmpEdge->destination->data == StartData)
			numCycle++;
		if (!tmpEdge->destination->processed)
		{
			tmpEdge->destination->processed = true;
			FindCycleFromVertex(tmpEdge->destination, numCycle, StartData);
			tmpEdge->destination->processed = false;
		}
		tmpEdge = tmpEdge->nextEdge;
	}
}

void ExGraph::Cycle_E14()
{
	//read file
	int *vertexDataArr, vertexCount, **edgeDataArr, edgeCount;
	ReadArrayInputOfGraph("input/E14.txt", vertexDataArr, vertexCount, edgeDataArr, edgeCount);
	for (int i = 0; i < vertexCount; i++)
		InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++)
		InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);

	Print();

	Vertex* processVertex = gHead;
	int numCycle = 0;
	while (processVertex != NULL)
	{
		processVertex->processed = true;
		FindCycleFromVertex(processVertex, numCycle, processVertex->data);
		processVertex = processVertex->nextVertex;
	}
	cout << "\nTong so chu trinh co trong Graph: " << numCycle;
}


/*
	E16: Check graph have strongly connected
*/

bool ExGraph::AllVetexProcessed()
{
	Vertex* tmp = gHead;
	while (tmp != NULL)
	{
		if (!tmp->processed)
			return false;
		tmp = tmp->nextVertex;
	}
	return true;
}

void ExGraph::DFS(Vertex* SourceVertex)
{
	if (SourceVertex != NULL && !SourceVertex->processed)
	{
		SourceVertex->processed = true;
		Edge* tmpEdge = SourceVertex->firstEdge;
		while (tmpEdge != NULL)
		{
			DFS(tmpEdge->destination);
			tmpEdge = tmpEdge->nextEdge;
		}
	}
}

void ExGraph::CheckStronglyConnected_E16()
{
	//read file
	int *vertexDataArr, vertexCount, **edgeDataArr, edgeCount;
	ReadArrayInputOfGraph("input/E16.txt", vertexDataArr, vertexCount, edgeDataArr, edgeCount);
	for (int i = 0; i < vertexCount; i++)
		InsertVertex(vertexDataArr[i]);
	for (int i = 0; i < edgeCount; i++)
		InsertEdge(edgeDataArr[i][0], edgeDataArr[i][1]);

	Print();
	
	Vertex* tmpVertex = gHead;
	while (tmpVertex != NULL)
	{
		DFS(tmpVertex);
		if (!AllVetexProcessed())
		{
			cout << "\nDo thi da cho KHONG phai la do thi lien thong manh";
			return;
		}
		//Set value all of processed of vertexs are false;
		Vertex* tmp = gHead;
		while (tmp != NULL)
		{
			tmp->processed = false;
			tmp = tmp->nextVertex;
		}
		tmpVertex = tmpVertex->nextVertex;
	}
	cout << "\nDo thi da cho LA do thi lien thong manh";
}

/*
E20: Determine 2 graph have isomorphic
*/

bool IsExist(int** edgeDataArr, int edgeCount, int from, int to)
{
	for (int i = 0; i < edgeCount; i++)
	{
		if (edgeDataArr[i][0] == from && edgeDataArr[i][1] == to)
			return true;
	}
	return false;
}

void readFile(int**& matrix1, int**& matrix2, int& size1, int& size2)
{
	int *vertexDataArr,**edgeDataArr, edgeCount;
	//read file
	ReadArrayInputOfGraph("input/E20a.txt", vertexDataArr, size1, edgeDataArr, edgeCount);
	
	//create dynamic memory for matrix1
	matrix1 = new int*[size1];
	for (int i = 0; i < size1; i++)
		matrix1[i] = new int[size1];

	//create data for matrix1
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			if (IsExist(edgeDataArr, edgeCount, vertexDataArr[i], vertexDataArr[j]))
				matrix1[i][j] = 1;
			else
				matrix1[i][j] = 0;
		}
	}

	//delete
	delete[] vertexDataArr;
	vertexDataArr = NULL;
	for (int i = 0; i < edgeCount; i++)
		delete[] edgeDataArr[i];
	delete[] edgeDataArr;

	ReadArrayInputOfGraph("input/E20b.txt", vertexDataArr, size2, edgeDataArr, edgeCount);
	
	//create dynamic memory for matrix1
	matrix2 = new int*[size2];
	for (int i = 0; i < size2; i++)
		matrix2[i] = new int[size2];

	//create data for matrix1
	for (int i = 0; i < size2; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (IsExist(edgeDataArr, edgeCount, vertexDataArr[i], vertexDataArr[j]))
				matrix2[i][j] = 1;
			else
				matrix2[i][j] = 0;
		}
	}

	//delete
	delete[] vertexDataArr;
	vertexDataArr = NULL;
	for (int i = 0; i < edgeCount; i++)
		delete[] edgeDataArr[i];
	delete[] edgeDataArr;
}

bool ExGraph::Isomorphic(int** matrix1, int** matrix2, int* arrPermutation, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix1[i][j] != matrix2[arrPermutation[i]][arrPermutation[j]])
				return false;
		}
	}
	return true;
}

void ExGraph::checkIsomorphic_E20()
{
	int** matrix1, **matrix2, size1, size2;
	readFile(matrix1, matrix2, size1, size2);

	//check size
	if (size1 != size2)
	{
		cout << "Two graphs aren't isomorphic";
		return;
	}

	//check degree
	int* degreeMatrix1 = new int[size1];
	for (int i = 0; i < size1; i++)
	{
		int idx = 0;
		for (int j = 0; j < size1; j++)
		{
			if (matrix1[i][j])
				idx++;
		}
		degreeMatrix1[i]=idx;
	}

	for (int i = 0; i < size2; i++)
	{
		int idx = 0;
		for (int j = 0; j < size2; j++)
		{
			if (matrix2[i][j])
				idx++;
		}
		for (int i = 0; i < size1; i++)
		{
			if (degreeMatrix1[i] == idx)
				degreeMatrix1[i] = -1;
		}
	}
	for (int i = 0; i < size1; i++)
	{
		if(degreeMatrix1[i]!=-1)
		{
			cout << "Two graphs aren't isomorphic";
			return;
		}
	}

	// create permutation
	int* arrPermutation = new int[size1];
	for (int i = 0; i < size1; i++)
		arrPermutation[i] = i;
	//check first permutation
	if (Isomorphic(matrix1, matrix2, arrPermutation, size1))
	{
		cout << "Two graphs are isomorphic";
		return;
	}

	int i = size1 - 1;// i la vi tri ma doan cuoi giam dan
	while (i>0)// trong khi doan cuoi khong phai bat dau tu vi tri dau tien
	{
		i = size1 - 1;
		while (arrPermutation[i] < arrPermutation[i - 1]) // tim vi tri dau tien ma doan cuoi giam dan
			i--;

		if (i>0)// Neu tim duoc i
		{
			int k;// tim so a[k] nho nhat trong doan giam dan ma a[k] > a[i-1]
			for (k = size1 - 1; k >= i; k--)
			{
				if (arrPermutation[k] > arrPermutation[i - 1])
					break;
			}
			swap(arrPermutation[k], arrPermutation[i - 1]);

			// dao nguoc doan cuoi giam dan thanh tang dan
			for (int k = i; k < i + (size1 - i) / 2; k++)
			{
				swap(arrPermutation[k], arrPermutation[size1 - 1 - k + i]);
			}
			if (Isomorphic(matrix1, matrix2, arrPermutation, size1))
			{
				cout << "Two graphs are isomorphic";
				return;
			}
		}
	}
	cout << "Two graphs aren't isomorphic";
	return;
}