/* Write a program that finds all loops in a directed graph */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Node{
  int data;
  std::vector<Node*> edges;
  public:
    Node(int data){this->data = data;};
    friend class Graph;
};

class Graph{
  private:
    std::vector<Node> nodes;
   
  public:
    Graph(){};
    void addNode(int data){nodes.push_back(Node(data));};
    void connectNodes(int from, int to){
      auto f = std::find_if(nodes.begin(), nodes.end(),[from](const Node& node){return node.data == from;});
      auto t = std::find_if(nodes.begin(), nodes.end(),[to](const Node& node){return node.data == to;});

      f->edges.push_back(&*t);
    };
  
};

int main(){

}
