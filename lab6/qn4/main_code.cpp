#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    bool hasCycle();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

bool Graph::hasCycle() {
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; ++i) {
        for (int v : adj[i])
            inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    int count = 0; 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++; 

        for (int v : adj[u]) {
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }

    
    return count != V;
}

int main() {
    ifstream input("input.txt");
    int num_vertices, num_edges;
    input >> num_vertices >> num_edges;

    Graph g(num_vertices);
    for (int i = 0; i < num_edges; ++i) {
        int u, v;
        input >> u >> v;
        g.addEdge(u, v);
    }
    input.close();

    bool has_cycle = g.hasCycle();

    ofstream output("output.txt");
    output << boolalpha << has_cycle << endl;
    output.close();

    return 0;
}
