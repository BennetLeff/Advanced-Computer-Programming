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
    Node* getLeft() { return this->left; }
    Node* getRight() { return this->right; }
    void setData(int dataSet){ data = dataSet; }
    void setLeft(Node* pointTo){ left = pointTo; }
    void setRight(Node* pointTo){ right = pointTo; }
private:
    Node* left;
    Node* right;
    int data;
};
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
        // cout << "\npassed " << conductor->getData() << endl;
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
    int maxDepth()
    {
        //cout << conductor->getData() << endl;
        if (conductor->getLeft() == NULL)
        {   
            //cout << "went here 1" << endl;
            if (conductor->getRight() == NULL)
            {
                //cout << "went here 2" << endl;
                conductor = root;
                return maxDepthCount;
            }
            else
            {
                //cout << "went here 3" << endl;
                maxDepthCount++;
                conductor = conductor->getRight();
                return maxDepth();
            }
        }
        else if (conductor->getLeft() != NULL)
        {
            if (conductor->getRight() == NULL)
            {    
                //cout << "went here 4" << endl;
                conductor = conductor->getLeft();
                maxDepthCount++;
                return maxDepth();
            }
            else
            {
                //cout << "went here 5" << endl;
                conductor = conductor->getRight();
                maxDepthCount++;
                return maxDepth();
            }
        }
        //cout << "went here 6" << endl;
        return maxDepthCount;
    }
    int minValue()
    {
        minValueNum = conductor->getData();
        if (conductor->getLeft() != NULL)
        {
            conductor = conductor->getLeft();
            return maxValue();
        }
        else
        {
            return maxValueNum;
        }
    }
    int maxValue()
    {
        maxValueNum = conductor->getData();
        if (conductor->getRight() != NULL)
        {
            conductor = conductor->getRight();
            return maxValue();
        }
        else
        {
            return maxValueNum;
        }
    }
    int size()
    {
        if (conductor->getLeft() == NULL)
        {   
            //cout << "went here 1" << endl;
            if (conductor->getRight() == NULL)
            {
                //cout << "went here 2" << endl;
                conductor = root;
                return sizeCount;
            }
            else
            {
                //cout << "went here 3" << endl;
                sizeCount++;
                conductor = conductor->getRight();
                return maxDepth();
            }
        }
        else if (conductor->getLeft() != NULL)
        {
            if (conductor->getRight() == NULL)
            {    
                //cout << "went here 4" << endl;
                conductor = conductor->getLeft();
                sizeCount++;
                return size();
            }
            else
            {
                //cout << "went here 5" << endl;
                conductor = conductor->getRight();
                sizeCount++;
                return size();
            }
        }
        //cout << "went here 6" << endl;
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
int main()
{
    int lookUpVar = 12;
    BinarySearchTree BST(5);
    /*
    cout << "---------- 7 ----------" << endl;
    cout << BST.insert(7) << endl;
    cout << "---------- 3 ----------" << endl;
    cout << BST.insert(3) << endl;
    cout << "---------- 9 ----------" << endl;
    cout << BST.insert(9) << endl;
    cout << "---------- 9 ----------" << endl;
    cout << BST.insert(9) << endl;
    cout << "---------- 12 ---------" << endl;
    cout << BST.insert(12) << endl;
    */
    BST.insert(7);
    BST.insert(3);
    BST.insert(9);
    BST.insert(9);
    BST.insert(12);
    BST.insert(90);
    cout << "lookUp " << lookUpVar << " returns " << BST.lookUp(lookUpVar) << endl;
    cout << "maxDepth returns " << BST.maxDepth() << endl;
    cout << "minValue " << BST.minValue() << endl;
    cout << "size " << BST.size() << endl;
    return 0;
}