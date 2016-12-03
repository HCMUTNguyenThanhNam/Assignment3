#include"ExHeap.h"

ExHeap::ExHeap()
{
}

ExHeap::~ExHeap()
{
}

/*
*  E4: Thao tac co ban voi Heap (Insert)
*/
void ExHeap::InsertHeap_E4()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter arr[" << i << "]: ";
		cin >> arr[i];
	}
	Heap heap = ArrayToHeap(arr, n);
	cout << endl << "Heap Tree: \n";
	heap.PrintHeapTree();
}

/*
*  E8: Tinh trong so cua cay theo chieu cao
*/
void ExHeap::WeightedHeap_E8()
{
	// read file
	int* arr, count;
	ReadArrayInput("input/E8.txt", arr, count);
	Heap heap = ArrayToHeap(arr, count);
	heap.PrintHeapTree();
	int idx = 1, j=0 ,total = 0;
	for (int i = 0; i < count; i++)
	{
		total += heap[i];
		if(i + 1 >= idx || i==count-1)
		{
			cout << total << endl;
			total = 0;
			j++;
			idx = idx + pow(2,j);
		}
	}
}

/*
*	E10: Chuyen mot Heap sang Graph
*/
void ExHeap::HeapToGraph_E10() {
	int *arr;
	int count;
	ReadArrayInput("input/E10.txt", arr, count);
	Heap NewHeap = ArrayToHeap(arr, count);
	NewHeap.PrintHeapTree();
	Graph NewGraph;
	for (int i = 0; i < count; i++) {
		NewGraph.InsertVertex(NewHeap[i]);
	}
	for (int i = count - 1; i >0; i--) {
		NewGraph.InsertEdge(NewHeap[(i - 1) / 2], NewHeap[i]);
		NewGraph.InsertEdge(NewHeap[i], NewHeap[(i - 1) / 2]);
	}
	NewGraph.Print();
}

/*
*	E13: Chuyen mot Heap sang mot matran lien ke
*/
void ExHeap::HeapToMatrix_E13()
{
	int *arr;
	int count;
	ReadArrayInput("input/E13.txt", arr, count);
	Heap NewHeap = ArrayToHeap(arr, count);
	NewHeap.PrintHeapLinear();
	//NewHeap.PrintHeapTree();
	int**mat = new int*[count + 1];
	for (int i = 0; i <= count; i++) mat[i] = new int[count + 1];
	for (int i = 0; i <= count; i++)
		for (int j = 0; j <= count; j++) {
			if (j != 0) mat[0][j] = NewHeap[j - 1];
			if (i != 0) mat[i][0] = NewHeap[i - 1];
			if ((i != j) && (((i - 2) / 2 == j - 1) || ((j - 2) / 2 == i - 1))) mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	for (int i = 0; i <= count; i++) {
		for (int j = 0; j <= count; j++) {
			if ((i != 0) || (j != 0))
				cout << left << setw(5) << mat[i][j];
			else
				cout << setw(5) << " ";
		}
		cout << endl;
	}
}