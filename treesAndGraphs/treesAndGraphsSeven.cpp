/* Let's have as given a graph G(V,E) and two of its vertices x and y. Write a program that finds
 * the shortest path between two vertices measured in number of edges staying on the path.*/

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

int dfs(Vertex* v, int value, int count=0){
  if(!v||v->getData()==value)
    return count;
  for (auto &child : v->edges) {
    return dfs(child,value, ++count);
  }
  
  return count;
}

int main(){
  Vertex root(1);
  Vertex one(2);
  Vertex two(3);
  Vertex three(4);
  Vertex subone(5);
  Vertex subtwo(6);
  Vertex subthree(7);
  Vertex subsubone(8);
  root.add(&one);
  root.add(&two);
  root.add(&three);
  root.edges[0]->add(&subone);
  root.edges[1]->add(&subtwo);
  root.edges[2]->add(&subthree);
  root.edges[0]->edges[0]->add(&subsubone);
  int a = dfs(&root, 8);
  int b = dfs(&root, 2);
  std::cout<<a-b<<'\n';
  return 0;
}
