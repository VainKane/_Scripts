#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
    int n;
    vector<int> tree;
    vector<bool> lazy;

    SegmentTree(int size)
    {
        n = 1;
        while (n < size)
            n <<= 1;
        tree.resize(2 * n, 0);
        lazy.resize(2 * n, false);
    }

    void apply(int node, int l, int r)
    {
        tree[node] = (r - l + 1);
        if (l != r)
        {
            lazy[2 * node] = true;
            lazy[2 * node + 1] = true;
        }
        lazy[node] = false;
    }

    void push(int node, int l, int r)
    {
        if (lazy[node])
        {
            int mid = (l + r) / 2;
            apply(2 * node, l, mid);
            apply(2 * node + 1, mid + 1, r);
            lazy[node] = false;
        }
    }

    void update_range(int node, int l, int r, int ul, int ur)
    {
        if (ur < l || ul > r)
            return;
        if (ul <= l && r <= ur)
        {
            apply(node, l, r);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update_range(2 * node, l, mid, ul, ur);
        update_range(2 * node + 1, mid + 1, r, ul, ur);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int l, int r)
    {
        update_range(1, 0, n - 1, l, r);
    }

    int query()
    {
        return tree[1];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<int> depth(n + 1, 0);
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    depth[1] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (v != parent[u])
            {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

    const int LOG = 20;
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        up[0][i] = parent[i];
    for (int j = 1; j < LOG; ++j)
        for (int i = 1; i <= n; ++i)
            up[j][i] = up[j - 1][up[j - 1][i]];

    auto lca = [&](int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);
        for (int j = LOG - 1; j >= 0; --j)
            if (depth[u] - (1 << j) >= depth[v])
                u = up[j][u];
        if (u == v)
            return u;
        for (int j = LOG - 1; j >= 0; --j)
            if (up[j][u] != up[j][v])
                u = up[j][u], v = up[j][v];
        return up[0][u];
    };

    vector<int> size(n + 1, 0);
    vector<int> head(n + 1, 0);
    vector<int> pos(n + 1, 0);
    int current_pos = 0;

    function<void(int)> dfs_size = [&](int u)
    {
        size[u] = 1;
        for (int v : adj[u])
        {
            if (v != parent[u])
            {
                dfs_size(v);
                size[u] += size[v];
            }
        }
    };
    dfs_size(1);

    function<void(int, int)> dfs_hld = [&](int u, int h)
    {
        head[u] = h;
        pos[u] = ++current_pos;
        int max_size = -1, heavy_child = -1;
        for (int v : adj[u])
            if (v != parent[u] && size[v] > max_size)
                max_size = size[v], heavy_child = v;
        if (heavy_child != -1)
        {
            dfs_hld(heavy_child, h);
            for (int v : adj[u])
                if (v != parent[u] && v != heavy_child)
                    dfs_hld(v, v);
        }
    };
    current_pos = 0;
    dfs_hld(1, 1);

    auto get_ranges = [&](int u, int lca_node)
    {
        vector<pair<int, int>> ranges;
        while (u != lca_node)
        {
            if (depth[head[u]] > depth[lca_node])
            {
                int start = pos[head[u]] - 1;
                int end = pos[u] - 1;
                ranges.emplace_back(start, end);
                u = parent[head[u]];
            }
            else
            {
                int k = depth[u] - depth[lca_node] - 1;
                int v = u;
                for (int i = 0; i < LOG; ++i)
                    if (k & (1 << i))
                        v = up[i][v];
                int start = pos[v] - 1;
                int end = pos[u] - 1;
                ranges.emplace_back(start, end);
                u = lca_node;
            }
        }
        return ranges;
    };

    SegmentTree st(n - 1);

    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int l = lca(x, y);
        auto ranges_x = get_ranges(x, l);
        auto ranges_y = get_ranges(y, l);
        for (auto [a, b] : ranges_x)
        {
            if (a > b)
                swap(a, b);
            st.update(a, b);
        }
        for (auto [a, b] : ranges_y)
        {
            if (a > b)
                swap(a, b);
            st.update(a, b);
        }
    }

    cout << (n - 1) - st.query() << '\n';

    return 0;
}