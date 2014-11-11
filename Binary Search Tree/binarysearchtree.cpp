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
            cout << "conductor is NULL" << endl;
            conductor = root;
            return 0;
        }
        else if (conductor->getLeft() == NULL && rootData < conductor->getData())
        {
            cout << "conductor = " << conductor->getData() << endl;
            conductor->setLeft(new Node(rootData));
            cout << "setLeft" << endl;
            //return insert(rootData);
            conductor = root;
            return 1;
        }
        else if (conductor->getRight() == NULL && rootData >= conductor->getData())
        {
            cout << "conductor = " << conductor->getData() << endl;
            conductor->setRight(new Node(rootData));
            cout << "setRight" << endl;
            //return insert(rootData);
            conductor = root;
            return 2;
        }
        else if (conductor->getLeft() != NULL && rootData < conductor->getData())
        {
            cout << "conductor = " << conductor->getData() << endl;
            conductor = conductor->getLeft();
            cout << "went left" << endl;
            return insert(rootData);
        }
        else if (conductor->getRight() != NULL && rootData >= conductor->getData())
        {
            cout << "conductor = " << conductor->getData() << endl;
            conductor = conductor->getRight();
            cout << "went right" << endl;
            return insert(rootData);
        }
    }
    int maxDepth()
    {
        maxDepthCount += 1;
        /*
        if (conductor == NULL)
        {
            return maxDepthCount;
        }
        else if (conductor->getLeft() != NULL)
        {
            cout << "passed left " << conductor->getData() << endl;
            conductor = conductor->getLeft();
            maxDepth();
        }
        else //if (conductor->getRight() == NULL)
        {
            cout << "passed right " << conductor->getData() << endl;
            conductor = conductor->getRight();
            maxDepth();
        }
        return maxDepthCount;
        */
        //cout << "working";
        if (conductor->getLeft() == NULL)
        {
            cout << conductor->getData() << endl;
            //cout << "segfault after getLeft()" << endl;
            if (conductor->getRight() == NULL)
            {
                cout << conductor->getData() << endl;
                //cout << "segfault after getRight()" << endl;
                conductor = root; 
                return maxDepthCount;
            }
            else 
            {
                cout << conductor->getData() << endl;
                //cout << "segfault after getRight() != NULL" << endl;
                conductor = conductor->getRight();
                maxDepth();
            }
        }
        else
        {
            //cout << "segfault after else" << endl;
            cout << conductor->getData() << endl;
            conductor = conductor->getLeft();
            maxDepth();
        }
        return maxDepthCount;
    } 
    void reset()
    {
        conductor = root;
    }
private:
    Node* root; // root node
    Node* conductor; // navigates search tree
    int maxDepthCount;
    int maxValueCount;
    int minValueCount;
};
int main()
{
    int lookUpVar = 3;
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
    return 0;
}