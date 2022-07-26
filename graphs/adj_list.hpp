#include <iostream>
#include <list>
#include <vector>
using namespace std;


class Graph{
    list <int> *l;
    int size;

    public:
    Graph(int size){
        this->size = size;
        l = new list<int>[size];
    }

    void addEdges(int i, int j, bool undirected = true){
        l[i].push_back(j);

        if(undirected){
            l[j].push_back(i);
        }
    }

    void printAdjList(){
        for(int i=0; i<size; i++){
            cout << i << "---> ";
            for(auto x: l[i]){
                cout << x << ",";
            }
            cout << endl;
        }
    }

    void bfs(int);
    void bfs_shortest_path(int, int);

    void dfs(int);
    void dfsHelper(int, bool*);
};