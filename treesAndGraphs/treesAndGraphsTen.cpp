/* Write a breadth first seach (BFS), based on a queue, to traverse a directed graph.*/

#include <iostream>
#include <vector>
#include <iterator>

template<typename T> class Node{
  private:
    T data;
    std::vector<Node*> edges;
  public:
    template<typename V> friend class Graph;
    Node(T value){data = value;}
    void connectNode(Node<T>* to){
      edges.push_back(to);
    }
};

template<typename V> class Graph{
  private:
    std::vector<Node<V>> nodes;
    Node<V>* getNode(V value){
      typename std::vector<Node<V>>::iterator i = nodes.begin();
      while (i!=nodes.end()) {
        if(i->data == value) 
          return &*i;
        ++i;
      }
      return nullptr;
    } 
  public:
    Graph(){};
    void addNode(V value){
      nodes.push_back(Node<V>(value));
    }
    void connectNodes(V from, V to){
      Node<V>* a = getNode(from);
      a->connectNode(getNode(to));
    }
};


int main(){
  Graph<int> graph;
  graph.addNode(0);
  graph.addNode(1);
  graph.addNode(2);
  graph.addNode(3);
  graph.addNode(4);
  graph.addNode(5);
  graph.addNode(6);
  graph.addNode(7);
  graph.connectNodes(0, 1);
  graph.connectNodes(1, 2);
  graph.connectNodes(2, 3);
  graph.connectNodes(3,4);
  graph.connectNodes(0, 2);
  graph.connectNodes(2,4);
  graph.connectNodes(4, 5);
  graph.connectNodes(5, 6);
  graph.connectNodes(5, 7);
  return 0;
}
