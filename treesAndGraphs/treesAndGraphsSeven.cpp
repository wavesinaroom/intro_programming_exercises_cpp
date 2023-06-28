/* Let's have as given a graph G(V,E) and two of its vertices x and y. Write a program that finds
 * the shortest path between two vertices measured in number of vertices staying on the path.*/

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

int main(){
  Vertex main(1);
  Vertex child(2);
  main.add(&child);
  return 0;
}
