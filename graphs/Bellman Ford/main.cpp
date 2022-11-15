#include <iostream>
#include <vector>

using namespace std;

vector<int> bellman_ford(int V, int src, vector<vector<int> > edge_list){

    vector<int> dist(V+1, INT_MAX);
    dist[src] = 0;

    for(int i=0; i< V-1;i++){
        for(auto edge : edge_list){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
             
             // first cond. just to avoid overflow.. so we don't add a number to INT_MAX
            if(dist[u] != INT_MAX and dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }
    // negative wt cycle meaning we can reduce dist infinite times..
    // after V-1 iteration if we are stiil able to decreser the dist then we have negative wt cycle
    for(auto edge : edge_list){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if(dist[u] != INT_MAX and dist[u]+wt < dist[v]){
            cout << "Negative wt cycle" << endl;
            exit(0);
        }
    }

    return dist;
}


int main(){
    int num_edges;
    int num_vertices;
    vector<vector<int> > edge_list;

    cin >> num_edges >> num_vertices;

    for(int i = 0; i < num_edges; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edge_list.push_back({u, v, wt});
    }

    vector<int> d = bellman_ford(num_vertices, 1, edge_list);

    for(int i=1; i <= num_vertices; i++){
        cout << "Node " << i << " is at dist " << d[i] << endl;
    }
    
}