#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 5;

vector<pair<int, int>> adj[MAXN];
bool visited[MAXN];
int maxDist, farthestNode;

void dfs(int u, int dist) {
    visited[u] = true;
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = u;
    }

    for (auto [v, w] : adj[u]) {
        if (!visited[v]) {
            dfs(v, dist + w);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // Lần 1: tìm đỉnh xa nhất từ đỉnh 1
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(1, 0);

    // Lần 2: tìm đường kính từ đỉnh xa nhất vừa tìm được
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(farthestNode, 0);

    cout << maxDist << endl;
    return 0;
}
