#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) (x >> i & 1)
#define ll long long
#define sz(x) (int)x.size()
#define rep(i, l, r) for (int i = (l), _r = (r); i <= _r; i++)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) {
        return uniform_int_distribution<ll>(l, r)(rng);
}

void maximize(ll &x, ll y) {
        x = max(x, y);
}

int n, k, L, R, C;
int a[5005];
ll dp[5005][5005];
deque<pair<ll, ll>> q[5005];
int idx[5005];

signed main(int argc, char* argv[]) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
	
        #define Elen Elen
        #ifdef Elen     
                auto starttime = chrono::high_resolution_clock::now();
        #endif
        
        cin >> n >> k;
        cin >> L >> R;
        cin >> C;        
        
        rep(i, 1, n) cin >> a[i];

        memset(dp, -0x3f, sizeof dp);
        dp[0][0] = 0;
        rep(i, 1, n) {
                rep(j, 0, min(i - 1, k - 1)) {
                        while(idx[j] < i && a[i] - a[idx[j]] >= L) {
                                int ii = idx[j];
                                pair<ll, ll> x = {ii, dp[ii][j] - 1LL * j * (k - j) * a[ii]};
                                while(!q[j].empty() && x.second > q[j].back().second) {
                                        q[j].pop_back();
                                }
                                q[j].push_back(x);
                                idx[j]++;
                        }
                }
                rep(j, 1, min(i, k)) {
                        while(!q[j - 1].empty() && a[i] - a[q[j - 1].front().first] > R) {
                                q[j - 1].pop_front();
                        }
                        if(!q[j - 1].empty()) {
                                maximize(dp[i][j], q[j - 1].front().second + 1LL * (j - 1) * (k - j + 1) * a[i]);
                        }
                }
        }

        ll res = 0;
        rep(i, 1, n) {
                if(C - a[i] < L || C - a[i] > R) continue;
                res = max(res, dp[i][k]);
        }

        cout << 2 * res;
        
        #ifdef Elen
                auto endtime = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(endtime - starttime).count();
                cerr << "\nRuntime: " << duration << "ms\n";
        #endif

        return 0 ^ 0;
}
