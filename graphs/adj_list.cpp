#include "adj_list.hpp"


int main(){
     Graph g(6);
     g.addEdges(0, 1);
     g.addEdges(0, 4);
     g.addEdges(2, 1);
     g.addEdges(3, 4);
     g.addEdges(4,5);
     g.addEdges(2,3);
     g.addEdges(3,5);
     g.printAdjList();

     return 0;
}