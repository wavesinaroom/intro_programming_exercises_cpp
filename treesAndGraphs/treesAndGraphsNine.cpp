/* Implement a recursive traversal in depth in an undirected graph and a program to test it.*/

#include <iostream>
#include <iterator>
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

    Node<V>* getNode(V value){
      typename std::vector<Node<V>>::iterator i = nodes.begin();
      while(i!=nodes.end()){
        if(i->data==value)
          return &*i;
        ++i;
      }
      return nullptr;
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

    void dfs(V value, Node<V>* node){
      if(!node)
        return;

      if(node->data==value){
        std::cout<<"Node found!"<<'\n';
        return;
      }
        
      for (auto & vertex : node->edges) {
        dfs(value, vertex); 
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
  graph.connectNodes(0, 2);
  graph.connectNodes(2,4);
  graph.connectNodes(4, 5);
  graph.connectNodes(5, 6);
  graph.connectNodes(5, 7);

  return 0;
}
