/* Suppose we are given a weighted oriented graph G (V, E), in which the weights on the side are nonnegative
 * numbers. Write a program that by a given vertex x from the graph finds the shortest paths from it to all
 * other vertical */ 

#include<iostream>
#include<vector>

class Edge{
  int *from, *to;
  public:
    Edge(int from, int to){
      this->from = &from;
      this->to = &to;
    }
};

class Graph{

  std::vector<int> nodes;
  std::vector<std::vector<int>> matrix;
  std::vector<std::vector<int>> shortest;
  public:

  void addNode(int node){
    nodes.push_back(node);

    for(int m=0; m<matrix.size(); ++m){
      matrix[m].push_back(0);
    }

    std::vector<int> tmp;
    for(int i=0; i<nodes.size(); ++i){
      tmp.push_back(0);
    }

    matrix.push_back(tmp);
  }

  void addEdge(int from, int to){
    int f, t, i=0;

    while(i<nodes.size()){
      if(i==from)
        f = i;
      else if(i==to)
        t = i;
      ++i;
    }

    matrix[f][t] = 1;
  }

  void traverse(int from, int to, std::vector<int> path){
    int f = 0;
    int t = 0;
    std::vector<int*> visit;

    if(from == to){
      path.push_back(from);
      pushShortest(path);
      return;
    }
      
    path.push_back(from);

    for(; f<nodes.size(); ++f){
      if(nodes[f]==from)
        break;
    }
    
    for(; t<matrix.size(); ++t){
      if(matrix[f][t]==1&&nodes[t]!=path[path.size()-1])
        visit.push_back(&nodes[t]);
    }

    for(const auto & v:visit){
      traverse(*v, to, path);
    }
  }

  void pushShortest(std::vector<int> path){
    int index = 0;
    
    if(shortest.empty()){
      shortest.push_back(path);
      return;
    }

    for(; index<=shortest.size(); ++index){
      if(index==shortest.size()){
        shortest.push_back(path);
        return;
      }

      if(shortest[index][0]==path[0])
        if(shortest[index][shortest[index].size()-1]==path[path.size()-1])
          break;
    }

    if(path.size()<shortest[index].size()){
      shortest.erase(shortest.begin()+index);
      shortest.push_back(path);
    }
   
  }
};

int main(){
  Graph graph;

  graph.addNode(0);
  graph.addNode(1);
  graph.addNode(2);
  graph.addNode(3);
  graph.addNode(4);
  graph.addNode(5);
  graph.addNode(6);
  graph.addNode(7);
  graph.addNode(8);
  graph.addNode(9);

  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
  graph.addEdge(4, 9);
  graph.addEdge(0, 5);
  graph.addEdge(5, 7);
  graph.addEdge(7, 8);
  graph.addEdge(8, 9);

  std::vector<int> path;
  graph.traverse(0, 9, path);

  return 0;
}
