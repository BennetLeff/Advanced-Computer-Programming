#pragma once
#include "LinkedList.h"

// nodes that point to a linked list of nodes
class GraphNode{
public:
    // takes a node that will be the head node
    GraphNode(LinkedList* l)
    {
        childList = l;  
        next = NULL;
    }
    GraphNode* getNext()
    {
        return next;
    }
    void setNext(GraphNode* gr)
    {
        next = gr;
    }
    LinkedList* getChildList()
    {
        return childList;
    }
private:
    LinkedList* childList;
    GraphNode* next;
};

class Graph
{
public:
    // takes a GraphNode
    // points to a LinkedList of GraphNodes
    Graph(GraphNode* gn)
    {
        root = gn;
        conductor = root;
        graphNodeCount = 0;
    } 
    int traverse()
    {
        if (conductor->getNext() != NULL)
        {
            graphNodeCount++;
            std::cout << "GrapNode number: " << graphNodeCount << std::endl;
            conductor->getChildList()->traverse();
            conductor = conductor->getNext();
            traverse();
        }
        else
        {
            graphNodeCount++;
            std::cout << "GrapNode number: " << graphNodeCount << std::endl;
            conductor->getChildList()->traverse();
            conductor = root;
            return 0;
        }
        return 0;
    } 
    void addNode(GraphNode* n)
    {
        if (conductor->getNext() != NULL)
        {
            conductor = conductor->getNext();
            addNode(n);
        }
        else
        {
            conductor->setNext(n);
            conductor = root;
        }
    } 
private:
    GraphNode* root;
    GraphNode* conductor;
    int graphNodeCount;
};

/*
class Graph
{
public:
    // takes a GraphNode
    // points to a LinkedList of GraphNodes
    Graph(GraphNode* gn)
    {
        nodes = gn;
    } 
    void traverse()
    {
        nodes->getChildren()->traverse();
    } 
    void addNode(int n)
    {
        nodes->getChildren()->addNode(new Node(n));
    } 
private:
    GraphNode* nodes;
};
*/