//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "arithmetic"

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
pii T[maxn*4];
int id[maxn], a[maxn];

void Init(int node, int l, int r) //tree[node]: min(l,r)
{
    T[node] = mp(1,0);
    if (l == r){
        id[r] = node;
        return;
    }
    int mid = (l+r)/2;
    Init(node*2, l, mid);
    Init(node*2+1, mid+1, r);
}

void Push(pii Cha, pii &Con){
    Con.F = (1ll*Con.F * Cha.F) % MOD;
    Con.S = (1ll*Con.S * Cha.F + Cha.S) % MOD;
}

void Update(int node, int l, int r, int u, int v, int A, int B)
{
    // khong giao
    if (u > r || v < l) return ;
    // [u,v] chua [l,r]
    if (l>=u && r <= v) {
        if (A == 1) T[node].S = (T[node].S + B) % MOD;
            else {
                int p = (1ll*T[node].F * A) % MOD;
                int q = (1ll*T[node].S * A) % MOD;
                T[node] = mp(p,q);
            }
        return;
    };
    Push(T[node], T[node *2]);
    Push(T[node], T[node *2+1]);
    T[node] = mp(1,0);
    int mid = (l+r)/2;
    Update(node*2, l, mid, u, v, A, B);
    Update(node*2+1, mid+1, r, u, v, A, B);
}

int Get(int pos)
{
    int node = id[pos];
    long long res = a[pos];
    //cout << pos << " ";

    while (node){

        res = (res * T[node].F + T[node].S) % MOD;
        node /= 2;
        //cout << " " << node << " " << res << endl;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    // freopen(Task".inp", "r", stdin);
    // freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Init(1,1,n);
    int m;
    cin >> m;
    while (m--){
        char type;
        int u, v, d, p;
        cin >> type;
        if (type == '?'){
            cin >> p;
            cout << Get(p) << "\n";
        } else {
            cin >> u >> v >> d;
            if (type == '+') Update(1,1,n,u,v,1,d);
                else Update(1,1,n,u,v,d,0);
        }
    }
    return 0;
}

