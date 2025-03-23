#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    vector<bool> activated;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        activated.resize(n + 1, false);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u == root_v) return;
        if (size[root_u] < size[root_v]) {
            swap(root_u, root_v);
        }
        parent[root_v] = root_u;
        size[root_u] += size[root_v];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("20C.inp", "r", stdin);
    freopen("20C.ans", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(), [&p](int a, int b) {
        return p[a] > p[b];
    });

    DSU dsu(n);
    vector<int> ans(n + 1, -1);

    for (int u : order) {
        dsu.activated[u] = true;
        if (ans[1] == -1) {
            ans[1] = p[u];
        }
        for (int v : adj[u]) {
            if (dsu.activated[v]) {
                int root_u = dsu.find(u);
                int root_v = dsu.find(v);
                if (root_u != root_v) {
                    int a = dsu.size[root_u];
                    int b = dsu.size[root_v];
                    int new_size = a + b;
                    if (ans[new_size] == -1) {
                        ans[new_size] = p[u];
                    }
                    dsu.unite(root_u, root_v);
                }
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        cout << ans[k] << ' ';
    }

    return 0;
}