/* Let's have as given a graph G( V, E). Write a program that finds all connected components of the graph, i.e finds all maximal connected sub-graphs. A maximal connected sub-graph of G is a connected graph such that no other connected sub-graphs of G, contains it.*/

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
    std::vector<Node*> traversed;
    std::vector<Node> nodes;
    void traverse(Node *node, std::vector<Node*> &visited){
      if(!node)
        return;

      auto maximal = std::find_if(traversed.begin(), traversed.end(), [node](const Node* t){ return t == node; });
      auto found = std::find_if(visited.begin(), visited.end(), [node](const Node* s){return s->data==node->data;});

      if(maximal != traversed.end()){
        std::cout<<"Not maximal"<<'\n';
        return;
      }

      if(found==visited.end())
        visited.push_back(node);
      else{
        return;
      }

      for(int i=0; i<node->edges.size(); ++i)
        traverse(node->edges[i], visited);
    }

  public:
    Graph(){};
    void addNode(int data){nodes.push_back(Node(data));};
    void connectNodes(int from, int to){
      int f, t;
      for(int i=0; i<nodes.size(); ++i){
        if(nodes[i].data == from)
          f = from;
        else if(nodes[i].data == to)
          t = to;
      }
      nodes[f].edges.push_back(&nodes[t]);
    };

    void findMaximal(){
      for(const auto & e:nodes[0].edges){
        std::vector<Node *> v;
        traverse(e, v);
        for(const auto & visited:v){
          traversed.push_back(visited);
        }
      }
    }

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
  graph.connectNodes(1, 3);
  graph.connectNodes(3, 4);
  graph.connectNodes(3, 5);

  graph.connectNodes(0,6);
  graph.connectNodes(6,7);
  graph.connectNodes(6,8);
  graph.connectNodes(7,9);
  graph.connectNodes(8,9);

  graph.findMaximal();
}
