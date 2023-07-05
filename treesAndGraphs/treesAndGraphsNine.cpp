/* Implement a recursive traversal in depth in an undirected graph and a program to test it.*/

#include <iostream>
#include <vector>

class Vertex {
  private:
    int data;
  public:
    int getData(){return data;}
    std::vector<Vertex *> children;
    void add(Vertex * v){children.push_back(v);};
};

int main(){

}
