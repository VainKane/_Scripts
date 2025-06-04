#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int,int>
#define lll pair<long long,long long>
#define iii pair<int,pair<int,int>>
#define ill pair<int,long long>
#define lli pair<long long,int>
#define fi first
#define se second
#define m_p make_pair
const long double pi = 3.141592653589793238462643383279;
const int N = 1e5+5;
const ll M = 1e9+7;
//const int M = 998244353;
using namespace std;
void file(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    #define task "graph"
    if (fopen(task".inp", "r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
vector< ii > ans;
int node, d, k;

void make(int x, int y){
    int nodel = ++node;
    int cur = nodel;
    for (int i = 1;i <= d - 2 ;++i){
        int tmp = ++node;
        ans.push_back({cur, tmp});
        cur = tmp;
    }
    int noder = node;
    for (int i = 1;i <= x; ++i){
        ans.push_back({nodel, ++node});
    }
    for (int i = 1; i <= y; ++i){
        ans.push_back({noder, ++node});
    }

}


void sol1(){
    while ( k > 0){
        int t = 1;
        while (t * (t + 1) / 2 <= k) ++t;
        make(1, t - 1);
        k -= t * (t - 1) / 2;
    }
    cout << node << ' ' << ans.size() << "\n";
    for (auto x: ans)
        cout << x.fi << ' '  << x.se << "\n";
}
void sol2(){
    while ( k > 0){
        int t = trunc(sqrt(k));
        if (t * t > k) --t;
        make(t, t);
        k -= t*t;
    }
    cout << node << ' ' << ans.size() << "\n";
    for (auto x: ans)
        cout << x.fi << ' '  << x.se << "\n";
}

int main(){
    file();
    cin >> d >> k;
    node = 0;
    if (d == 2) sol1();
    if (d > 2) sol2();
    return 0;
}
