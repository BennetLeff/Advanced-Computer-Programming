#include <cstddef>
#include <iostream>
#include "binarysearchtree.h"
using namespace std;

int main()
{
    int lookUpVar = 12;
    BinarySearchTree BST(5);
    BST.insert(7);
    BST.insert(3);
    BST.insert(9);
    BST.insert(9);
    BST.insert(12);
    BST.insert(90);
    BST.insert(99);
    cout << "lookUp " << lookUpVar << " returns " << BST.lookUp(lookUpVar) << endl;
    cout << "maxDepth returns " << BST.maxDepth() << endl;
    cout << "minValue " << BST.minValue() << endl;
    cout << "size " << BST.size() << endl;
    return 0;
}