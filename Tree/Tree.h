#include <iostream>
#include "node.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

class Tree 
{
public:
    Tree()
    {
        root = new Node((int) (rand() % 10) + 1);
        conductor = root;
    }
    Tree(int rootData)
    {
        root = new Node(rootData);
        conductor = root;
    }
    void genTree() 
    {
        srand(time(NULL));
        for (int i = 0; i < 10; i++)
        {
            if (rand() % 1 == 0)
            {
                conductor->push(rand() % 10);
                conductor = conductor->childNodes()[0];
            }
        }
    }
    Node* rootNode() 
    {
        return root;
    }
    int traverse(Node* n)
    {
        if (n == NULL)
        {
            cout << n->getData() << endl;
            return 0;
        }
        else
        {
            cout << n->getData() << endl;
            for (int i = 0; i < n->childrenSize(); i++)
            {
                cout << "//" << endl;
                traverse(n->childNodes()[i]);
            }
            return 0;
        }
    }
private:
    Node* root; 
    Node* conductor;
};