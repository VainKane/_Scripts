//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "LCA"
#define maxn 100005
#define maxh 20

#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m, root;
int par[maxn][maxh];
int h[maxn];
vector <int> a[maxn];

void nhap()
{
    cin >> n >> root >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
}

void DFS(int u) // h[u], par[u][i]
{
    for (int v : a[u])
        if (v != par[u][0]){
            h[v] = h[u] + 1;
            par[v][0] = u;
            for (int i = 1; i <= 17; i++)
                par[v][i] = par[par[v][i-1]][i-1];
            DFS(v);
        }
}

int lca(int u, int v) //O(logN)
{
    // Buoc 1: Đưa 2 đỉnh về cùng độ sâu
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v];
    for (int i = 0; i <= 17; i++)
        if ((delta >> i) & 1) u = par[u][i];
    // Đã có u và v cùng độ sâu
    if (u == v) return u;//v
    // Nhảy lên cha chung gần nhất
    for (int i = 17; i >= 0; i--)
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];// par[v][0]
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    // freopen(Task".inp", "r", stdin);
    // freopen(Task".out", "w", stdout);
    nhap();
    h[root] = 0;
    DFS(root);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u,v) << "\n";
    }
    return 0;
}
