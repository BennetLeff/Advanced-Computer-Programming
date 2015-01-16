#pragma once
#include "Node.h"
#include <iostream>

class LinkedList
{
private:
    Node* root;
    Node* conductor;
public:
    LinkedList(Node* n)
    {
        root = n;
        conductor = root;
    }
    Node* getRoot()
    {
        return root;
    }
    void addNode(Node* n)
    {
        if (conductor->getNext() != NULL)
        {
            conductor=conductor->getNext();
            addNode(n);
        }
        else
        {
            conductor->setNext(n);
            conductor = root;
        }
    }
    int traverse()
    {
        if (conductor->getNext() != NULL)
        {
            std::cout << conductor->getData() << std::endl;
            conductor = conductor->getNext();
            traverse();
        }
        else
        {
            std::cout << conductor->getData() << std::endl;
            conductor = root;
            return 0;
        }
        return 0;
    }
};

