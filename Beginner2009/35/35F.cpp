#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int q;

int n;
int m;

vector<int> adj[N];
vector<int> adj2[N];

int inDeg[N];
int outDeg[N];
bool visisted[N];

void Reset()
{
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++) adj2[i].clear();
    memset(inDeg, 0, sizeof inDeg);
    memset(outDeg, 0, sizeof outDeg);
    memset(visisted, 1, sizeof visisted);
}

void DFS(int u)
{
    visisted[u] = true;
    for (auto v : adj2[u])
    {
        if (!visisted[v]) DFS(v);
    }
}

bool Check() // kiem tra duong di Euler
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
            adj2[u].push_back(v);
            adj2[v].push_back(u);

            inDeg[v]++;
            outDeg[u]++;
        }

        int s = 0;
        bool cc = true;

        for (int u = 1; u <= n; u++)
        {
            if (inDeg[u] + outDeg[u] > 0)
            {
                s = u;
                break;
            }
        }

        if (s)
        {
            DFS(s);
            for (int u = 1; u <= n; u++)
            {
                if (inDeg[u] + outDeg[u] > 0 && !visisted[u])
                {
                    cc = false;
                }
            }
        }
       
        if (!cc) 
        {
            cout << "NO\n";
            continue;
        }

        if (Check()) cout << "YES\n";
        else cout << "NO\n";
        
        Reset();
    }

    return 0;
}   