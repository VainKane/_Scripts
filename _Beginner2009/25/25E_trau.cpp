#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, s, t;
vector<int> adj[N];
int dist[N];
int parent[N];

void bfs() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                // For same distance, take lexicographically smaller parent
                parent[v] = min(parent[v], u);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Sort adjacency lists to consider neighbors in order
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    bfs();
    
    if (dist[t] == -1) {
        cout << -1;
        return 0;
    }
    
    vector<int> path;
    for (int v = t; v != s; v = parent[v]) {
        path.push_back(v);
    }
    path.push_back(s);
    
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    
    return 0;
}