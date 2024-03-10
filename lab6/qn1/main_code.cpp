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
    vector<int> topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

vector<int> Graph::topologicalSort() {
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

    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }

    return result;
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

    vector<int> sorted_vertices = g.topologicalSort();

    ofstream output("output.txt");
    for (int vertex : sorted_vertices) {
        output << vertex << "\n";
    }
    output.close();

    return 0;
}
