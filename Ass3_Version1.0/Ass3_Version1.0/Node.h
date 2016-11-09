#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>

enum Balance { LEFT, EQUAL, RIGHT };
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Balance balance;
	Node();
	Node(int);
	void PrintNode(int indent = 0);
	bool HasNode(int nodeData);
};

#endif