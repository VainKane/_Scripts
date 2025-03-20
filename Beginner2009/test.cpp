#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> log_table;
vector<vector<ll>> st;
vector<ll> p;
int n;

void build_sparse_table() {
    log_table.resize(n + 1);
    log_table[1] = 0;
    for (int i = 2; i <= n; ++i) {
        log_table[i] = log_table[i / 2] + 1;
    }
    int max_k = log_table[n] + 1;
    st.resize(max_k, vector<ll>(n + 1));
    for (int i = 1; i <= n; ++i) {
        st[0][i] = p[i];
    }
    for (int k = 1; (1 << k) <= n; ++k) {
        for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }
}

ll get_min(int l, int r) {
    int len = r - l + 1;
    int k = log_table[len];
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

int find_first(int l, int r, ll t) {
    if (l > r) return -1;
    if (get_min(l, r) > t) return -1;
    int low = l, high = r;
    while (low < high) {
        int mid = (low + high) / 2;
        if (get_min(low, mid) <= t) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return (p[low] <= t) ? low : -1;
}

int find_last(int l, int r, ll t) {
    if (l > r) return -1;
    if (get_min(l, r) > t) return -1;
    int low = l, high = r;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (get_min(mid, high) <= t) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return (p[low] <= t) ? low : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    p.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    build_sparse_table();

    while (m--) {
        ll t;
        int l, r;
        cin >> t >> l >> r;

        if (t == 0) {
            cout << 0 << '\n';
            continue;
        }

        if (l <= r) {
            int current_l = l;
            int current_r = r;
            while (current_l <= current_r && t > 0) {
                int pos = find_first(current_l, current_r, t);
                if (pos == -1) break;
                ll price = p[pos];
                t %= price;
                current_l = pos + 1;
            }
        } else {
            int current_l = l;
            int current_r = r;
            while (current_l >= current_r && t > 0) {
                int pos = find_last(current_r, current_l, t);
                if (pos == -1) break;
                ll price = p[pos];
                t %= price;
                current_l = pos - 1;
            }
        }

        cout << t << '\n';
    }

    return 0;
}