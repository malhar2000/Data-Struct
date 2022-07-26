#include "adj_list.hpp"
#include <queue>

void Graph::bfs(int source){
    queue<int> q;
    bool *visited = new bool[size];
    q.push(source);

    visited[source] = true;

    while(!q.empty()){
        int front = q.front();
        cout << front << endl;
        q.pop();

        for(auto nbrs : l[front]){ 
            if(!visited[nbrs]){
                q.push(nbrs);
                visited[nbrs] = true;
            }
        }
    }
}

void Graph::bfs_shortest_path(int source, int dest){
    queue<int> q;
    bool *visited = new bool[size];

    //distance of each node from the source
    int *dist = new int[size]{0};

    //parent of each node
    int *parent = new int[size];

    for(int i = 0; i < size; i++){
        parent[i] = -1;
    }

    q.push(source);

    visited[source] = true;
    parent[source] = source;
    dist[source] = 0;

    while(!q.empty()){
        int front = q.front();
        
        q.pop();

        for(auto nbrs : l[front]){ 
            if(!visited[nbrs]){
                q.push(nbrs);
                visited[nbrs] = true;
                dist[nbrs] = dist[front] + 1;
                parent[nbrs] = front;
            }
        }
    }

    //print distance of each node from source
    for(int i = 0; i < size; i++){
        cout << dist[i] << endl;
    }
    
    if(dest != -1){
        int temp = dest;
        while(temp != source){
            cout << temp << "--> ";
            temp = parent[temp];
        }
        cout << source << endl;
    }
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
    // g.bfs(1);
    g.bfs_shortest_path(1, 6);
    return 0;

}