/* Write a program that finds all loops in a directed graph */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Node{
  int data;
  public:
    Node(int data){this->data = data;};
    friend class Graph;
};

class Edge{
  Node* from;
  Node* to;
  public:
    Edge(){}
    friend class Graph;
};

class Graph{
  private:
    bool isLoop;
    std::vector<Edge> edges;
    std::vector<Node> nodes;

  public:
    Graph(){};
    void addNode(int data){nodes.push_back(Node(data));};
    void connectNodes(int from, int to){
      edges.push_back(Edge());
      for(std::vector<Node>::iterator it = nodes.begin(); it!=nodes.end(); ++it){
        if(it->data == from)
          edges.front().from = &*it;
        else if (it->data == to)
          edges.front().to = &*it;
      }
    };
};

int main(){

  Graph graph;
  graph.addNode(0);
  graph.addNode(1);
  graph.addNode(2);
  graph.addNode(3);
  graph.addNode(4);
  graph.addNode(5);
  graph.addNode(6);
  graph.addNode(7);
  graph.addNode(8);
  graph.addNode(9);

  graph.connectNodes(1, 2);
  graph.connectNodes(2, 3);
  graph.connectNodes(3, 1);

  graph.connectNodes(1, 4);
  graph.connectNodes(4, 5);
  graph.connectNodes(5, 1);

  graph.connectNodes(2, 5);
  graph.connectNodes(5, 6);
  graph.connectNodes(6, 2);

  graph.connectNodes(2, 7);
  graph.connectNodes(7, 8);
  graph.connectNodes(8, 2);

  graph.connectNodes(3, 8);
  graph.connectNodes(8, 9);
  graph.connectNodes(9, 3);


  return 0;
}
