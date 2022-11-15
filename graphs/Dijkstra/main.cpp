// #include "../adj_list.hpp"
#include<iostream>
#include <vector>
#include <set>
#include <utility>
#include <list>
using namespace std;


class Graph{
    public:
        list <pair<int, int>> *l;
        int size;

    public:
    Graph(int size){
        this->size = size;
        l = new list<pair<int, int>>[size];
    }

    void addEdges(int i, int j, int wt, bool undirected = true){
        l[i].push_back({wt, j});

        if(undirected){
            l[j].push_back({wt, i});
        }
    }

    int dijkstra(int, int);
    
};

int Graph::dijkstra(int src, int dst){

    vector<int> dist(size, INT_MAX);
    set<pair<int,int> > s;

    dist[src] = 0;
    s.insert({0, src});

    while(!s.empty()){

        auto it = s.begin();

        int node = it->second;
        int nodeDistTillNow = it->first;
        s.erase(it);

        // auto becoz in l the node will be store as pair (4, 1) where 1 is 
        // the node and 4 is the weight of the edge
        for(auto nbrPair : l[node]){
            int nbr = nbrPair.second;
            int currentEdgeWeight = nbrPair.first;

            if(nodeDistTillNow + currentEdgeWeight < dist[nbr]){
                
                // remove the nbr if it already exist in the set 
                // becoz we found a smaller value and therefore we need to update it,,
                auto f = s.find({dist[nbr], nbr});
                if(f != s.end()){
                    s.erase(f);
                }

                dist[nbr] = nodeDistTillNow + currentEdgeWeight;

                // you can use make_pair or {} ...
                // updating the value
                s.insert(make_pair(dist[nbr], nbr));
            }
        }


    }
    for(int i = 0; i < size; i++){
        cout << "Node " << i << " Dist " << dist[i] << endl;
    }

    return dist[dst];
    
}

int main(){

    Graph g(5);

    g.addEdges(0, 1, 1);
    g.addEdges(1, 2, 1);
    g.addEdges(0, 2, 4);
    g.addEdges(0, 3, 7);
    g.addEdges(3, 2, 2);
    g.addEdges(3, 4, 3);
     
    int d = g.dijkstra(0, 4);
    cout << d << endl;
}