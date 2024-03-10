#include <iostream>
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
    int num_vertices = 6;
    int num_edges = 7;

    Graph g(num_vertices);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);

    bool has_cycle = g.hasCycle();

    cout << boolalpha << has_cycle << endl;

    return 0;
}
