/* Implement a recursive traversal in depth in an undirected graph and a program to test it.*/

#include <iostream>
#include <vector>

class Graph{
  struct Node{
    int data;
  };
  struct Edge{
    Node *from, *to;
  };

  std::vector<Node*> nodes;
  std::vector<Edge*> edges;
}

