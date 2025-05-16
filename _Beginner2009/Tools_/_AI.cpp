#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int a[MAXN], freq[MAXN];
unordered_map<int, int> cnt;
int answer[MAXN];
int current_xor = 0;

struct Query {
    int l, r, id;
};

int block_size;

bool cmp(Query a, Query b) {
    if (a.l / block_size != b.l / block_size)
        return a.l < b.l;
    return ((a.l / block_size) & 1) ? (a.r < b.r) : (a.r > b.r);
}

void add(int x) {
    cnt[x]++;
    if (cnt[x] % 2 == 0)
        current_xor ^= x;
    else if (cnt[x] > 1)
        current_xor ^= x;
}

void remove(int x) {
    if (cnt[x] % 2 == 0)
        current_xor ^= x;
    else if (cnt[x] > 1)
        current_xor ^= x;
    cnt[x]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, q;
    cin >> t >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> q;

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].id = i;
    }

    block_size = sqrt(n);
    sort(queries.begin(), queries.end(), cmp);

    int L = 0, R = -1;
    for (auto query : queries) {
        while (R < query.r) add(a[++R]);
        while (L > query.l) add(a[--L]);
        while (R > query.r) remove(a[R--]);
        while (L < query.l) remove(a[L++]);
        answer[query.id] = current_xor;
    }

    for (int i = 0; i < q; ++i) cout << answer[i] << ' ';
}
