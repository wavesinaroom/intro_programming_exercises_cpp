/* Write a breadth first seach (BFS), based on a queue, to traverse a directed graph.*/

#include <iostream>
#include <vector>
#include <iterator>
#include <deque>

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

    std::deque<Node<V>*> queue;
  public:
    Graph(){};

    void addNode(V value){
      nodes.push_back(Node<V>(value));
    }

    void connectNodes(V from, V to){
      Node<V>* a = getNode(from);
      a->connectNode(getNode(to));
    }

    void enqueue(Node<V>* node){
      if(node == nullptr)
        return;

      for (auto &visited: queue) {
        if(node == visited)
          return;
      }

      queue.push_back(node);

      for (auto& edge : node->edges) {
        enqueue(edge);
      }
    }

  public:
    void bfs(){
      enqueue(&nodes[0]);

      while(!queue.empty()){
        std::cout<<queue.front()->data<<'\n';
        queue.pop_front();
      }
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
  graph.bfs();
  return 0;
}
