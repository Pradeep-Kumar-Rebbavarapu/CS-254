#include <iostream>
#include <vector>
#define int long long
using namespace std;

int num_vertices;

vector<vector<int>> adjacency_matrix;
vector<vector<int>> memoization_table;

int find_shortest_path(int current_vertex, int remaining_vertices_mask){
    if(memoization_table[current_vertex][remaining_vertices_mask] != 0)
        return memoization_table[current_vertex][remaining_vertices_mask];
    
    if(__builtin_popcount(remaining_vertices_mask) == 2)
        return memoization_table[current_vertex][remaining_vertices_mask] = adjacency_matrix[0][current_vertex];
    
    int result = INT_MAX;
    for(int next_vertex = 1; next_vertex < num_vertices; next_vertex++)
        if((remaining_vertices_mask & (1 << next_vertex)) && next_vertex != current_vertex)
            result = min(result, find_shortest_path(next_vertex, remaining_vertices_mask ^ (1 << current_vertex)) + adjacency_matrix[next_vertex][current_vertex]);
    return memoization_table[current_vertex][remaining_vertices_mask] = result;
}

signed main(){
    freopen("test_cases_Q3.txt","r",stdin);
    freopen("output_Q3.txt","w",stdout);
    int test_cases; cin >> test_cases;
    while(test_cases--){
        cin >> num_vertices;
        memoization_table.resize(num_vertices);
        adjacency_matrix.resize(num_vertices);
        for(int i=0; i<num_vertices; i++){
            adjacency_matrix[i].resize(num_vertices);
            for(int j=0; j<num_vertices; j++)
                cin >> adjacency_matrix[i][j];
            memoization_table[i].resize(1 << num_vertices);
        }
        int answer = INT_MAX;
        for(int start_vertex = 1; start_vertex < num_vertices; start_vertex++)
            answer = min(answer, find_shortest_path(start_vertex, (1 << num_vertices)-1) + adjacency_matrix[start_vertex][0]);
        cout << answer << endl;
    }
}
