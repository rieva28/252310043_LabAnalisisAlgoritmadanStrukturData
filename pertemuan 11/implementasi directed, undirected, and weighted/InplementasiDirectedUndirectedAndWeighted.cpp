#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int> > adj; // Adjacency List
    
public:
    Graph (int V) {
        this->V = V;
        adj.resize(V); // Manipulasi ukuran pada simpul
    }
    
    
    void addEdgeUndir(int u, int v) {
        adj[u].push_back(v); //
    }
}
