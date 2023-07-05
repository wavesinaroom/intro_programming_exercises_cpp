/* Let's have as given a graph G(V,E). Write a program that checks whether the graph is cyclic */

#include <iostream>
#include <vector>

class Vertex{
  private:
    int data;
  public:
    std::vector<Vertex*> edges;
    Vertex(int value){data=value;}
    void add(Vertex* v){
      edges.push_back(v);
    }
    int getData(){ return data; }
};

bool isCyclic(Vertex * v, Vertex * start){
  if(!v)
    return false;

  for (auto &child : v->edges) {
    if(child == start)
      return true;
    return isCyclic(child, start);
  }

  return false;
}

int main(){
  Vertex root (0);
  Vertex one (1);
  Vertex two (2);
  Vertex three (3);
  Vertex four (4);
  Vertex five (5);
  Vertex six (6);
  Vertex seven (7);
  Vertex eight (8);

  root.add(&one);
  root.add(&two);
  root.add(&three);
  root.edges[0]->add(&four);
  root.edges[0]->add(&five);
  root.edges[0]->add(&six);
  root.edges[0]->edges[0]->add(&seven);
  root.edges[0]->edges[0]->add(&eight);
  root.edges[0]->edges[0]->edges[0]->add(&root);

  std::cout<<isCyclic(&root, &root)<<'\n';
}
