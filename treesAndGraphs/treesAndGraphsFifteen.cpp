/* Suppose we are given a weighted oriented graph G (V, E), in which the weights on the side are nonnegative
 * numbers. Write a program that by a given vertex x from the graph finds the shortest paths from it to all
 * other vertical */ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Node {
  class Edge{
    int weight;
    Node * to;
    Edge(Node* to, int weight){
      this->to = to;
      this->weight = weight;
    }
    public:
      friend class Node;
      friend class Graph;
  };

  int data;
  Node(int data){this->data = data;};
  std::vector<Edge> edges;

  public:
    friend class Graph;
};


class Graph{
  int min = 0;
  std::vector<std::vector<Node::Edge*>> shortest;

  void traverse(Node::Edge* e, Node* end, std::vector<Node::Edge*> path){
    path.push_back(e);

    if(e->to == end){
      pushShortest(path);
      return;
    }

    for(int i = 0; i<e->to->edges.size(); ++i){
      traverse(&e->to->edges[i], end, path);
    }

  }

  void pushShortest(std::vector<Node::Edge*> path){
    int i = 0;

    if(shortest.size()==0){
      shortest.push_back(path);
      return;
    }

    while(i<shortest.size()){
      if(shortest[i][0] == path[0]){
        if(shortest[i][shortest[i].size()-1] == path[path.size()-1])
          break;
      }
      ++i;
    }

    if(path.size()<shortest[i].size()){
      std::vector<std::vector<Node::Edge*>>::iterator it;
      std::next(it, i);
      shortest.erase(it);
      shortest.push_back(path);
    }
  }

  void printShortest(std::vector<Node::Edge*> path){
    for(const auto & p:path){
      std::cout<<p->to->data<<'\t';
    }
    std::cout<<'\n';
  }

  public:
    Graph(){};
    std::vector<Node>nodes;
    void addNode(int data){
      nodes.push_back(Node(data));
    }

    void addEdge(int from, int to, int weight){
      Node *f, *t;
      for(int i=0; i<nodes.size(); ++i){
        if(nodes[i].data == from)
          f = &nodes[i];
        else if(nodes[i].data == to)
          t = &nodes[i];
      }
      Node::Edge edge(t, weight);
      f->edges.push_back(edge);
    }
    
    void findShortest(int from, int to){
      Node *f, *t;
      std::vector<Node::Edge*> path;

      for(int i=0; i<nodes.size(); ++i){
        if(nodes[i].data == from)
          f = &nodes[i];
        else if(nodes[i].data == to)
          t = &nodes[i];
      }

      for(int j=0; j<f->edges.size(); ++j){
        traverse(&f->edges[j], t, path);
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

  graph.addEdge(0, 1, 2);
  graph.addEdge(1, 2, 2);
  graph.addEdge(2, 3, 2);
  graph.addEdge(1, 4, 2);
  graph.addEdge(2, 4, 2);
  graph.addEdge(3, 4, 2);

  graph.findShortest(1, 4);

  return 0;
}
