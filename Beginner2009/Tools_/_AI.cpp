#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int n, m;
vector<int> adj[MAXN];

int dsu[MAXN], sz[MAXN];
bool visited[MAXN];

void init_dsu() {
    for (int i = 1; i <= n; ++i) {
        dsu[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if (dsu[u] != u)
        dsu[u] = find(dsu[u]);
    return dsu[u];
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    dsu[v] = u;
    sz[u] += sz[v];
    return true;
}

int count_components_without(int banned) {
    init_dsu();
    for (int i = 1; i <= n; ++i)
        visited[i] = false;

    for (int u = 1; u <= n; ++u) {
        if (u == banned) continue;
        for (int v : adj[u]) {
            if (v == banned) continue;
            unite(u, v);
        }
    }

    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (i != banned && find(i) == i)
            components++;
    }
    return components;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxComponents = -1, city = -1;
    for (int i = 1; i <= n; ++i) {
        int components = count_components_without(i);
        if (components > maxComponents || (components == maxComponents && i < city)) {
            maxComponents = components;
            city = i;
        }
    }

    cout << maxComponents << " " << city << "\n";
    return 0;
}
