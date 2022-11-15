#include <iostream>
#include <list>
#include <vector>
#include <utility>

using namespace std;

class Graph
{
public:
    int size;
    list<pair<int, int>> *l;

    Graph(int size)
    {
        this->size = size;
        l = new list<pair<int, int>>[size];
    }

    void addEdges(int u, int v, int wt, bool undirected = false)
    {
        l[u].push_back({v, wt});
        if (undirected)
        {
            l[v].push_back({u, wt});
        }
    }

    vector<vector<int>> floydWarshall();
};

vector<vector<int>> Graph::floydWarshall()
{
    // 10000 instead of INT_MAX to avoid overflow in line 43 & 44
    vector<vector<int>> matrix(size, vector<int>(size, 10000));

    for (int i = 0; i < size; i++)
    {
        matrix[i][i] = 0;
        for (auto j : l[i])
        {
            int u = j.first;
            matrix[i][u] = j.second;
        }
    }

    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    return matrix;
}

int main()
{

    Graph g(4);

    g.addEdges(0, 2, -2);
    g.addEdges(1, 0, 4);
    g.addEdges(1, 2, 3);
    g.addEdges(2, 3, 2);
    g.addEdges(3, 1, -1);

    vector<vector<int>> d = g.floydWarshall();

    for (int i = 0; i < d.size(); i++)
    {
        for (int j : d[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}