/* Write a breadth first seach (BFS), based on a queue, to traverse a directed graph.*/

#include <iostream>
#include <vector>
#include <iterator>

template<typename T> class Node{
  private:
    T data;
    std::vector<Node<T>*> edges;
  public:
    Node(T value){data = value;}
    template<typename V> friend class Graph;
    void connectNode(Node<T>* to){
      edges.push_back(to);
    }
};

template<typename V> class Graph{
  private:
    std::vector<Node<V>> nodes;
    Node<V>* getNode(V value){
      typename std::vector<Node<V>>::iterator it = nodes.begin();
      while(it != nodes.end()){
        if(it.data == value)
          return &*it;
        ++it;
      }
    } 
  public:
    Graph(){};
    void addNode(V value){
      nodes.push_back(Node<V>(value));
    }
    void connecNodes(V from, V to){
      Node<V>* a = getNode(from);
      a->connectNode(getNode(to));
    }
};


int main(){
  Graph<int> graph;
  graph.addNode(0);
  return 0;
}
