#include "EdgeW.h"

DistanceNode::DistanceNode(Vertex* current)
{
	Prev = NULL;
	Cur = current;
	Distance = 0;
}

DistanceNode::DistanceNode(Vertex* pre, Vertex* cur, int Dis)
{
	Prev = pre;
	Cur = cur;
	Distance = Dis;
}

EdgeW::EdgeW() :Edge(NULL)
{
	distance = -1;
}
EdgeW::EdgeW(Vertex* _destination, int _distance) : Edge(_destination)
{
	distance = _distance;
}

void GraphW::Shortest_path_E18()
{
	//read file
	int** Matrix, size;
	ReadAdjacencyMat("input/E18.txt", Matrix, size);

	//Create Graph from matrix
	for (int i = 0; i < size; i++)
		InsertVertex(i + 1);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Matrix[i][j] != 0)
			{
				EdgeW* newEdgeW = new EdgeW(GetVertex(j + 1), Matrix[i][j]);
				InsertEdge(GetVertex(i + 1), (Edge*)newEdgeW);
			}
		}
	}
	//Print_GraphW();

	// Enter from vertex and to vertex
	int from, to;
	
	do
	{
		cout << "\nNhap dinh xuat phat [1-" << size << "]: ";
		cin >> from;
		if (from<1 || from>size)
			cout << "Nhap khong hop le. Vui long nhap lai.";
	} while (from<1 || from>size);

	do
	{
		cout << "\nNhap dinh dich [1-" << size << "]: ";
		cin >> to;
		if (to<1 || to>size)
			cout << "Nhap khong hop le. Vui long nhap lai.";
	} while (to<1 || to>size);

	//Get Vetex has data equal  from
	Vertex* VertexSource = GetVertex(from);

	vector<DistanceNode*> ListProcessed, ListUnprocessed;

	//Set Vertex was processed
	ListProcessed.push_back(new DistanceNode(VertexSource));
	VertexSource->processed = true;

	//push all DistanceNode to ListUnprocessed. They are destination's edges
	EdgeW* tmpEdgeW = (EdgeW*)VertexSource->firstEdge;
	while (tmpEdgeW != NULL)
	{
		DistanceNode* tmpNode = new DistanceNode(VertexSource, tmpEdgeW->destination, tmpEdgeW->distance);
		ListUnprocessed.push_back(tmpNode);
		tmpEdgeW = (EdgeW*)tmpEdgeW->nextEdge;
	}

	bool  FindPath = true;
	while (!GetVertex(to)->processed)
	{
		if (ListUnprocessed.size() == 0)
		{
			FindPath = false;
			break;
		}

		//find shotest distance on List unprocessed
		DistanceNode* Min = ListUnprocessed[0];
		int position = 0;
		for (int i = 1; i < (int)ListUnprocessed.size(); i++)
		{
			if (ListUnprocessed[i]->Distance < Min->Distance)
			{
				Min = ListUnprocessed[i];
				position = i;
			}
		}

		ListProcessed.push_back(Min);
		GetVertex(Min->Cur->data)->processed = true;
		ListUnprocessed.erase(ListUnprocessed.begin() + position);

		Vertex* tmpVertex = GetVertex(Min->Cur->data);
		EdgeW* tmpEdge = (EdgeW*)tmpVertex->firstEdge;
		while (tmpEdge != NULL)
		{
			if (!tmpEdge->destination->processed)
			{
				//Check tmpEdge->Destination has been ListUnprocessed
				bool check = false;
				for (int i = 0; i < (int)ListUnprocessed.size(); i++)
				{
					if (ListUnprocessed[i]->Cur == tmpEdge->destination)
					{
						check = true;
						int totalDistance = tmpEdge->distance + Min->Distance;
						if (totalDistance < ListUnprocessed[i]->Distance)
						{
							ListUnprocessed[i]->Prev = tmpVertex;
							ListUnprocessed[i]->Distance = totalDistance;
						}
						break;
					}
				}
				if (!check)
				{
					DistanceNode* tmpNode = new DistanceNode(tmpVertex, tmpEdge->destination, tmpEdge->distance + Min->Distance);
					ListUnprocessed.push_back(tmpNode);
				}
			}
			tmpEdge = (EdgeW*)tmpEdge->nextEdge;
		}
	}
	//Print path
	if (!FindPath)
		cout << "\nKhong tim thay duong di tu " << from << " den " << to;
	else
	{
		cout << "\nDuong di ngan nhat tu " << from << " den " << to << ":\t";
		vector<int> ListPath;
		for (int i = 0; i < (int)ListProcessed.size(); i++)
		{
			if (ListProcessed[i]->Cur->data == to)
			{
				ListPath.push_back(ListProcessed[i]->Cur->data);
				if (ListProcessed[i]->Prev != NULL)
					to = ListProcessed[i]->Prev->data;
				else
					break;
				i = -1;
			}
		}
		for (int i = ListPath.size() - 1; i > -1; i--)
		{
			cout << ListPath[i];
			if (i != 0)
				cout << " --> ";
		}
	}
}

