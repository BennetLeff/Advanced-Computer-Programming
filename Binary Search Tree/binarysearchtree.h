#include "node.h"

class BinarySearchTree
{
public:
    BinarySearchTree(int rootData)
    {
        root = new Node(rootData);
        conductor = root;
        maxDepthCount = 1;
        maxValueNum = 1;
        sizeCount = 1;
    }
    bool lookUp(int target)
    {
        if (conductor == NULL)  //->getLeft() && conductor->getRight() == NULL)
        {
            conductor = root;
            return 0;
        }
        else if (conductor->getData() == target)
        {
            conductor = root;
            return 1;
        }
        else                    //if(conductor->getData() != target)
        {
            if (conductor->getData() > target)
            {
                conductor = conductor->getLeft();
            }
            else if(conductor->getData() < target)
            {
                conductor = conductor->getRight();
            }
            return lookUp(target);
        }
    }
    int insert(int rootData)
    {
        if (conductor == NULL)
        {
            conductor = root;
            sizeCount++; // increments for the size method everytime a node is inserted
            return 0;
        }
        else if (conductor->getLeft() == NULL && rootData <= conductor->getData())
        {
            conductor->setLeft(new Node(rootData));
            conductor = root;
            sizeCount++;
            return 1;
        }
        else if (conductor->getRight() == NULL && rootData > conductor->getData())
        {
            conductor->setRight(new Node(rootData));
            conductor = root;
            sizeCount++;
            return 2;
        }
        else if (conductor->getLeft() != NULL && rootData <= conductor->getData())
        {
            conductor = conductor->getLeft();
            return insert(rootData);
        }
        else if (conductor->getRight() != NULL && rootData > conductor->getData())
        {
            conductor = conductor->getRight();
            return insert(rootData);
        }
        return 0;
    }
    int maxDepth()
    {
        if (conductor->getLeft() == NULL)
        {   
            if (conductor->getRight() == NULL)
            {
                conductor = root;
                return maxDepthCount;
            }
            else
            {
                maxDepthCount++;
                conductor = conductor->getRight();
                return maxDepth();
            }
        }
        else if (conductor->getLeft() != NULL)
        {
            if (conductor->getRight() == NULL)
            {    
                conductor = conductor->getLeft();
                maxDepthCount++;
                return maxDepth();
            }
            else
            {
                conductor = conductor->getRight();
                maxDepthCount++;
                return maxDepth();
            }
        }
        return maxDepthCount;
    }
    int minValue() // just traverses left down the tree
    {
        minValueNum = conductor->getData();
        if (conductor->getLeft() != NULL)
        {
            conductor = conductor->getLeft();
            return maxValue();
        }
        else
        {
            conductor = root;
            return maxValueNum;
        }
    }
    int maxValue() // just traverses right down the tree
    {
        maxValueNum = conductor->getData();
        if (conductor->getRight() != NULL)
        {
            conductor = conductor->getRight();
            return maxValue();
        }
        else
        {
            conductor = root;
            return maxValueNum;
        }
    }
    int size()
    {
        return sizeCount;
    }
private:
    Node* root; // root node
    Node* conductor; // navigates search tree
    int maxDepthCount;
    int maxValueNum;
    int minValueNum;
    int sizeCount;
};