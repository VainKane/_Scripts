#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN][MAXN];

void bfs(int start, int n) {
    queue<int> q;
    q.push(start);
    dist[start][start] = 0;
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!visited[v]) {
                visited[v] = true;
                dist[start][v] = dist[start][u] + w;
                q.push(v);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i < n; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    
    // Precompute all pairs distances
    for (int i = 1; i <= n; ++i) {
        bfs(i, n);
    }
    
    vector<int> best_nodes;
    
    // Check all possible subsets of nodes
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<int> current_nodes;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                current_nodes.push_back(i + 1);
            }
        }
        
        if (current_nodes.size() < 2) continue;
        
        int d = dist[current_nodes[0]][current_nodes[1]];
        bool valid = true;
        for (int i = 0; i < current_nodes.size() && valid; ++i) {
            for (int j = i + 1; j < current_nodes.size() && valid; ++j) {
                if (dist[current_nodes[i]][current_nodes[j]] != d) {
                    valid = false;
                }
            }
        }
        
        if (valid && current_nodes.size() > best_nodes.size()) {
            best_nodes = current_nodes;
        }
    }
    
    // Handle case when no subset of size >= 2 is found
    if (best_nodes.empty()) {
        best_nodes.push_back(1);
    }
    
    cout << best_nodes.size() << endl;
    for (int node : best_nodes) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}