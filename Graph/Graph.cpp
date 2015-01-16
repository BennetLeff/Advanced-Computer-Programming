#include <cstddef>
#include <iostream>
#include "LinkedList.h"
#include "Graph.h"

int main()
{
    LinkedList list1(new Node(10));
    list1.addNode(new Node(11));
    GraphNode g(&list1);
    
    LinkedList list2(new Node(22));
    list2.addNode(new Node(24));
    GraphNode g2(&list2);

    LinkedList list3(new Node(37));
    list3.addNode(new Node(49));
    GraphNode g3(&list3);

    LinkedList list4(new Node(45));
    list4.addNode(new Node(67));
    GraphNode g4(&list4);

    Graph gr(&g);
    gr.addNode(&g2);
    gr.addNode(&g3);
    gr.addNode(&g4);
    gr.traverse();

    return 0;
}