#include "adj_list.hpp"



void Graph::dfsHelper(int node, bool *visited){
    visited[node] = true;
    cout << node << ",";
    for(auto nbr: l[node]){
        if(!visited[nbr]){
            dfsHelper(nbr,visited);
        }
    }
    return;

}

void Graph::dfs(int source){
    bool *visited = new bool[size];
    dfsHelper(source, visited);
}

int main(){
    Graph g(7);

    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(3,5);
    g.addEdges(5,6);
    g.addEdges(4,5);
    g.addEdges(0,4);
    g.addEdges(3,4);
    
    g.dfs(1);
    return 0;
}