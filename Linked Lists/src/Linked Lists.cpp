//============================================================================
// Name        : Linked.cpp
// Author      : Bennet Leff
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node * next;

};

Node *makeNode(int nodeData, Node *nextNode) {
	Node *Node1;
	Node1 = new Node;
	Node1 -> data = nodeData;
	Node1 -> next = nextNode;
	return Node1;
}

int main() {
	Node *root;
	Node *conductor;
	Node *node3;
	Node *node4;
	root = new Node;
	root = makeNode(5, node3);
	node3 = new Node;
	node3 = makeNode(17, node4);
	node4 = new Node;
	node4 = makeNode(50, 0);
	node3 -> next = node4;
	node3 -> data = 17;
	node4 -> data = 50;
	node4 -> next = 0;
	//root -> next = node3;
	//root -> data = 5;
	conductor = root;
	if (conductor != 0) {
		while (conductor->next != 0) {
			conductor = conductor->next;
		}
	}
	conductor-> next = new Node;
	conductor = conductor -> next;
	conductor -> next = 0;
	conductor -> data = 42;
	conductor = root;
	if (conductor != 0) {
			while (conductor->next != 0) {
				cout << conductor -> data << endl;
				conductor = conductor->next;
			}
			cout << conductor-> data;
		}


	return 0;
}
