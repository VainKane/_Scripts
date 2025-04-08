#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, s, t;
vector<int> adj[N];
int parent[N];
int dist[N];
bool visited[N];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Sort adjacent nodes to ensure lexicographical order
        sort(adj[u].begin(), adj[u].end());

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (dist[v] == dist[u] + 1 && u < parent[v]) {
                // If same distance, choose the smaller parent for lex order
                parent[v] = u;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(s);

    if (!visited[t]) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    for (int v = t; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); ++i) {
        if (i > 0) cout << " ";
        cout << path[i];
    }
    cout << endl;

    return 0;
}