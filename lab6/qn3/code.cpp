#include <bits/stdc++.h>
using namespace std;

const int N = 6;
int V = N, E = 7;
vector<int> adj[N], radj[N];
bool vis[N], rvis[N];

void dfs(int s, stack<int> &st){
    vis[s] = true;
    for(auto x : adj[s])
        if(!vis[x])
            dfs(x, st);
    st.push(s);
}

vector<int> topological_sort(){
    stack<int> st;
    vector<int> srt;
    for(int i = 0; i < V; i++)
        if(!vis[i])
            dfs(i, st);
    while(!st.empty()){
        srt.push_back(st.top());
        st.pop();
    }
    return srt;
}

void rdfs(int s){
    rvis[s] = true;
    cout << s << " ";
    for(auto x : radj[s])
        if(!rvis[x])
            rdfs(x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    adj[0] = {1, 2};
    adj[1] = {3, 2};
    adj[2] = {4, 5};
    adj[3] = {5};

    for(int i = 0; i < V; i++){
        radj[i].clear();
        vis[i] = false;
        rvis[i] = false;
    }

    for(int i = 0; i < V; i++){
        for(auto x : adj[i])
            radj[x].push_back(i);
    }

    vector<int> tsrt = topological_sort();
    for(auto i : tsrt){
        if(!rvis[i]){
            rdfs(i);
            cout << endl;
        }
    }

    return 0;
}
