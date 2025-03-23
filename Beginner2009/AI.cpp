#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
int p[MAXN];
vector<int> adj[MAXN];
int parent[MAXN];
int sz[MAXN];
int ans[MAXN];
bool active[MAXN];

struct Node {
    int idx, val;
    bool operator < (const Node& other) const {
        return val > other.val;
    }
} nodes[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        nodes[i] = {i, p[i]};
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(nodes + 1, nodes + n + 1);

    memset(ans, -1, sizeof(ans));
    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= n; i++) {
        int u = nodes[i].idx;
        int val = nodes[i].val;

        active[u] = true;
        parent[u] = u;
        sz[u] = 1;

        if (ans[1] < val) {
            ans[1] = val;
        }

        for (int v : adj[u]) {
            if (!active[v]) continue;

            // union
            int root_u = find(u);
            int root_v = find(v);
            if (root_u != root_v) {
                if (sz[root_u] < sz[root_v]) {
                    swap(root_u, root_v);
                }
                parent[root_v] = root_u;
                int new_sz = sz[root_u] + sz[root_v];
                sz[root_u] = new_sz;
                if (ans[new_sz] < val) {
                    ans[new_sz] = val;
                }
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        if (k > 1) cout << ' ';
        cout << (ans[k] == -1 ? -1 : ans[k]);
    }
    cout << '\n';

    return 0;
}