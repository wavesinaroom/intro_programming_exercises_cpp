/* Implement a recursive traversal in depth in an undirected graph and a program to test it.*/

#include <iostream>
#include <vector>

template<typename T>
class Node{
  private:
    T data;
    std::vector<Node*> edges;
  public:
    template<typename V> friend class Graph;
    Node(T value){
      data = value;
    }
};

template <typename V>
class Graph{
  private:
    std::vector<Node<V>> nodes;

  public:
    Graph(){};
    void addNode(V data){
      nodes.push_back(Node<V>(data));
    }
    
    void connectNodes(V from, V to){
      Node<V>* a;
      Node<V>* b;
      for(auto & node:nodes){
        if(node.data==from)
          a = &node;
        else if(node.data==to){
          b = &node;
          break;
        }
      }
      a->edges.push_back(b);
      b->edges.push_back(a);
    }    
};

int main(){
  Graph<int> graph;
  graph.addNode(0);
  graph.addNode(1);
  graph.addNode(2);
  graph.connectNodes(2, 0);
  return 0;
}