void GraphW::Shortest_path_E19()
{
	int** Matrix, size;
	ReadAdjacencyMat("input/E19.txt", Matrix, size);

	//Create Graph from matrix
	for (int i = 0; i < size; i++)
		InsertVertex(i + 1);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Matrix[i][j] != 0)
			{
				EdgeW* newEdgeW = new EdgeW(GetVertex(j + 1), Matrix[i][j]);
				InsertEdge(GetVertex(i + 1), (Edge*)newEdgeW);
			}
		}
	}
	Print();

	//Enter from Vertex, to Vertex and excepted Vertex
	int from, to, len, *arr_ExVertex;
	do
	{
		cout << "\nNhap dinh xuat phat [1-" << size << "]: ";
		cin >> from;
		if (from<1 || from>size)
			cout << "Nhap khong hop le. Vui long nhap lai.";
	} while (from<1 || from>size);
	do
	{
		cout << "\nNhap dinh dich [1-" << size << "]: ";
		cin >> to;
		if (to<1 || to>size)
			cout << "Nhap khong hop le. Vui long nhap lai.";
	} while (to<1 || to>size);
	do
	{
		cout << "Nhap so dinh can loai bo [1-" << size - 2 << "]:";
		cin >> len;
		if (len<0 || len>size - 2)
			cout << "Nhap khong hop le. Vui long nhap lai.";
	} while (len<0 || len>size - 2);
	arr_ExVertex = new int[len];
	for (int i = 0; i < len; i++)
	{
		do
		{
			cout << "\nNhap arr[" << i << "]: ";
			cin >> arr_ExVertex[i];
			if (arr_ExVertex[i] == from || arr_ExVertex[i] == to)
				cout << "Nhap khong hop le. Vui long nhap lai.";
		} while (arr_ExVertex[i] == from || arr_ExVertex[i] == to);

		//Find and set Excepted Verted in arr is processed
		GetVertex(arr_ExVertex[i])->processed = true;
	}

	vector<DistanceNode*> ListProcessed, ListUnprocessed;
	//Get Vetex has data equal  from
	Vertex* VertexSource = GetVertex(from);
	//Set Vertex was processed
	VertexSource->processed = true;
	ListProcessed.push_back(new DistanceNode(VertexSource));

	EdgeW* tmpEdgeW = (EdgeW*)VertexSource->firstEdge;
	while (tmpEdgeW != NULL)
	{
		if (!tmpEdgeW->destination->processed)
		{
			DistanceNode* tmpNode = new DistanceNode(VertexSource, tmpEdgeW->destination, tmpEdgeW->distance);
			ListUnprocessed.push_back(tmpNode);
		}
		tmpEdgeW = (EdgeW*)tmpEdgeW->nextEdge;
	}

	bool  FindPath = true;
	while (!GetVertex(to)->processed)
	{
		if (ListUnprocessed.size() == 0)
		{
			FindPath = false;
			break;
		}
		//find shotest distance
		DistanceNode* Min = ListUnprocessed[0];
		int position = 0;
		for (int i = 1; i < (int)ListUnprocessed.size(); i++)
		{
			if (ListUnprocessed[i]->Distance < Min->Distance)
			{
				Min = ListUnprocessed[i];
				position = i;
			}
		}
		ListProcessed.push_back(Min);
		GetVertex(Min->Cur->data)->processed = true;
		ListUnprocessed.erase(ListUnprocessed.begin() + position);

		Vertex* tmpVertex = GetVertex(Min->Cur->data);
		EdgeW* tmpEdge = (EdgeW*)tmpVertex->firstEdge;
		while (tmpEdge != NULL)
		{
			if (!tmpEdge->destination->processed)
			{
				//Check tmpEdge->Destination has been ListUnprocessed
				bool check = false;
				for (int i = 0; i < (int)ListUnprocessed.size(); i++)
				{
					if (ListUnprocessed[i]->Cur == tmpEdge->destination)
					{
						check = true;
						int totalDistance = tmpEdge->distance + Min->Distance;
						if (totalDistance < ListUnprocessed[i]->Distance)
						{
							ListUnprocessed[i]->Prev = tmpVertex;
							ListUnprocessed[i]->Distance = totalDistance;
						}
						break;
					}
				}
				if (!check)
				{
					DistanceNode* tmpNode = new DistanceNode(tmpVertex, tmpEdge->destination, tmpEdge->distance + Min->Distance);
					ListUnprocessed.push_back(tmpNode);
				}
			}
			tmpEdge = (EdgeW*)tmpEdge->nextEdge;
		}
	}
	//Print path
	if (!FindPath)
		cout << "\nKhong tim thay duong di tu " << from << " den " << to;
	else
	{
		cout << "\nDuong di ngan nhat tu " << from << " den " << to << ":\t";
		vector<int> ListPath;
		for (int i = 0; i < (int)ListProcessed.size(); i++)
		{
			if (ListProcessed[i]->Cur->data == to)
			{
				ListPath.push_back(ListProcessed[i]->Cur->data);
				if (ListProcessed[i]->Prev != NULL)
					to = ListProcessed[i]->Prev->data;
				else
					break;
				i = -1;
			}
		}
		for (int i = ListPath.size() - 1; i > -1; i--)
		{
			cout << ListPath[i];
			if (i != 0)
				cout << " --> ";
		}
	}
}