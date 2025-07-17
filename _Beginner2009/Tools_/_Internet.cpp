#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) (x >> i & 1)
#define ll long long
#define sz(x) (int)x.size()
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define rep2(i, l, r) for(int i = l; i >= r; i--)

const int N = 2e5 + 5;
const int mod1 = 998244353;
const int mod2 = 1e9 + 7;
const int base_row = 31;
const int base_col = 37;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) {
        return uniform_int_distribution<ll>(l, r)(rng);
}

signed main(int argc, char* argv[]) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
	
        #define Elen Elen
        #ifdef Elen     
                auto starttime = chrono::high_resolution_clock::now();
        #endif
        
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n + 3, vector<int>(m + 3, 0));
        vector<vector<int>> b(n + 3, vector<int>(m + 3, 0));
        vector<vector<char>> c(n + 3, vector<char>(m + 3, ' '));
        rep(i, 1, n) rep(j, 1, m) {
                char x; cin >> x;
                if(x != '.') a[i][j] = x - 'a' + 1;
                else a[i][j] = 0;
                b[i][j] = (a[i][j] > 0);
                c[i][j] = x;
        }
        int sz_x, sz_y; cin >> sz_x >> sz_y;

        vector<ll> pw_row1(max(n, m) + 3, 0);
        vector<ll> pw_col1(max(n, m) + 3, 0);
        vector<ll> pw_row2(max(n, m) + 3, 0);
        vector<ll> pw_col2(max(n, m) + 3, 0);
 
        pw_row1[0] = pw_col1[0] = 1;
        pw_row2[0] = pw_col2[0] = 1;
        rep(i, 1, max(n, m)) {
                pw_row1[i] = (1LL * pw_row1[i - 1] * base_row) % mod1;
                pw_col1[i] = (1LL * pw_col1[i - 1] * base_col) % mod1;
                pw_row2[i] = (1LL * pw_row2[i - 1] * base_row) % mod2;
                pw_col2[i] = (1LL * pw_col2[i - 1] * base_col) % mod2;
        }

        auto calc_hash = [&](const vector<vector<int>> &a) -> vector<vector<pair<ll, ll>>> {
                vector<vector<pair<ll, ll>>> hash(n + 3, vector<pair<ll, ll>>(m + 3, make_pair(0, 0)));
                rep(i, 1, n) rep(j, 1, m) {
                        hash[i][j].first = (1LL * hash[i - 1][j].first * base_col) % mod1
                                        + (1LL * hash[i][j - 1].first * base_row) % mod1
                                        - (((1LL * hash[i - 1][j - 1].first * base_col) % mod1) * base_row) % mod1
                                        + a[i][j];
                        hash[i][j].first = (hash[i][j].first % mod1 + mod1) % mod1;
 
                        hash[i][j].second = (1LL * hash[i - 1][j].second * base_col) % mod2
                                        + (1LL * hash[i][j - 1].second * base_row) % mod2
                                        - (((1LL * hash[i - 1][j - 1].second * base_col) % mod2) * base_row) % mod2
                                        + a[i][j];
                        hash[i][j].second = (hash[i][j].second % mod2 + mod2) % mod2;
                }
                return hash;
        };

        auto get_hash = [&](const vector<vector<pair<ll, ll>>> &hash, int x, int y, int u, int v) -> pair<ll, ll> {
                pair<ll, ll> res = {0, 0};
                res.first = hash[u][v].first 
                          - (hash[x - 1][v].first * pw_col1[u - x + 1]) % mod1
                          - (hash[u][y - 1].first * pw_row1[v - y + 1]) % mod1
                          + (((hash[x - 1][y - 1].first * pw_col1[u - x + 1]) % mod1) * pw_row1[v - y + 1]) % mod1;
                res.first = (res.first % mod1 + mod1) % mod1;
 
                res.second = hash[u][v].second 
                          - (hash[x - 1][v].second * pw_col2[u - x + 1]) % mod2
                          - (hash[u][y - 1].second * pw_row2[v - y + 1]) % mod2
                          + (((hash[x - 1][y - 1].second * pw_col2[u - x + 1]) % mod2) * pw_row2[v - y + 1]) % mod2;
                res.second = (res.second % mod2 + mod2) % mod2;
                return res;
        };

        // rep(i, 1, n) {
        //         rep(j, 1, m) {
        //                 cout << b[i][j] << " ";
        //         }
        //         cout << "\n";
        // }

        vector<vector<pair<ll, ll>>> hash = calc_hash(a);
        vector<pair<ll, ll>> hash_list;
        rep(i, 1, n - sz_x + 1) rep(j, 1, m - sz_y + 1) {
                auto x = get_hash(hash, i, j, i + sz_x - 1, j + sz_y - 1);
                hash_list.push_back(x);
        }

        sort(hash_list.begin(), hash_list.end());
        pair<int, pair<ll, ll>> max_value = {0, {0, 0}};
        for(int i = 0, j = 0; i < hash_list.size();) {
                while(j < hash_list.size() && hash_list[i] == hash_list[j]) j++;
                max_value = max(max_value, make_pair(j - i, hash_list[i]));
                i = j;
        }

        vector<pair<int, int>> positions;
        rep(i, 1, n - sz_x + 1) rep(j, 1, m - sz_y + 1) {
                auto x = get_hash(hash, i, j, i + sz_x - 1, j + sz_y - 1);
                if(x == max_value.second) positions.push_back({i, j});
        }

        assert(!positions.empty());
        cout << sz_x << " " << sz_y << "\n";
        rep(i, positions[0].first, positions[0].first + sz_x - 1) {
                rep(j, positions[0].second, positions[0].second + sz_y - 1) {
                        cout << c[i][j];
                }
                cout << "\n";
        }
        cout << positions.size() << "\n";
        for(auto [x, y] : positions) cout << x << " " << y << "\n";

        #ifdef Elen
                auto endtime = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(endtime - starttime).count();
                cerr << "\nRuntime: " << duration << "ms\n";
        #endif

        return 0 ^ 0;
}
