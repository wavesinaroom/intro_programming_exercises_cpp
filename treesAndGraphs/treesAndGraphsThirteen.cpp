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
    Edge(Node* from, Node* to){this->from = from; this->to = to;}
    friend class Graph;
};

class Graph{
  private:
    bool isLoop;
    std::vector<Node> nodes;
   
  public:
    std::vector<Edge> edges;
    void traverse(const Edge& e, int start){
      auto it = std::find_if(edges.begin(), edges.end(), [e](const auto& edge){
        return edge.from == e.to;
    });
      std::cout<<"From: "<<it->from->data<<'\t'<<"To: "<<it->to->data<<'\n';
      if(it->to->data == start){
        std::cout<<"Loop"<<'\n';
        return;
      }
      traverse(*it, start);
    };
    Graph(){};
    void addNode(int data){nodes.push_back(Node(data));};
    void connectNodes(int from, int to){
      auto f = std::find_if(nodes.begin(), nodes.end(),[from](const Node& node){return node.data == from;});
      auto t = std::find_if(nodes.begin(), nodes.end(),[to](const Node& node){return node.data == to;});
      edges.push_back(Edge(&*f, &*t));
    };
  
    void findLoops(){
      std::for_each(edges.begin(), edges.end(), [this](const auto& e){traverse(e, e.from->data);});
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

  graph.connectNodes(0, 1);
  graph.connectNodes(1, 2);
  graph.connectNodes(2, 0);

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

  graph.traverse(graph.edges[0], 0);
}
