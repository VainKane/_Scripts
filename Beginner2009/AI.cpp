//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "mintree"
#define maxn 30005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m;

vector <pii> a[maxn];
int d[maxn];//khoang cach ngan nhat tu dinh u -> cay da co
int connect[maxn];
long long ans = 0;
bool used[maxn];

void Push(int u)
{
	used[u] = 1;
	for (int i = 0; i < a[u].size(); i++){
		int v = a[u][i].F;
		int w = a[u][i].S;
		if (used[v]==0 && d[v] > w){
			d[v] = w; // cập nhật khoảng cách v tới MST
			connect[v] = u;
		}
	}
}

void Prim(){
    fill(d, d+n+1, 1e9);
	// d[u] là khoảng cách từ u tới MST hiện có
    reset(used); 	
	Push(1);
    d[1] = 0;	
	int socanh = 0;
    while (1){
		// tìm đỉnh có khoảng cách tới cây khung nhỏ nhất;
        int u = 0;
        for (int i = 1; i <= n; i++)
            if (used[i] == 0 && d[i] < d[u]) u = i;
		
        if (u == 0) break; // khong con dinh tu do noi duoc
        socanh++;        
        ans += d[u];
		// đưa đỉnh u vào cây khung
		Push(u);        
    }
    if (socanh != n-1){
        cout << "-1";
        return;
    }
    cout << ans << endl;
    for (int i = 2; i <= n; i++)
        cout << i << " " << connect[i] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
    // freopen(Task".inp", "r", stdin);
    // freopen(Task".out", "w", stdout);
    cin >> n >> m;
    for (int u, v, w, i = 1; i <= m; i++){
        cin >> u >> v >> w;
        a[u].PB(mp(v,w));
        a[v].PB(mp(u,w));
    }

    Prim();
    return 0;
}

