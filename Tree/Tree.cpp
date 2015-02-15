#include "Tree.h"
#include <stdlib.h>

using namespace std;

int main()
{
    //Tree tree();
    //cout << rand() % 10 << endl;
    Tree tree(0);
    tree.genTree();
    tree.traverse(tree.rootNode());
    return 0;
}