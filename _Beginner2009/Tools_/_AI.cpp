#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4005;

int n, timer = 0;
vector<int> tree1[MAXN], tree2[MAXN];
int in1[MAXN], out1[MAXN], in2[MAXN], out2[MAXN];
int parent1[MAXN], parent2[MAXN];
vector<pair<int, int>> edges1, edges2;
vector<int> subtree1[MAXN * 2], subtree2[MAXN * 2];

// Euler Tour
void dfs(int u, int p, vector<int> tree[], int in[], int out[], int parent[]) {
    in[u] = ++timer;
    parent[u] = p;
    for (int v : tree[u]) {
        if (v != p)
            dfs(v, u, tree, in, out, parent);
    }
    out[u] = timer;
}

// Fenwick Tree
int BIT[MAXN];

void update(int x, int val) {
    for (; x < MAXN; x += x & -x)
        BIT[x] += val;
}

int query(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x)
        res += BIT[x];
    return res;
}

int query_range(int l, int r) {
    return query(r) - query(l - 1);
}

bool is_child(int in[], int out[], int u, int v) {
    return in[v] >= in[u] && out[v] <= out[u];
}

    stack<int> st;
    st.push(root);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        subtree.push_back(u);
        for (int v : tree[u]) {
            if (v != ban && !is_child(in, out, v, root))
                st.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        tree1[u].push_back(v);
        tree1[v].push_back(u);
        edges1.emplace_back(u, v);
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        tree2[u].push_back(v);
        tree2[v].push_back(u);
        edges2.emplace_back(u, v);
    }

    // Euler tour
    timer = 0;
    dfs(0, -1, tree1, in1, out1, parent1);
    timer = 0;
    dfs(0, -1, tree2, in2, out2, parent2);

    // Collect subtree nodes after removing each edge
    for (int i = 0; i < edges1.size(); ++i) {
        auto [u, v] = edges1[i];
        if (parent1[v] == u)
            swap(u, v); // ensure u is child

        vector<int> A1, A2;
        collect_subtree_nodes(u, v, tree1, in1, out1, A1);
        collect_subtree_nodes(v, u, tree1, in1, out1, A2);
        subtree1[2 * i] = A1;
        subtree1[2 * i + 1] = A2;
    }

    for (int i = 0; i < edges2.size(); ++i) {
        auto [u, v] = edges2[i];
        if (parent2[v] == u)
            swap(u, v); // ensure u is child

        vector<int> B1, B2;
        collect_subtree_nodes(u, v, tree2, in2, out2, B1);
        collect_subtree_nodes(v, u, tree2, in2, out2, B2);
        subtree2[2 * i] = B1;
        subtree2[2 * i + 1] = B2;
    }

    vector<int> ans(n + 1, 0);
    int m = n - 1;

    for (int i = 0; i < 2 * m; i += 2) {
        for (int j = 0; j < 2 * m; j += 2) {
            int max_common = 0;
            for (int a = 0; a < 2; ++a) {
                // Add all nodes in subtree1[i+a] to BIT
                for (int u : subtree1[i + a])
                    update(in1[u], 1);
                for (int b = 0; b < 2; ++b) {
                    int cnt = 0;
                    for (int v : subtree2[j + b])
                        cnt += query(in1[v]);
                    max_common = max(max_common, cnt);
                }
                for (int u : subtree1[i + a])
                    update(in1[u], -1);
            }
            ans[max_common]++;
        }
    }

    for (int i = 0; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}
