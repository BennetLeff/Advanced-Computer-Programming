#pragma once
class Node 
{
public:
    Node(int d)
    {
        next = NULL;
        data = d;
    }
    int getData(){ return this->data; }
    Node* getNext() { return this->next; }
    void setData(int d){ this->data = d; }
    void setNext(Node* pointTo){ this->next = pointTo; }
private:
    Node* next;
    int data;
};