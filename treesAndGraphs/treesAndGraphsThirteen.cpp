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
   
  public:
    Graph(){};
    std::vector<Node> nodes;
    void traverse(Node node, std::vector<int> steps){
      auto found = std::find_if(steps.begin(), steps.end(), [node](const int step){return node.data == step;});
      if(found!=steps.end()){
        std::cout<<"Loop at: "<<*found<<'\n';
        return;
      }

      steps.push_back(node.data);

      for(const auto & e:node.edges){
        traverse(*e, steps);
      }
    }

    void findLoops(){
      std::for_each(nodes.begin(), nodes.end(),[this](const Node& node){
            std::vector<int>visited;
            traverse(node, visited);});
    }
    

    void addNode(int data){nodes.push_back(Node(data));};
    void connectNodes(int from, int to){
      auto f = std::find_if(nodes.begin(), nodes.end(),[from](const Node& node){return node.data == from;});
      auto t = std::find_if(nodes.begin(), nodes.end(),[to](const Node& node){return node.data == to;});

      f->edges.push_back(&*t);
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
  graph.connectNodes(2, 3);
  graph.connectNodes(3, 4);
  graph.connectNodes(4, 5);
  graph.connectNodes(5, 0);
  graph.connectNodes(0, 6);
  graph.connectNodes(6, 7);
  graph.connectNodes(7, 8);
  graph.connectNodes(8, 9);
  graph.connectNodes(9, 0);

  graph.findLoops();
}
