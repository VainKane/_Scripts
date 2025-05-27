#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, q;
vector<tuple<int, int, int>> edges; // u, v, w
map<int64_t, int64_t> cnt;
vector<pair<int, int>> queries;

int parent[MAXN], sz[MAXN];

int find(int u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void unite(int u, int v, int w) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    cnt[w] += 1LL * sz[u] * sz[v];
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (auto &[w, u, v] : edges) {
        unite(u, v, w);
    }

    // Tạo prefix sum
    vector<pair<int64_t, int64_t>> prefix;
    for (auto &[w, c] : cnt) {
        if (prefix.empty())
            prefix.emplace_back(w, c);
        else
            prefix.emplace_back(w, prefix.back().second + c);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        auto get = [&](int64_t x) {
            auto it = upper_bound(prefix.begin(), prefix.end(), make_pair(x, (int64_t)1e18));
            if (it == prefix.begin()) return 0LL;
            --it;
            return it->second;
        };
        cout << get(r) - get(l - 1) << ' ';
    }
    return 0;
}
