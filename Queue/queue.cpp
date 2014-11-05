#include <cstddef>
#include <iostream>
using namespace std;

class Node 
{
public:
	Node(int d)
	{
		next = NULL;
		data = d;
	}
	int getData(){ return this->data; }
	int getPosition(){ return position; }
	Node* getNext() { return this->next; }
	void setData(int d){ data = d; }
	void setPosition(int p){ position = p; }
	void setNext(Node* pointTo){ this->next = pointTo; }
private:
	Node* next;
	int data;
	int position; 
};
class Queue 
{
public:
	Node* conductor;
	//Queue(Node* nodeOne)
	Queue(int data)
	{
		Node* nodeSet = new Node(data);
		node1 = nodeSet;
		conductor = nodeSet;
	}
	void traverse()
	{
		posCount = 1;
		Node* temp = conductor;
		while (conductor != NULL)
		{
			conductor->setPosition(posCount);
			cout << "Pos is: " << conductor->getPosition() << 
				" for: " << conductor->getData()<< endl;
			conductor = conductor->getNext();
			posCount++;
		}
		conductor = temp;
	}
	//void push(Node* nodeSet)
	void push(int data)
	{
		Node* nodeSet = new Node(data);
		nodeSet->setNext(conductor);
		conductor = nodeSet;
	}
	void pop()
	{
		Node* temp = conductor;
		int i = size() - 1;
		while (conductor->getPosition() < i)
		{
			conductor = conductor->getNext();
		}
		conductor->setNext(NULL);
		conductor = temp;
	}
	int size()
	{
		Node* temp = conductor;
		int i = 1;
		while(conductor != NULL)
		{
			i++;
			conductor = conductor->getNext();
			if (conductor->getNext() == NULL)
			{
				conductor = temp;
				return i;
			}
		}
	}
	Node* back()
	{
		return conductor;	
	}
	Node* front()
	{
		Node* temp = conductor;
		while(conductor != NULL)
		{
			conductor = conductor->getNext();
			if (conductor->getNext() == NULL)
			{
				return conductor;
			}
		}
		conductor = temp;
	}
private:
	int posCount;
	Node* node1;
};
int main()
{
	Queue nodes(11);
	nodes.push(25);
	nodes.push(36);
	nodes.traverse();
	return 0;
}
