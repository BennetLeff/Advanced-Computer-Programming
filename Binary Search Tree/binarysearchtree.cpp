#include <cstddef>
#include <iostream>
using namespace std;

class Node 
{
public:
    Node(int data)
    {
        left = NULL;
        right = NULL;
        this->data = data;
    }
    int getData(){ return this->data; }
    //int getPosition(){ return position; }
    Node* getLeft() { return this->left; }
    Node* getRight() { return this->right; }
    void setData(int data){ this->data = data; }
    //void setPosition(int pos){ this->position = pos; }
    //void setNext(Node* pointTo){ this->next = pointTo; }
private:
    Node* left;
    Node* right;
    int data;
    //int position; 
};
class BinarySearchTree
{
public:
    Node* conductor; // navigates search tree
    BinarySearchTree(int rootData)
    {
        Node* root = new Node(rootData);
        conductor = root;
    }
    bool lookUp(int target)
    {
        if (conductor->getLeft() && conductor->getRight() == NULL)
        {
            return false;
        }
        else if (conductor->getData() == target)
        {
            return true;
        }
        else //if(conductor->getData() != target)
        {
            if (conductor->getData() <= target)
            {
                conductor = conductor->getLeft();
            }
            else
            {
                conductor = conductor->getRight();
            }
            lookUp(target);
        }
        return false;
    } 
};
int main()
{
    BinarySearchTree BST(5);
    if(BST.lookUp(6))
    { 
        cout << "working" << endl;
    }
    return 0;
}