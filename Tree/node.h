#include <Vector>
using namespace std;
class Node 
{
public:
    Node(int d)
    {
        data = d;
    }
    int getData(){ return data; }
    void setData(int d){ data = d; }
    void push(int d){ children.push_back(new Node(d)); }
    int childrenSize() { return children.size(); }
    vector<Node*> childNodes() { return children; }
private:
    vector<Node*> children;
    int data;
};