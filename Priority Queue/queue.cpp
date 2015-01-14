#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;

class Node 
{
public:
	Node(int d)
	{
		next = NULL;
		data = d;
		priority = rand() % 50;
	}
	int getPriority() { return this-> priority; }
	int getData(){ return this->data; }
	int getPosition(){ return position; }
	Node* getNext() { return this->next; }
	void setPriority(int p) { priority = p; } 
	void setData(int d){ data = d; }
	void setPosition(int p){ position = p; }
	void setNext(Node* pointTo){ next = pointTo; }
private:
	Node* next;
	int data;
	int position; 
	int priority;
};
class Queue 
{
public:
	Node* conductor;
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
				" for: " << conductor->getData() << " and priority is: " 
				<< conductor->getPriority() << endl;
			conductor = conductor->getNext();
			posCount++;
		}
		conductor = temp;
	}
	void enqueue(int data)
	{
		Node* nodeSet = new Node(data);
		nodeSet->setNext(conductor);
		conductor = nodeSet;
	}
	void dequeue()
	{
		Node* temp = conductor;
		Node* greatest = conductor;
		
		while (conductor->getPosition() < size() - 1)
		{
			conductor = conductor->getNext();
			if (conductor->getPriority() > greatest->getPriority())
			{
				greatest = conductor;
			}
		}
		conductor = temp;
		while (conductor->getPosition() < size() - 1)
		{
			if (conductor->getNext() == greatest)
				{
					if (conductor->getNext()->getNext() != NULL)
					{
						conductor->setNext(conductor->getNext()->getNext());
					}
					else 
					{
						conductor->setNext(NULL);
					}
				}
		}
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
		return 0;
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
		return NULL;
	}
private:
	int posCount;
	Node* node1;
};
int main()
{
	Queue nodes(11);
	cout << "before dequeue" << endl;
	nodes.enqueue(25);
	nodes.enqueue(36);
	nodes.traverse();
	cout << "after dequeue" << endl;
	nodes.dequeue();
	nodes.traverse();
	return 0;
}
