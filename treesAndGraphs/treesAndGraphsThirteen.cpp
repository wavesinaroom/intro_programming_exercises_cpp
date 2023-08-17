/* Write a program that finds all loops in a directed graph */

#include <iostream>
#include <vector>

class Node{
  int data;
  public:
    Node(int data){this->data = data;};
};

class Edge{
  Node* from;
  Node* to;
  public:
  Edge(Node* from, Node* to){
    this->from = from;
    this->to = to;
  }
};
class Graph{
  std::vector<Edge> edges;
  std::vector<Node> nodes;
  public:
    Graph(){};
    void addNode(int data){nodes.push_back(Node(data));};
    void connectNodes(Node* from, Node* to){edges.push_back(Edge(from,to));};
};
