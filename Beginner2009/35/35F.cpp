#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int q;

int n;
int m;

vector<int> adj[N];
set<int> dagAdj[N];
stack<int> st;

int inDeg[N];
int outDeg[N];

int low[N];
int id[N];
int in[N];

int cnt = 0;

void Tarjan(int u) // khu chu ki
{
    low[u] = id[u] = ++cnt;
    st.push(u);
    
    for (auto v : adj[u])
    {
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == id[u])
    {
        int v = 0;
        while (v != u)
        {
            v = st.top();
            st.pop();

            id[v] = n + 1;
            in[v] = u;
        }
    }
}

void Reset()
{
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++) dagAdj[i].clear();
    memset(inDeg, 0, sizeof inDeg);
    memset(outDeg, 0, sizeof outDeg);
    memset(id, 0, sizeof id);
    cnt = 0;
}

bool Check() // co ton tai duong di Euler ko?
{
    int s = 0;
    int t = 0;

    for (int u = 1; u <= n; u++)
    {
        int d = outDeg[u] - inDeg[u];
        if (d == 1) s++;
        else if (d == -1) t++;
        else if (d) return false;
    }

    return (s * t == 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> q;

    while (q--)
    {
        cin >> n >> m;

        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
        }

        for (int i = 1; i <= n; i++) if (!id[i]) Tarjan(i);

        for (int u = 1; u <= n; u++)
        {
            for (auto v : adj[u])
            {
                if (in[u] == in[v]) continue;
                if (dagAdj[in[u]].count(in[v])) continue;
                
                dagAdj[in[u]].insert(in[v]);
                inDeg[in[v]]++;
                outDeg[in[u]]++;
            }
        }

        if (Check()) cout << "YES\n";
        else cout << "NO\n";
        
        Reset();
    }

    return 0;
}   