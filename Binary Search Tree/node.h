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