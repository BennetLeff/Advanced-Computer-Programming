#include <cstddef>
#include <iostream>
using namespace std;

class Node 
{
public:
    Node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
    }
    int getData(){ return this->data; }
    //int getPosition(){ return position; }
    Node* getLeft() { return this->left; }
    Node* getRight() { return this->right; }
    void setData(int dataSet){ data = dataSet; }
    //void setPosition(int pos){ this->position = pos; }
    void setLeft(Node* pointTo){ left = pointTo; }
    void setRight(Node* pointTo){ right = pointTo; }
private:
    Node* left;
    Node* right;
    int data;
    //int position; 
};
class BinarySearchTree
{
public:
    BinarySearchTree(int rootData)
    {
        root = new Node(rootData);
        conductor = root;
        maxDepthCount = 1;
    }
    bool lookUp(int target)
    {
        cout << "\npassed " << conductor->getData() << endl;
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
            return 0;
        }
        else if (conductor->getLeft() == NULL && rootData < conductor->getData())
        {
            conductor->setLeft(new Node(rootData));
            conductor = root;
            return 1;
        }
        else if (conductor->getRight() == NULL && rootData >= conductor->getData())
        {
            conductor->setRight(new Node(rootData));
            conductor = root;
            return 2;
        }
        else if (conductor->getLeft() != NULL && rootData < conductor->getData())
        {
            conductor = conductor->getLeft();
            return insert(rootData);
        }
        else if (conductor->getRight() != NULL && rootData >= conductor->getData())
        {
            conductor = conductor->getRight();
            return insert(rootData);
        }
        return 0;
    }
    /*
    int maxDepth()
    {
        //cout << "\npassed " << conductor->getData() << endl;
        if (conductor == NULL)
        {
            return maxDepthCount;
        }
        else if (conductor->getLeft() == NULL)
        {
            maxDepthCount += 1;
            conductor = conductor->getLeft();
            return maxDepthCount;
        }
        else if (conductor->getLeft() != NULL)
        {
            maxDepthCount += 1;
            conductor = conductor->getLeft();
            return maxDepth();
        }
        else if (conductor->getRight() == NULL)
        {
            maxDepthCount += 1;
            conductor = conductor->getRight();
            return maxDepth();
        }
        else if (conductor->getRight() != NULL)
        {
            maxDepthCount += 1;
            conductor = conductor->getRight();
            return maxDepth();
        }
    }
    */
private:
    Node* root; // root node
    Node* conductor; // navigates search tree
    int maxDepthCount;
    int maxValueCount;
    int minValueCount;
};
int main()
{
    int lookUpVar = 12;
    BinarySearchTree BST(5);
    cout << "---------- 7 ----------" << endl;
    cout << BST.insert(7) << endl;
    cout << "---------- 3 ----------" << endl;
    cout << BST.insert(3) << endl;
    cout << "---------- 9 ----------" << endl;
    cout << BST.insert(9) << endl;
    //cout << "lookUp 9 returns " << BST.lookUp(9) << endl;
    cout << "---------- 9 ----------" << endl;
    cout << BST.insert(9) << endl;
    cout << "---------- 12 ---------" << endl;
    cout << BST.insert(12) << endl;
    cout << "lookUp " << lookUpVar << " returns " << BST.lookUp(lookUpVar) << endl;
    cout << "maxDepth returns " << BST.maxDepth() << endl;
    return 0;
}