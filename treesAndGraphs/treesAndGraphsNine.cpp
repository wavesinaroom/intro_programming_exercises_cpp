/* Implement a recursive traversal in depth in an undirected graph and a program to test it.*/

#include <iostream>
#include <vector>

class Vertex {
  private:
    int data;
  public:
    Vertex(int value){data = value;}
    Vertex * parent;
    int getData(){return data;}
    //position 0 always stores parent
    std::vector<Vertex *> edges;
    void add(Vertex * v){
      edges.push_back(v);
      edges.back()->add(this);
    };
};

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

}

