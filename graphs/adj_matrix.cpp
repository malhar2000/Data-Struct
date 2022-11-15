#include <iostream>


using namespace std;

class Graph{
    public:
        bool** adj_matrix;
        int vertices;

    Graph(const int vertices){
        this->vertices = vertices;
        // init arrays of vertices i.e. x arrays
        adj_matrix = new bool*[vertices];
        for(int i = 0; i < vertices; i++){
            // and now the above init arrays point to the first 
            // element of the these init arrays of size vertices
            adj_matrix[i] = new bool[vertices];
            for(int j = 0; j < vertices; j++){
                adj_matrix[i][j] = false;
            }
        }
    }

    void add_edge(int i, int j){
        adj_matrix[i][j] = true;
        adj_matrix[j][i] = true;;
    }
};


int main(){
    Graph g(6);

    g.add_edge(1, 1);
    g.add_edge(2, 1);
    g.add_edge(5, 3);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout << g.adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}