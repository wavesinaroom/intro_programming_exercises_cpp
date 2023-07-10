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
    std::vector<Vertex *> edges;
    void add(Vertex * v){
      edges.push_back(v);
      edges.back()->parent = this;
    };
};

int main(){

  Vertex root  (0);
  Vertex one (1);
  root.add(&one);
}

