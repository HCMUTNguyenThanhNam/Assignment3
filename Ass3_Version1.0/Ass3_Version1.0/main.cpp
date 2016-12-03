#include"ExAVLTree.h"
#include"ExHeap.h"
#include"ExGraph.h"
#include"ExMatrix.h"
#include"EdgeW.h"

int  main()
{
	int choose;
	do
	{
		cout << "\n=================================== ASSIGNMENT 3 ==================================="
			<< "\nI. PHAN CO BAN:"
			<< "\n\tE1) Thao tac co ban voi AVL tree (insert)."
			<< "\n\tE2) Thao tac co ban voi AVLTree (delete)."
			<< "\n\tE3) Dem so nut le, chan, so nguyen to co trong cay AVL."
			<< "\n\tE4) Thao tac co ban voi Heap (Insert)."
			<< "\n\tE5) Thao tac co ban voi Graph (In graph)."
			<< "\n\tE6) Thao tac co ban voi Graph (Xoa Vertex)."
			<<"\nII. PHAN NANG CAO:"
			<< "\n\tE7) Tinh trong so cua cay AVL theo do cao."
			<< "\n\tE8) Tinh trong so cua Heap theo do cao."
			<< "\n\tE9) Chuyen mot cay AVL sang Graph."
			<< "\n\tE10) Chuyen mot Heap sang Graph."
			<< "\n\tE11) Chuyen mot Graph sang dang mot ma tran lien ke."
			<< "\n\tE12) Chuyen mot AVL Tree sang dang mot ma tran lien ke."
			<< "\n\tE13) Chuyen mot Heap sang dang ma tran lien ke."
			<< "\n\tE14) Dem tong so cac chu trinh co trong Graph."
			<< "\n\tE15) Chuyen tu ma tran lien ke sang Graph."
			<< "\n\tE16) Kiem tra xem mot Graph co lien thong manh hay khong."
			<< "\n\tE17) Kiem tra xem mot ma tran lien ke co phai la mot cay AVL hay khong."
			<< "\nIII. PHAN KET:"
			<< "\n\tE18) Tim duong di ngan nhat."
			<< "\n\tE19) Tim duong di ngan nhat (bien the)."
			<< "\n\tE20) Kiem tra do thi dang cau."
			<< "\n\n\tNhap -1 de thoat."
			<< "\nNhap lua chon cua ban: ";
		cin >> choose;
		switch (choose)
		{
		case 1: {
			ExAVLTree AVL;
			AVL.InsertAVLTree_E1();
			break;
		}
		case 2: {
			ExAVLTree AVL;
			AVL.DelNodeAVL_E2();
			break;
		}
		case 3: {
			ExAVLTree AVL;
			AVL.Count_EvenOddPrime_E3();
			break;
		}
		case 4: {
			ExHeap HEAP;
			HEAP.InsertHeap_E4();
			break;
		}
		case 5: {
			ExGraph GRAPH;
			GRAPH.PrintGraph_E5();
			break;
		}
		case 6: {
			ExGraph GRAPH;
			GRAPH.DeleteVertex_E6();
			break;
		}
		case 7: {
			ExAVLTree exAVL;
			exAVL.print_result_E7();
			break;
		}
		case 8: {
			ExHeap exHeap;
			exHeap.WeightedHeap_E8();
			break;
		}
		case 9: {
			ExAVLTree AVL;
			AVL.AVLtoGraph_E9();

			break;
		}
		case 10: {
			ExHeap HEAP;
			HEAP.HeapToGraph_E10();
			break;
		}
		case 11: {
			ExGraph GRAPH;
			GRAPH.GraphToMatrix_E11();
			break;
		}
		case 12: {
			ExAVLTree AVL;
			AVL.AVLtoMatrix_E12();
			break;
		}
		case 13: {
			ExHeap HEAP;
			HEAP.HeapToMatrix_E13();
			break;
		}
		case 14: {
			ExGraph GRAPH;
			GRAPH.Cycle_E14();
			break;
		}
		case 15:{
			ExMatrix MATRIX;
			MATRIX.MatrixToGraph_E15();
			break;
		}
		case 16: {
			ExGraph GRAPH;
			GRAPH.CheckStronglyConnected_E16();
			break;
		}
		case 17: {
			E17_MatrixIsAVL();
			break;
		}
		case 18: {
			GraphW GRAPH_W1;
			GRAPH_W1.Shortest_path_E18();
			break;
		}
		case 19: {
			GraphW GRAPH_W2;
			GRAPH_W2.Shortest_path_E19();
			break;
		}
		case 20: {
			ExGraph exGRAPH;
			exGRAPH.checkIsomorphic_E20();
			break;
		}
		default: {
			if(choose!=-1)
				cout << "Vui long kiem tra lai lua chon cua ban.";
			break;
		}
		}
		if(choose!=-1)
			system("pause>nul");
	} while (choose!=-1);
	
	system("pause");
	return 0;
}